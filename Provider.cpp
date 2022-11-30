// Ashton Sawyer 11/1
#include "Provider.hpp"

// *********
// PROVIDER
// *********

/* **Provider Interface** */

//default constructor
Provider::Provider() {
	num_services_provided = 0;
	total_cost = 0.0;
}

Provider::Provider(std::string _name, std::string num, const Address & _address) {
	name = _name;
	pid = num;
	address.copy_address(_address);
	num_services_provided = 0;
	total_cost = 0.0;
}

Provider::Provider(const Provider & to_copy) {
	copy(to_copy);
}

//json constructor
Provider::Provider(nlohmann::json j, Provider_Directory & d) {
	load_file(j, d);
}

Provider::~Provider() = default;

//ask for user input + error check
//doesn't add services
void Provider::init_provider() {
	std::string tmp;
	int flag = 1;

	while (flag) {
		std::cout << "Name: ";
		std::getline(std::cin, tmp);
		flag = set_name(tmp);
	}
	flag = 1;

	while (flag) {
		std::cout << "PID: ";
		std::cin >> tmp;
		std::cin.ignore(100, '\n');
		flag = set_pid(tmp);
	}
	flag = 1;
	
	address.init_address();
}

void Provider::copy(const Provider & to_copy) {
	name = to_copy.name;
	pid = to_copy.pid;
	address.copy_address(to_copy.address);
	num_services_provided = to_copy.num_services_provided;
	total_cost = to_copy.total_cost;
	service_list = to_copy.service_list;
}

std::string Provider::get_pid() {
	return pid;
}

bool Provider::operator==(const Provider& comp) {
	return (pid == comp.pid);
}

std::ostream& operator<<(std::ostream& out, Provider & p) {
	out << p.to_string();
	return out;
}

int Provider::edit_provider(std::string s) {
	if (std::all_of(s.begin(), s.end(), ::isdigit))
		pid = s;
	else
		name = s;
	return 0;
}

int Provider::edit_provider(const Address & _address) {
	address.copy_address(_address);
	return 0;
}

int Provider::edit_provider(std::string _name, std::string _pid) {
	name = _name;
	pid = _pid;
	return 0;
}

int Provider::edit_provider(std::string s, const Address & _address) {
	if (std::all_of(s.begin(), s.end(), ::isdigit))
		pid = s;
	else
		name = s;
	address.copy_address(_address);
	return 0;
}

int Provider::edit_provider(std::string _name, std::string _pid, const Address & _address) {
	name = _name;
	pid = _pid;
	address.copy_address(_address);
	return 0;
}

// max len = 25
int Provider::set_name(std::string _name) {
	name = _name.substr(0,25);
	return 0;
}

// len = 9 & only digits
int Provider::set_pid(std::string _pid) {
	if (_pid.length() != 9 || !std::all_of(_pid.begin(), _pid.end(), ::isdigit)) {
		std::cout << "Invalid PID!" << std::endl;
		return 1;
	}
	pid = _pid;
	return 0;
}

int Provider::set_address(const Address & _address) {
	address.copy_address(_address);
	return 0;
}

/* **File Functions** */

//Format:
//<Name> - <PID>
//<Street>
//<City>, <ST> <zip>
std::string Provider::to_string() {
	std::string out;
	out += name + " - " + pid + "\n";
	out += address.street + "\n";
	out += address.city + ", " + address.state + " " + address.zip + "\n";
	return out;
}

std::string Provider::to_file() {
	using json = nlohmann::json;
	std::string out;

	json j = {
		{"name", name},
		{"pid", pid},
		{"street", address.street},
		{"city", address.city},
		{"state", address.state},
		{"zip", address.zip}
	};

	auto services = json::array();
	json temp;
	for (Service_Record r : service_list) {
		temp = json::parse(r.to_string_exp());
		services.push_back(temp);
	}
	j["serviceList"] = services; //append services

	out = j.dump(2);
	return out;
}

void Provider::load_file(nlohmann::json j, Provider_Directory & d) {
	std::string street, city, state, zip, service_array;

	name = j.value("name", "not found");
	pid = j.value("pid", "not found");

	street = j.value("street", "not found");
	city = j.value("city", "not found");
	state = j.value("state", "not found");
	zip = j.value("zip", "not found");
	address.init_address(street, city, state, zip);

	for (auto elem : j["serviceList"]) {
		Service_Record to_add(elem);
		service_list.push_back(to_add);

		num_services_provided += 1;
		total_cost += d.get_fee_d(to_add.get_sID());
	}
}

