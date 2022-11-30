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
	float total_cost;
	node * next;
};

struct Address {
	std::string street;   // 25 char
	std::string city;     // 14 char
	std::string state;    // initials
	std::string zip;

	/* Interface */
	Address();
	Address(std::string street, std::string city, std::string state, std::string zip); // not error checked
	void init_address();          // asks user for input
	// *following not error checked* -> error check input before use
	void init_address(std::string street, std::string city, std::string state, std::string zip);
	void copy_address(const Address & source);

	//following fxns do error checking
	//  ret 0 on success
	int set_street(std::string);
	int set_city(std::string);
	int set_state(std::string);
	int set_zip(std::string);
};

class Provider {
	/* for unit tests */
	friend bool Provider_init_happy();
	friend bool Provider_init_json();

	public:
		/* Constructors */
		Provider();
		Provider(std::string _name, std::string _pid, const Address & _address);  // no error checking
		Provider(nlohmann::json j, Provider_Directory &);
		~Provider();

		/* Interface */
		void init_provider();                     // asks user for input
		std::string get_pid();		              // return pid
		std::string to_string();                  // returns provider formatted as string
		std::string to_file();                    // format data for json file
		void run_report(Provider_Directory & d);  // generate provider report
		std::string run_manager_report();         // generate string for database gen. report
		void load_file(nlohmann::json j, Provider_Directory&);   // load provider from json file

		// overloaded for ease of use
		//   return 0 on success
		//   *not error checked* -> error check input before use
		int edit_provider(std::string name_or_pid);
		int edit_provider(const Address & _address);
		int edit_provider(std::string _name, std::string _pid);
		int edit_provider(std::string name_or_pid, const Address & _address);
		int edit_provider(std::string _name, std::string _pid, const Address & _address);

		/* Overloaded Operators */
		bool operator==(const Provider & toComp);
		friend std::ostream & operator<<(std::ostream & out, Provider & p);

		/* Linked List Functionality */
		int add_service(Service_Record & to_add, Provider_Directory & directory);
		int remove_service(Service_Record & to_remove);
		int clear_services();  // for resetting at end of week


	protected:
		std::string name;    // expects: <first> <last> 
		std::string pid;     // provider ID; 9 digits
		Address address; 
		node_head * head;    // head of provided services list
		node * tail;         // tail of provided services list

		/* Service List Helper Fxns */
		void service_load_file(nlohmann::json, Provider_Directory&);  // inits service list from json file
		std::string service_to_string(Provider_Directory&);  // formats service data for provider report
		std::string service_to_file();                       // formats service data for provider json file 
		void delete_list();                                  // destructor helper - deletes list, not head
		void init_list();                                    // initializer helper

		/* Init Helper Fxns */
		int set_name(std::string _name);
		int set_pid(std::string _pid);
		int set_address(const Address & _address);
};

#endif // PROVIDER_H