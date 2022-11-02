// Ashton Sawyer 11/1
#include <iostream>
#include <cstdlib>
#include <cstring>

struct node {
	//Service * service;
	node* next;
};

struct Address {
	std::string street;
	std::string city;
	char state[2];    // initials
	int zip;
};

class Provider {
	public:
		Provider();
		~Provider();

	protected:
		std::string name;
		int prov_num;     // 9 digits
		Address address; 
		node* head;       // linked list of provided services

};