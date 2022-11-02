// Ashton Sawyer 11/1
#include <iostream>
#include <cstdlib>
#include <cstring>


struct node {
	//Service * service;
	node * next;
};

struct Address {
	std::string street;
	std::string city;
	std::string state;    // initials
	int zip;

	void copy_address(const Address & source);
	void print_address();
};

class Provider {
	public:
		Provider();
		~Provider();
		void init_provider(std::string _name, int _prov_num, Address _address);
		void print_provider();

	protected:
		std::string name;
		int prov_num;     // 9 digits
		Address address; 
		node * head;      // linked list of provided services

		void delete_list(node *);  // delete linked list
		void print_list(node*);

};