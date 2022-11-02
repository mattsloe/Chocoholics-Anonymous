#include "provider.h"

// *********
// PROVIDER
// *********

//default initializer
Provider::Provider() {
	head = NULL;
}

//default destructor: deletes list of services
Provider::~Provider() {
	delete_list(head);
}

void Provider::delete_list(node * head) {
	return;
}

void Provider::init_provider(std::string _name, int num, Address to_copy) {
	name = _name;
	prov_num = num;
	address.copy_address(to_copy);
}

void Provider::print_provider() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Provider Number: " << prov_num << std::endl;
	address.print_address();
	print_list(head);
}

void Provider::print_list(node* head) {
	if (!head) {
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