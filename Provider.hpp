// Ashton Sawyer 11/1

#ifndef PROVIDER_H
# define PROVIDER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "json.hpp"
#include "Service_Record.hpp"

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
	void init_address(std::string street, std::string city, std::string state, std::string zip)
	void copy_address(const Address & source);
	void print_address();
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
		void print_provider();              // mostly for testing
		std::string get_pid();		        // return pid
		std::string to_file();              // format data for json file
		void load_file();                   // load provider from json file
		void run_report();                  // generate provider report
		std::string run_manager_report();   // generate string for database gen. report

		// overloaded for ease of use
		//   return 0 on success
		int edit_provider(std::string _name);
		int edit_provider(std::string _pid);
		int edit_provider(const Address & _address);
		int edit_provider(std::string _name, std::string _pid);
		int edit_provider(std::string _name, const Address & _address);
		int edit_provider(std::string _pid, const Address & _address);

		/* Overloaded Operators */
		bool operator==(const Provider & toComp);
		bool operator<(const Provider & toComp);
		friend std::ostream & operator<<(std::ostream & out, const Provider & p);

		/* Linked List Functionality */
		int add_service(Service * to_add);
		int remove_service(Service * to_remove);


	protected:
		std::string name;
		std::string pid;     // provider ID; 9 digits
		Address address; 
		node_head * head;     // head of provided services list
		node * tail;          // tail of provided services list

		/* Service List Helper Fxns */
		void service_to_file();             // formats service data for provider json file
		void service_report();              // formats service data for provider report
		void delete_list();                 // destructor helper
		void init_list();                   // initializer helper

		/* Init + Edit Helper Fxns */
		int set_name(std::string _name);
		int set_pid(std::string _pid);
		int set_address(const Address & _address);
};

#endif // PROVIDER_H