// outputs .txt file of provider info + provided services info
void Provider::run_report(Provider_Directory & d) {
	std::string file_name = name;
	size_t pos = name.find(' ');
	file_name.replace(pos, 1, 1, '_');
	file_name += ".txt";

	std::ofstream output_file(file_name);
	if (!output_file.is_open()) {
		std::cout << "Error: could not open file" << std::endl;
		std::cout << "Exiting..." << std::endl;
		return;
	}

	output_file << to_string();
	output_file << "\n";
	output_file << service_to_string(d);
	output_file.close();
	return;
}

// returns string for database generated report
//Format: 
//<Name> - <PID>
//Number of Consults: <#>    Total Fee: <$>
std::string Provider::run_manager_report() {
	std::string out;
	
	out += name + " - " + pid + "\n";
	out += "Number of Consults: " + std::to_string(num_services_provided) + "\t";
	out += "Total Fee: $" + std::to_string(total_cost) + "\n";

	return out;
}

/* **Service List Functions** */

int Provider::add_service(Service_Record & to_add, Provider_Directory & d) {
	service_list.push_back(to_add);

	num_services_provided += 1;
	total_cost += d.get_fee_d(to_add.get_sID());

	return 0;
}

// for resetting week
int Provider::clear_services() {
	service_list.clear();
	total_cost = 0.0;
	num_services_provided = 0;
	return 0;
}

// for report
//Format:
// <Service 1 info>
// 
// <Service 2 info>
// 
// ...
// 
// Total Services: <#>    Total Fee: <$>
std::string Provider::service_to_string(Provider_Directory & d) {
	std::string out;

	for (int i = 0; i < service_list.size(); ++i) {
			out += service_list[i].to_string_provider();
			out += "Service Fee: " + d.get_fee(service_list[i].get_sID()) + "\n";
			out += "\n";
	}
	out += "Total Services: " + std::to_string(num_services_provided) + "\t";
	out += "Total Fee: " + std::to_string(total_cost) + "\n";

	return out;
}

// **********
// ADDRESS
// **********

Address::Address() = default;

Address::Address(std::string street, std::string city, std::string state, std::string zip) {
	init_address(street, city, state, zip);
}

void Address::init_address() {
	std::string tmp;
	int flag = 1;

	while (flag) {
		std::cout << "Street: ";
		std::getline(std::cin, tmp);
		flag = set_street(tmp);
	}
	flag = 1;

	while (flag) {
		std::cout << "City: ";
		std::cin >> tmp;
		std::cin.ignore(100, '\n');
		flag = set_city(tmp);
	}
	flag = 1;

	while (flag) {
		std::cout << "State Initials: ";
		std::cin >> tmp;
		std::cin.ignore(100, '\n');
		flag = set_state(tmp);
	}
	flag = 1;

	while (flag) {
		std::cout << "Zip: ";
		std::cin >> tmp;
		std::cin.ignore(100, '\n');
		flag = set_zip(tmp);
	}

}

void Address::init_address(std::string _street, std::string _city, std::string _state, std::string _zip) {
	street = _street;
	city = _city;
	state = _state;
	zip = _zip;
}

//copy from source into current obj
void Address::copy_address(const Address & source) {
	street = source.street;
	city = source.city;
	state = source.state;
	zip = source.zip;
}

int Address::set_street(std::string _street) {
	street = _street.substr(0, 25);
	return 0;
}

// max len = 14
int Address::set_city(std::string _city) {
	city = _city.substr(0, 14);
	return 0;
}

int Address::set_state(std::string _state) {
	if (_state.length() != 2) {
		std::cout << "Invalid state!" << std::endl;
		return 1;
	}
	state = _state;
	return 0;
}

int Address::set_zip(std::string _zip) {
	if (_zip.length() != 5 || !std::all_of(_zip.begin(), _zip.end(), ::isdigit)) {
		std::cout << "Invalid zipcode!" << std::endl;
		return 1;
	}
	zip = _zip;
	return 0;
}
