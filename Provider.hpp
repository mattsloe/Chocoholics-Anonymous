// Ashton Sawyer 11/1

#ifndef PROVIDER_H
# define PROVIDER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Service_Record.hpp"

struct node {
	Service_Record * service;
	node * next;
};

struct node_head {
	int numServicesProvided;
	int totalCost;
	node * next;
};

struct Address {
	std::string street;   // 25 char
	std::string city;     // 14 char
	std::string state;    // initials
	std::string zip;

	/* Interface */
	Address();			  // asks for input
	Address(std::string street, std::string city, std::string state, std::string zip);
	// Return Values:
	//     0: Success
	//    -1: invalid state len
	//    -2: invalid zip len
	//    -3: invalid zip chars
	int init_address(std::string street, std::string city, std::string state, std::string zip);
	void copy_address(const Address & source);
	void print_address();
};

class Provider {
	/* for unit tests */
	friend bool Provider_init_happy();
	friend bool Provider_init_maxPid();

	public:
		/* Constructors */
		Provider();
		Provider(std::string _name, unsigned int _pid, const Address & _address);
		~Provider();

		/* Interface */
		void init_provider(std::string _name, unsigned int _pid, const Address & _address);
		void print_provider();              // mostly for testing
		unsigned int get_pid();		        // return pid
		std::string to_file();              // format data for json file
		void load_file();                   // load provider from json file
		void run_report();                  // generate provider report

		// overloaded for ease of use
		int edit_provider(std::string _name);
		int edit_provider(unsigned int _pid);
		int edit_provider(const Address & _address);
		int edit_provider(std::string _name, unsigned int _pid);
		int edit_provider(std::string _name, const Address & _address);
		int edit_provider(unsigned int _pid, const Address & _address);

		/* Overloaded Operators */
		bool operator==(Provider & toComp);

		/* Linked List Functionality */
		int add_service(Service);
		int remove_service(Service);


	protected:
		std::string name;
		unsigned int pid;     // provider ID; 9 digits
		Address address; 
		node_head * head;     // head of provided services list
		node * tail;          // tail of provided services list

		/* Service List Helper Fxns */
		void service_to_file();             // formats service data for provider json file
		void service_report();              // formats service data for provider report
		 
};

#endif // PROVIDER_H