// Ashton Sawyer 11/1
#include <iostream>
#include <cstdlib>
#include <cstring>


struct node {
	//Service * service;
	node * next;

	// for first node in list
	int total_services;
	int total_cost;
};

struct Address {
	std::string street;
	std::string city;
	std::string state;    // initials
	std::string zip;

	void init_address();  // asks for input
	void copy_address(const Address & source);
	void print_address();
};

class Provider {
	public:
		Provider();
		Provider(std::string _name, std::string _pid, const Address & _address);
		Provider(const Provider & to_copy);
		~Provider();
		void init_provider(std::string _name, std::string _pid, const Address & _address);
		void print_provider();  // mostly for testing
		bool operator==(const Provider & provider, int _pid);

	protected:
		std::string name;
		std::string pid;     // provider ID; 9 digits
		Address address; 
		node * head;      // linked list of provided services
		node * tail;      // linked list of provided services

		void delete_list(node *);  // delete linked list
		void print_list(node *);

};