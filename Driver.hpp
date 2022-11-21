#ifndef DRIVER_H
#define DRIVER_H

//Author: Nathan W.


#include <iostream>
#include <string>


#include "Service.hpp"
#include "Service_Record.hpp"
#include "Service_Ledger.hpp"

#include "Member.h"


using namespace std;



//Some helper functions for user input.
bool 	get_string(string user_str, const string prompt); 	//Always returns true.
int	get_int(void); 					 	//Returns the integer retrieved from the user. 
long	get_long(void);						//Returns the long retrieved from the user.:
bool 	get_char(void);						//Always returns true.



///////////	The following functions will be used to facilitate the the manipulation of the ProviderDB, MemberDB, and Service_Ledger.	////////////////
int validate_member(/*MemberDB &, Member *&*/);					//Returns 0 if the member number is found in the MemberDB else returns 1. Member object stores the member found.
int validate_provider(/*ProviderDB &, Provider *&*/);				//Returns 0 if provider number is found in the ProviderDB else returns 1. Provider object stores the provider found.
int validate_service(/*Provider &, Service *&*/);				//Returns 0 if service ID is found in the list of services provided by the provider else returns 1. 
										//Service stores the service found from the provider.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//Forward declarations for class Driver.
class Provider_Terminal;
class Interactive_Terminal;

//This is the main hub of menus that are output for the program.
class Driver {
	public:
		int start_driver();	//Main driver (this class)
		int start_pterm();	//Provider terminal
		int start_fterm();	//Financial Terminal
		int start_iterm();	//Interactive Mode Terminal


	private:
	Provider_Terminal 	*pterm;
	Interactive_Terminal 	*iterm;
	//Will need to add ProviderDB, MemberDB, and a Service Ledger (based on design document).
	


	//Potential private member functions include functions that delegate the output of menus. TBD...

};


//This is the provider terminal for providers within ChocAn to interact with.
class Provider_Terminal {
	public:
		int add_service_to_member(/*ProviderDB &, MemberDB &, Service_Ledger &*/);	//Locates member with member number in the MemberDB. Locates Service with service ID from provider from ProviderDB. Adds service to member
												//and then adds Service_Record to the Service_Ledger.
		
		int add_service_to_provider(/*ProviderDB &*/);					//Generates a service object that is then added to a provider from the ProviderDB.
		int generate_provider_report(/*ProviderDB &*/);					//Finds a provider in the ProviderDB and then generates a provider report using a function from the provider class 
												//(provider report from section 2.2.1 of the design document).

};


//This is the interactive terminal for managers within a ChocAn facility.
class Interactive_Terminal {
	public:
		int add_member(/*MemberDB &*/);							//Generates a member object with user input and adds it to the MemberDB.
		int remove_member(/*MemberDB &*/);						//Finds and removes a member from the MemberDB using a member number from the user.
		int edit_member(/*MemberDB &*/);						//Finds a member and edits member data members with user input.
	

		int add_provider(/*ProviderDB &*/);						//Generates a provider object with user input and adds it to the MemberDB.
		int remove_provider(/*ProviderDB &*/);						//Finds and removes a provider from the ProviderDB using a provider number from the user.
		int edit_provider(/*ProviderDB &*/);						//Finds a provider and edits provider data members with user input.

		int generate_member_reports(/*MemberDB &*/);					//Can either generate an individual member report or the entire MemberDB directory. Relies on member functions in DB and the Member class.
		int generate_provider_reports(/*ProviderDB &*/);				//Can either generate an individual provider report or the entire ProviderDB directory. Relies on member functions in DB and 
												//the Provider class. 
												//(provider report from section 2.2.1 of the design document).

};



//This is the financial terminal to test various functions that ACME will later utilize in their own terminal/program.
class Financial_Terminal {
	public:
		int generate_financial_report(/*Service_Ledger &*/);				//Generates a financial report for the past week of transactions from the Service_Ledger. 
												//(EFT Data from section 2.2.5 of the design document).
		int suspend_reinstate_member(/*MemberDB &*/);					//Will find a member from the MemberDB and manipulate the suspended data member.

};


#endif
