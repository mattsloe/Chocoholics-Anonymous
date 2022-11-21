#include "Driver.hpp"

//Author: Nathan W.


//Retrieves a string from the user and outputs a prompt.
void get_string(string user_str, const string prompt) {
	cout << prompt;
	
	getline(cin, user_str, '\n');
	while(!cin) {
		cin.clear();
		cin.ignore(MAX_CHARS, '\n');
		cout << "This is invalid an input. Please try again...\n> ";
		getline(cin, user_str, '\n');
	}
	cin.ignore(MAX_CHARS, '\n');

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
		option = (int) get_long("Please enter a number for the terminal you would like to use:\n\t1) Provider Terminal\n\t2) Interactive Terminal\n\t3) Financial Terminal\n\t4) Quit Program\n> ");
		
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
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t1) Add a provided service to a member\n\t2) Add a service to your list of available services to members\n\t3) Generate your provider report\n\t4) Exit terminal\n> ");
		
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
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t1) Display the member directory\n\t2) Add a member\n\t3) Remove a member\n\t4) Edit a member\n\t5) Display the provider directory\n\t6) Add a provider\n\t7) Remove a provider\n\t8) Edit a provider\n\t9) Generate member reports\n\t10) Generate provider reports\n\t11) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				break;
			case 2:
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
		}
	}	
	
	cout << '\n' << endl;

	return;
}




void Driver::start_fterm() {
	
	int option = 0;

	cout << "Welcome to the Financial (ACME) terminal! This is the terminal where you, the valued ChocAn financial accountant, can manage a member's status and generate financial reports.\n" << endl;

	while(option <= 2) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t1) Suspend or reinstate a member\n\t2) Generate a EFT Data Report\n\t3) Exit terminal\n> ");
		
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
