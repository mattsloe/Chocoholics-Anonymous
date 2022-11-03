// Ashton Sawyer 11/1
#include "provider.h"

// *********
// PROVIDER
// *********

//default constructor: ask for input
Provider::Provider() {
	std::cout << "What is the provider's name: ";
	std::cin >> name;
	std::cin.ignore(100, '\n');

	std::cout << "What is their provider number: ";
	std::cin >> prov_num;
	std::cin.ignore(100, '\n');

	std::cout << "Please enter their address:\n";
	address.init_address();

	head = tail = new node;
	head->next = NULL;
	head->total_cost = 0;
	head->total_services = 0;
}

//constructor: provide input
Provider::Provider(std::string _name, std::string num, const Address & _address) {
	init_provider(_name, num, _address);

	head = tail = new node;
	head->total_cost = 0;
	head->total_services = 0;
	head->next = NULL;
}

//copy constructor
Provider::Provider(const Provider& to_copy) {

}

//default destructor: deletes list of services
Provider::~Provider() {
	delete_list(head);
}

void Provider::delete_list(node * head) {
	if (!head)
		return;

	node * curr = head;
	while (curr) {
		curr = curr->next;
		delete head;
		head = curr;
	}
}

void Provider::init_provider(std::string _name, std::string num, const Address & to_copy) {
	name = _name;
	prov_num = num;
	address.copy_address(to_copy);
}

void Provider::print_provider() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Provider Number: " << prov_num << std::endl;
	address.print_address();
	print_list(head);
	std::cout << std::endl;
}

void Provider::print_list(node* head) {
	if (!head->next) {
		std::cout << "No services found for this provider" << std::endl;
		return;
	}

	/*
	node * curr = head;
	while (curr) {
		curr->service->print_service();
		curr = curr->next;
	} */
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

//copy from source into current obj
void Address::copy_address(const Address& source) {
	street = source.street;
	city = source.city;
	state = source.state;
	zip = source.zip;
}

void Address::print_address() {
	std::cout << street << std::endl;
	std::cout << city << "," << state << " " << zip << std::endl;
}