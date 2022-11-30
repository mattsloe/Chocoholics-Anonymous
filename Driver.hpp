#ifndef DRIVER_H
#define DRIVER_H

//Author: Nathan Waggoner


#include <iostream>
#include <string>

//Custom file includes from our project.
#include "Member.hpp"
#include "Provider_Database.hpp"
#include "Service_Ledger.hpp" //Includes Service_Ledger, Service_Record, Service, and Provider_Directory



using namespace std;


const int MAX_CHARS = 256;


//Some helper functions for user input.
void 	get_string(string &user_str, const string prompt); 	//Retrieves a string from the user.
long	get_long(const string prompt);						//Returns the long retrieved from the user.
char 	get_char(const string prompt);						//Always returns true.



///////////	The following functions will be used to facilitate the the manipulation of the ProviderDB, MemberDB, and Service_Ledger.	////////////////
bool validate_member(const string prompt);
bool validate_member(const string prompt, Member & to_find, string &m_id/*,MemberDB &*/);									//Returns 0 if the member number is found in the MemberDB else returns 1. Member object stores the member found.
bool validate_provider(const string prompt, Provider & to_find, string &p_id/*ProviderDB &*/);								//Returns 0 if provider number is found in the ProviderDB else returns 1. Provider object stores the provider found.
bool validate_service(const string prompt, Service & to_find, string &s_id/*Provider_Directory &, Service &*/);				//Returns 0 if service ID is found in the list of services provided by the provider else returns 1. 
																		//Service stores the service found from the provider.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//Forward declarations for class Driver.
class Provider_Terminal;
class Interactive_Terminal;
class Financial_Terminal;

//This is the main hub of menus that are output for the program.
class Driver {
	public:
		Driver();
		~Driver();

		void start_driver();	//Main driver (this class)
		void start_pterm();		//Provider terminal
		void start_fterm();		//Financial Terminal
		void start_iterm();		//Interactive Mode Terminal


	private:
	Provider_Terminal 		*pterm;
	Interactive_Terminal 	*iterm;
	Financial_Terminal		*fterm;
	//Will need to add ProviderDB, MemberDB, Service_Ledger, and a Provider_Directory (based on design document).
	//Potential private member functions include functions that delegate the output of menus. TBD...
	Service_Ledger ledger;
	Provider_Directory * directory;

};


//This is the provider terminal for providers within ChocAn to interact with.
class Provider_Terminal {
	public:
		int provide_service_to_member(/*ProviderDB &, MemberDB &, Service_Ledger &*/);	//Locates member with member number in the MemberDB. Locates Service with service ID from provider from ProviderDB. Adds service to member
																						//and then adds Service_Record to the Service_Ledger and Provider.
		int generate_provider_report(/*ProviderDB &*/);									//Finds a provider in the ProviderDB and then generates a provider report using a function from the provider class 
																						//(provider report from section 2.2.1 of the design document).
		int generate_provider_directory(/*Provider_Directory &*/);
};


//This is the interactive terminal for managers within a ChocAn facility.
class Interactive_Terminal {
	public:
		int display_member_db();

		int add_member(/*MemberDB &*/);												//Generates a member object with user input and adds it to the MemberDB.
		int remove_member(/*MemberDB &*/);											//Finds and removes a member from the MemberDB using a member number from the user.
		int edit_member(/*MemberDB &*/);											//Finds a member and edits member data members with user input.
	
		int display_provider_db();
	
		int add_provider(/*ProviderDB &*/);											//Generates a provider object with user input and adds it to the MemberDB.
		int remove_provider(/*ProviderDB &*/);										//Finds and removes a provider from the ProviderDB using a provider number from the user.
		int edit_provider(/*ProviderDB &*/);										//Finds a provider and edits provider data members with user input.

		int add_service_to_provider_directory(/*Provider_Directory &*/);			//Generates a service object that is then added to a provider from the ProviderDB.

		int generate_member_reports(/*MemberDB &*/);								//Can either generate an individual member report or the entire MemberDB directory. Relies on member functions in DB and the Member class.
		int generate_provider_reports(/*ProviderDB &*/);							//Can either generate an individual provider report or the entire ProviderDB directory. Relies on member functions in DB and 
																					//the Provider class. 
																					//(provider report from section 2.2.1 of the design document).

};



//This is the financial terminal to test various functions that ACME will later utilize in their own terminal/program.
class Financial_Terminal {
	public:
		int generate_EFT(/*Service_Ledger &*/);				//Generates a financial report for the past week of transactions from the Service_Ledger. 
															//(EFT Data from section 2.2.5 of the design document).
		int generate_APR(/*Service_Ledger &*/);
		int suspend_reinstate_member(/*MemberDB &*/);		//Will find a member from the MemberDB and manipulate the suspended data member.

};


#endif 
