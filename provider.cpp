// Ashton Sawyer 11/1
#include "provider.h"

// *********
// PROVIDER
// *********

/* **Provider Interface** */

//default constructor: ask for input
Provider::Provider() {
	std::string _name;
	std::string _pid;
	Address _address;

	std::cout << "What is the provider's name: ";
	std::cin >> _name;
	std::cin.ignore(100, '\n');

	std::cout << "What is their provider number: ";
	std::cin >> _pid;
	std::cin.ignore(100, '\n');

	std::cout << "Please enter their address:\n";
	_address.init_address();

	init_provider(_name, _pid, _address);

}

//constructor: provide input
Provider::Provider(std::string _name, std::string num, const Address & _address) {
	init_provider(_name, num, _address);
}

//default destructor: deletes list of services
Provider::~Provider() {
	delete_list();
}

void Provider::init_provider(std::string _name, std::string num, const Address & to_copy) {
	name = _name;
	pid = num;
	address.copy_address(to_copy);
}

void Provider::print_provider() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Provider Number: " << pid << std::endl;
	address.print_address();
}

std::string Provider::get_pid() {
	return pid;
}

bool Provider::operator==(Provider& comp) {
	return (pid == comp.pid);
}

int Provider::edit_provider(std::string _name) {
	int ret = 0;
	ret = set_name(_name);
}

int Provider::edit_provider(std::string _pid) {
	int ret = 0;
	ret = set_pid(_pid);
}

int Provider::edit_provider(const Address& _address) {
	int ret = 0;
	ret = set_address(_address);
}

int Provider::edit_provider(std::string _name, std::string _pid) {
	int ret = 0;
	ret = set_name(_name);
	ret = set_pid(_pid);
}

int Provider::edit_provider(std::string _name, const Address & _address) {
	int ret = 0;
	ret = set_name(_name);
	ret = set_address(_address);
}

int Provider::edit_provider(std::string _pid, const Address & _address) {
	int ret = 0;
	ret = set_pid(_pid);
	ret = set_address(_address);
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

// returns string for database generated report
std::string run_manager_report() {
	return std::string();
}

/* **Service List Functions** */

int Provider::add_service() {
	return 0;
}

int Provider::remove_service() {
	return 0;
}

void Provider::service_to_file() {

}

void Provider::service_report() {

}

void Provider::delete_list() {

}

// **********
// ADDRESS
// **********

void Address::init_address() {
	std::string _state, _city, _state, _zip;
	std::cout << "Street: ";
	std::getline(std::cin, _state);
	

	std::cout << "City: ";
	std::cin >> _city;
	std::cin.ignore(100, '\n');

	std::cout << "State Initials: ";
	std::cin >> _state;
	std::cin.ignore(100, '\n');

	std::cout << "Zip: ";
	std::cin >> _zip;
	std::cin.ignore(100, '\n');

	init_address(_state, _city, _state, _zip);
}

Address::Address(std::string street, std::string city, std::string state, std::string zip) {
	init_address(street, city, state, zip);
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