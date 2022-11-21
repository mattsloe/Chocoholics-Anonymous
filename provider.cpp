#include "provider.h"
#include "provider.h"
#include "provider.h"
#include "provider.h"
// Ashton Sawyer 11/1
#include "provider.h"

// *********
// PROVIDER
// *********

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
Provider::Provider(std::string _name, unsigned int num, const Address & _address) {
	init_provider(_name, num, _address);
}

//default destructor: deletes list of services
Provider::~Provider() {
	delete avail_services;
}

void Provider::init_provider(std::string _name, unsigned int num, const Address & to_copy) {
	name = _name;
	pid = num;
	address.copy_address(to_copy);
}

void Provider::print_provider() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Provider Number: " << pid << std::endl;
	address.print_address();
}

unsigned int Provider::get_pid() {
	return pid;
}

std::string Provider::to_file() {
	return std::string();
}

bool Provider::operator==(Provider & comp) {
	return (pid == comp.pid);
}

int Provider::add_service() {
	return 0;
}

int Provider::remove_service() {
	return 0;
}

std::string Provider::validate_sid() {
	return std::string();
}

// **********
// ADDRESS
// **********

void Address::init_address() {
	std::cout << "Street: ";
	std::getline(std::cin, state);
	

	std::cout << "City: ";
	std::cin >> city;
	std::cin.ignore(100, '\n');

	std::cout << "State Initials: ";
	std::cin >> state;
	std::cin.ignore(100, '\n');

	std::cout << "Zip: ";
	std::cin >> zip;
	std::cin.ignore(100, '\n');
}

Address::Address(std::string street, std::string city, std::string state, std::string zip)
{
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