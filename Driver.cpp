#include "Driver.hpp"

//Author: Nathan W.


/////////////////////////////// HELPER FUNCTIONS ///////////////////////////////////

//Retrieves a string from the user and outputs a prompt.
void get_string(string &user_str, const string prompt) {
	cout << prompt;
	
	getline(cin, user_str, '\n');
	
	/*
	while(!cin) {
		cin.clear();
		cin.ignore(MAX_CHARS, '\n');
		cout << "This is invalid an input. Please try again...\n> ";
		getline(cin, user_str, '\n');
	}
	cin.ignore(MAX_CHARS, '\n');
	*/

	return;
}



//Retrieves a long from the user and outputs a prompt.
long get_long(const string prompt) {	//Not the best thing to tell someone on the first date.
	long ret = 0;	
	
	cout << prompt;
	
	cin >> ret;
	while(!cin) {
		cin.clear();
		cin.ignore(MAX_CHARS, '\n');
		cout << "This is invalid an input. Please try again...\n> ";
		cin >> ret;	
	}
	cin.ignore(MAX_CHARS, '\n');

	return ret;
}



//Retrieves a char from the user and outputs a prompt.
char get_char(const string prompt) {
	char ret = '\0';

	cout << prompt;

	cin >> ret;
	while(!cin) {
		cin.clear();
		cin.ignore(MAX_CHARS, '\n');
		cout << "This is an invalid input. Please try again...\n> ";
		cin >> ret;	
	}
	cin.ignore(MAX_CHARS, '\n');

	return ret;
}





//Need to be implemented. Will request user input for member, provider, and service ID's
int validate_member(){return 1;}
int validate_provider(){return 1;}
int validate_service(){return 1;}







/////////////////////////////// DRIVER CLASS ///////////////////////////////////

Driver::Driver(): pterm(nullptr), iterm(nullptr), fterm(nullptr)
{
	pterm = new Provider_Terminal();
	iterm = new Interactive_Terminal();
	fterm = new Financial_Terminal();
}


Driver::~Driver() {
	if(pterm) {
		delete pterm;
		pterm = nullptr;
	}
	if(iterm) {
		delete iterm;
		iterm = nullptr;
	}
	if(fterm) {
		delete fterm;
		fterm = nullptr;
	}
}



void Driver::start_driver() {
		
	int option = 0;

	while(option <= 3) {
		option = (int) get_long("Please enter a number for the terminal you would like to use:\n\t \
		1) Provider Terminal\n\t \
		2) Interactive Terminal\n\t \
		3) Financial Terminal\n\t \
		4) Quit Program\n> ");
		
		cout << '\n' << endl;
		
		switch (option) {
			case 1:
				start_pterm();
				break;
			case 2:
				start_iterm();
				break;
			case 3:
				start_fterm();
				break;
		}
	}

	return;
}




void Driver::start_pterm() { 
	
	int option = 0;

	cout << "Welcome to the provider terminal! This is the terminal where you, the valued ChocAn provider, can manage your business and services provided to members.\n" << endl;

	while(option <= 3) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t \
		1) Add a provided service to a member\n\t \
		3) Generate your provider report\n\t \
		4) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
		}
	}	
	
	cout << '\n' << endl;

	return;
}


	


void Driver::start_iterm() {
	
	int option = 0;

	cout << "Welcome to the interactive terminal! This is the terminal where you, the valued ChocAn manager, can manage your members, providers, and generate reports individually or in bulk for a given database/directory.\n" << endl;

	while(option <= 10) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t \
		1) Display the member directory\n\t \
		2) Add a member\n\t \
		3) Remove a member\n\t \
		4) Edit a member\n\t \
		5) Display the provider directory\n\t \
		6) Add a provider\n\t \
		7) Remove a provider\n\t \
		8) Edit a provider\n\t \
		9) Generate member reports\n\t \
		10) Generate provider reports\n\t \
		11) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				break;
			case 2:
				iterm->add_member();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
		}
	}	
	
	cout << '\n' << endl;

	return;
}




void Driver::start_fterm() {
	
	int option = 0;

	cout << "Welcome to the Financial (ACME) terminal! This is the terminal where you, the valued ChocAn financial accountant, can manage a member's status and generate financial reports.\n" << endl;

	while(option <= 2) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t \
		1) Suspend or reinstate a member\n\t \
		2) Generate a EFT Data Report\n\t \
		3) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				break;
			case 2:
				break;
		}
	}	
	
	cout << '\n' << endl;

	return;
}




/////////////////////////////// INTERACTIVE_TERMINAL CLASS ///////////////////////////////////


int Interactive_Terminal::add_member() {

	//Create Member object to be added to MemberDB
	Member member_to_add;
	string	name, \
			m_id, \
			address, \
			city, \
			state, \
			zip;

	char option = 'n';
	while (option != tolower('Y')) {
		get_string(name, "Please enter the name of the member: ");
		get_string(m_id, "Please enter the member ID of the member: ");
		get_string(address, "Please enter the street address of the member: ");
		get_string(city, "Please enter the city in which the member resides: ");
		get_string(state, "Please enter the state in which the member resides: ");
		get_string(zip, "Please enter the zipcode of the member: ");

		member_to_add.set_name(name);
		member_to_add.set_MID(m_id);
		member_to_add.set_address(address);
		member_to_add.set_city(city);
		member_to_add.set_state(state);
		member_to_add.set_zip(zip);

		cout << "\n\n" << member_to_add << "\n\n";
		option = get_char("Is this the information for the member correct? (y/n): ");
	}

	//ADD MEMBER TO DB HERE


	return 0;
}