// Ashton Sawyer 11/1
#include "Provider.hpp"

// *********
// PROVIDER
// *********

/* **Provider Interface** */

//default constructor
Provider::Provider() {
	init_list();
}

Provider::Provider(std::string _name, std::string num, const Address & _address) {
	name = _name;
	pid = num;
	address.copy_address(_address);
	init_list();
}

//json constructor
Provider::Provider(nlohmann::json j) {
	std::string street, city, state, zip;

	name = j.value("name", "not found");
	pid = j.value("pid", "not found");

	street = j.value("street", "not found");
	city = j.value("city", "not found");
	state = j.value("state", "not found");
	zip = j.value("zip", "not found");
	address.init_address(street, city, state, zip);

	//init_list_from_file()
}

//default destructor: deletes list of services
Provider::~Provider() {
	delete_list();
}

//ask for user input + error check
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

std::string Provider::get_pid() {
	return pid;
}

bool Provider::operator==(const Provider& comp) {
	return (pid == comp.pid);
}

bool Provider::operator<(const Provider& comp) {
	return (pid < comp.pid);
}

std::ostream& operator<<(std::ostream& out, const Provider& p) {
	out << p.to_string();
	return out;
}

int Provider::edit_provider(std::string _name) {
	name = _name;
	return 0;
}

int Provider::edit_provider(std::string _pid) {
	pid = _pid;
	return 0;
}

int Provider::edit_provider(const Address& _address) {
	address.copy_address(_address);
	return 0;
}

int Provider::edit_provider(std::string _name, std::string _pid) {
	name = _name;
	pid = _pid;
	return 0;
}

int Provider::edit_provider(std::string _name, const Address & _address) {
	name = _name;
	address.copy_address(_address);
	return 0;
}

int Provider::edit_provider(std::string _pid, const Address & _address) {
	pid = _pid;
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
	return address.copy_address(_address);
}

/* **File Functions** */

std::string Provider::to_file() {
	return std::string();
}

void Provider::load_file() {

}

// outputs .txt file of provider info + provided services info
void Provider::run_report() {

}

std::string Provider::run_manager_report() {
	
}

// returns string for database generated report
std::string run_manager_report() {
	return std::string();
}

/* **Service List Functions** */

int Provider::add_service(Service_Record * to_add) {
	//incr_total_fee(service_fee)
	head->num_services_provided += 1;
	
	if (!tail) {
		tail = new node;
		tail->service = to_add;
		tail->next = NULL;
		return 0;
	}
	tail->next = new node;
	tail = tail->next;
	tail->service = to_add;
	tail->next = NULL;
	return 0;
}

int Provider::remove_service(Service_Record * to_remove) {
	// empty list
	if (!tail)
		return 1;

	node * curr = head->next;
	while (curr->next) {
		// need == 
		if (curr->next->service == *to_remove) {
			node * tmp = curr->next;
			curr->next = tmp->next;
			delete tmp;
			return 0;
		}
		curr = curr->next;
	}
	return 0;
}

int Provider::clear_services() {
	head->total_cost = 0;
	head->num_services_provided = 0;


}

void Provider::service_to_file() {

}

void Provider::service_report() {

}

void Provider::delete_list() {

}

void Provider::init_list() {
	head = new node_head;
	head->num_services_provided = 0;
	head->total_cost = 0;
	head->next = NULL;
	tail = NULL;
}

// **********
// ADDRESS
// **********

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
		flag = set_zip(tmp)
	}

}

int Address::init_address(std::string _street, std::string _city, std::string _state, std::string _zip) {
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

void Address::print_address() {
	std::cout << street << std::endl;
	std::cout << city << "," << state << " " << zip << std::endl;
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
	if (_zip.length != 5 || !std::all_of(_zip.begin(), _zip.end(), ::isdigit)) {
		std::cout << "Invalid zipcode!" << std::endl;
		return 1;
	}
	zip = _zip;
	return 0;
}