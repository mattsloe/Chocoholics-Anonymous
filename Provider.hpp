// Ashton Sawyer 11/1

#ifndef PROVIDER_H
# define PROVIDER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Available_Services.hpp"

struct Address {
	std::string street;   // 25 char
	std::string city;     // 14 char
	std::string state;    // initials
	std::string zip;

	Address();			  // asks for input
	Address(std::string street, std::string city, std::string state, std::string zip);
	// Return Values:
	//     0: Success
	//    -1: invalid state len
	//    -2: invalid zip len
	//    -3: invalid zip chars
	int init_address(std::string street, std::string city, std::string state, std::string zip);  // return 0 success
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

		/* Overloaded Operators */
		bool operator==(Provider & toComp);

		/* avail_service Wrappers */
		int add_service();
		int remove_service();
		std::string validate_sid();
		void display_services();


	protected:
		std::string name;
		unsigned int pid;     // provider ID; 9 digits
		Address address; 
		Available_Services avail_services;

};

#endif // PROVIDER_H