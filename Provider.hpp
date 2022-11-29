// Ashton Sawyer 11/1

#ifndef PROVIDER_H
# define PROVIDER_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "json.hpp"
#include "Service_Record.hpp"
#include "Provider_Directory.hpp"

struct node {
	Service_Record * service;
	node * next;
};

struct node_head {
	int num_services_provided;
	int total_cost;
	node * next;
};

struct Address {
	std::string street;   // 25 char
	std::string city;     // 14 char
	std::string state;    // initials
	std::string zip;

	/* Interface */
	Address(std::string street, std::string city, std::string state, std::string zip);
	void init_address();          // asks user for input
	void init_address(std::string street, std::string city, std::string state, std::string zip);
	void copy_address(const Address & source);
	void print_address();

	//following fxns do error checking
	int set_street(std::string);
	int set_city(std::string);
	int set_state(std::string);
	int set_zip(std::string);
};

class Provider {
	/* for unit tests */
	friend bool Provider_init_happy();
	friend bool Provider_init_maxPid();

	public:
		/* Constructors */
		Provider();
		Provider(std::string _name, std::string _pid, const Address & _address);
		Provider(nlohmann::json j);
		~Provider();

		/* Interface */
		void init_provider();               // asks user for input
		std::string get_pid();		        // return pid
		std::string to_string();            // returns provider formatted as string
		std::string to_file();              // format data for json file
		void load_file(nlohmann::json j);   // load provider from json file
		void run_report();                  // generate provider report
		std::string run_manager_report();   // generate string for database gen. report

		// overloaded for ease of use
		//   return 0 on success
		//   *not error checked* -> error check input before use
		int edit_provider(std::string _name);
		int edit_provider(std::string _pid);
		int edit_provider(const Address & _address);
		int edit_provider(std::string _name, std::string _pid);
		int edit_provider(std::string _name, const Address & _address);
		int edit_provider(std::string _pid, const Address & _address);
		int edit_provider(std::string _name, std::string _pid, const Address & _address);

		/* Overloaded Operators */
		bool operator==(const Provider & toComp);
		bool operator<(const Provider & toComp);
		friend std::ostream & operator<<(std::ostream & out, const Provider & p);

		/* Linked List Functionality */
		int add_service(Service_Record * to_add);
		int remove_service(Service_Record * to_remove);
		int clear_services();


	protected:
		std::string name;    // expects: <first> <last> 
		std::string pid;     // provider ID; 9 digits
		Address address; 
		node_head * head;    // head of provided services list
		node * tail;         // tail of provided services list

		/* Service List Helper Fxns */
		std::string service_to_file();      // formats service data for provider json file
		std::string service_to_string();    // formats service data for provider report
		void delete_list();                 // destructor helper - deletes list, not head
		void init_list();                   // initializer helper

		/* Init Helper Fxns */
		int set_name(std::string _name);
		int set_pid(std::string _pid);
		int set_address(const Address & _address);
};

#endif // PROVIDER_H