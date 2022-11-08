// Ashton Sawyer 11/1

#ifndef PROVIDER_H
# define PROVIDER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
//#include "AvailableServices.h"

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
		Provider(std::string provider);
		~Provider();
		void init_provider(std::string _name, std::string _pid, const Address & _address);
		void print_provider();         // mostly for testing
		std::string & to_file();       // format data as a string with delimeters for file storage
		bool operator==(int _pid);


	protected:
		std::string name;
		std::string pid;     // provider ID; 9 digits
		Address address; 
		//AvailableService avail_services;

};

#endif // PROVIDER_H