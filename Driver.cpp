#include "Driver.hpp"

//Author: Nathan Waggoner


/////////////////////////////// HELPER FUNCTIONS ///////////////////////////////////

//Retrieves a string from the user and outputs a prompt.
void get_string(string &user_str, const string prompt) {
	cout << prompt;
	
	getline(cin, user_str, '\n');

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



bool validate_member(const string prompt) {
	string m_id;
	Member to_find;
	char option = 'n';

	while (option != tolower('Y')) {
		cout << '\n';
		get_string(m_id, prompt);

		cout << "\n\n" << "Member ID: " << m_id << "\n\n";
		option = get_char("Is this the member ID correct? (y/n): ");
	}

	//FIND MEMBER.
	if (true) { //Replace true with function call to find member.
		if (!to_find.is_active())
			cout << "\n\n Member is suspended \n\n";
		else {
			cout << "\n\n VALIDATED \n\n";
			return true;
		}
	}


	cout << "\n\n Invalid Member Number \n\n";

	return false;
}



//Need to be implemented. Will request user input for member, provider, and service ID's
bool validate_member(const string prompt, Member & to_find, string &m_id){
	char option = 'n';

	while (option != tolower('Y')) {
		cout << '\n';
		get_string(m_id, prompt);

		cout << "\n\n" << "Member ID: " << m_id << "\n\n";
		option = get_char("Is this the member ID correct? (y/n): ");
	}

	//FIND MEMBER.
	if (true) { //Replace true with function call to find member.
		if (!to_find.is_active())
			cout << "\n\n Member is suspended \n\n";
		else {
			cout << "\n\n VALIDATED \n\n";
			return true;
		}
	}
	
	cout << "\n\n Invalid Member Number \n\n";
	
	return false;
}



bool validate_provider(const string prompt, Provider & to_find, string &p_id) {
	char option = 'n';

	while (option != tolower('Y')) {
		cout << '\n';
		get_string(p_id, prompt);

		cout << "\n\n" << "Provider ID: " << p_id << "\n\n";
		option = get_char("Is this the provider ID correct? (y/n): ");
	}

	//FIND PROVIDER
	if (true) { //Replace true with function call to find provider.
		cout << "\n\n VALIDATED \n\n";
		return true;
	}
	
	cout << "\n\n Invalid Provider Number \n\n";

	return false;
}



bool validate_service(const string prompt, Service& to_find, string &s_id) {
	string lo_id;
	char option = 'n';

	while (option != tolower('Y')) {
		cout << '\n';
		get_string(s_id, prompt);

		cout << "\n\n" << "Service ID: " << s_id << "\n\n";
		option = get_char("Is this the service ID correct? (y/n): ");
	}

	//FIND SERVICE
	if (true) { //Replace true with function call to find service.
		cout << "\n\n VALIDATED \n\n";
		s_id = lo_id;
		return true;
	}
	
	
	cout << "\n\n Invalid Service Number \n\n";

	return false;
}







/////////////////////////////// DRIVER CLASS ///////////////////////////////////

Driver::Driver(): pterm(nullptr), iterm(nullptr), fterm(nullptr), directory(nullptr)
{
	pterm = new Provider_Terminal();
	iterm = new Interactive_Terminal();
	fterm = new Financial_Terminal();

	directory = new Provider_Directory("assets/services.json");

	//READ FROM DISC HERE
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

	if (directory) {
		delete directory;
		directory = nullptr;
	}
	//WRITE TO DISC HERE
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

	while(option <= 4) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t \
		1) Validate Member\n\t \
		2) Add a provided service to a member\n\t \
		3) Generate your provider report\n\t \
		4) Generate provider directory (list of available services)\n\t \
		5) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				validate_member("Please enter the 9-digit member ID number of the member you wish to validate: ");
				break;
			case 2:
				pterm->provide_service_to_member();
				break;
			case 3:
				break;
			case 4: 
				break;
		}
	}	
	
	cout << "\n\n" << endl;

	return;
}


	


void Driver::start_iterm() {
	
	int option = 0;

	cout << "Welcome to the interactive terminal! This is the terminal where you, the valued ChocAn manager, can manage your members, providers, and generate reports individually or in bulk for a given database/directory.\n" << endl;

	while(option <= 11) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t \
		1) Display the member database\n\t \
		2) Add a member\n\t \
		3) Remove a member\n\t \
		4) Edit a member\n\t \
		5) Display the provider database\n\t \
		6) Add a provider\n\t \
		7) Remove a provider\n\t \
		8) Edit a provider\n\t \
		9) Add service to provider directory\n\t \
		10) Generate member reports\n\t \
		11) Generate provider reports\n\t \
		12) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				iterm->display_member_db();
				break;
			case 2:
				iterm->add_member();
				break;
			case 3:
				iterm->remove_member();
				break;
			case 4:
				iterm->edit_member();
				break;
			case 5:
				iterm->display_provider_db();
				break;
			case 6:
				iterm->add_provider();
				break;
			case 7:
				iterm->remove_member();
				break;
			case 8:
				iterm->edit_provider();
				break;
			case 9:
				iterm->add_service_to_provider_directory();
				break;
			case 10:
				iterm->generate_member_reports();
				break;
			case 11:
				iterm->generate_provider_reports();
				break;
		}
	}	
	
	cout << "\n\n" << endl;

	return;
}




void Driver::start_fterm() {
	
	int option = 0;

	cout << "Welcome to the Financial (ACME) terminal! This is the terminal where you, the valued ChocAn financial accountant, can manage a member's status and generate financial reports.\n" << endl;

	while(option <= 3) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t \
		1) Suspend or reinstate a member\n\t \
		2) Generate a EFT Data Report\n\t \
		3) Generate APR Data Report\n\t \
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
	
	cout << "\n\n" << endl;

	return;
}




/////////////////////////////// PROVIDER_TERMINAL CLASS ///////////////////////////////////

int Provider_Terminal::provide_service_to_member() {
	Member to_find;
	string m_id;

	if (validate_member("Please enter the 9-digit provider ID of the provider you would like to validate: ", to_find, m_id)) {

	}

	return 1;
}


int Provider_Terminal::generate_provider_report() {

	return 1;
}


int Provider_Terminal::generate_provider_directory() { return 1; }




/////////////////////////////// INTERACTIVE_TERMINAL CLASS ///////////////////////////////////


int Interactive_Terminal::display_member_db() { return 1; }



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
		get_string(m_id, "Please enter the 9-digit member ID of the member: ");
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
		option = get_char("Is this the member information correct? (y/n): ");
	}

	//ADD MEMBER TO DB HERE


	return 1;
}



int Interactive_Terminal::remove_member() {
	Member to_find;
	string m_id;

	if (validate_member("Please enter the 9-digit member ID of the member you would like to remove: ", to_find, m_id)) { //validate member here.
		//REMOVE MEMBER FROM DB HERE.

		return 1;
	}

	return 0;
}




int Interactive_Terminal::edit_member() {
	Member to_find;
	string m_id;

	if (validate_member("Please enter the 9-digit member ID of the member you would like to edit: ", to_find, m_id)) { //validate member here.
		//EDIT MEMBER FROM DB HERE.

		return 1;
	}

	return 0;
}



int Interactive_Terminal::display_provider_db() { return 1; }



int Interactive_Terminal::add_provider() {

	//Create Member object to be added to MemberDB
	Provider provider_to_add;
	Address	 address_to_add;
	string	name, \
		p_id, \
		street, \
		city, \
		state, \
		zip;

	char option = 'n';
	while (option != tolower('Y')) {
		get_string(name, "Please enter the name of the provider: ");
		get_string(p_id, "Please enter the 9-digit member ID of the provider: ");
		get_string(street, "Please enter the street address of the provider: ");
		get_string(city, "Please enter the city in which the provider resides: ");
		get_string(state, "Please enter the state in which the provider resides: ");
		get_string(zip, "Please enter the zipcode of the provider: ");

		address_to_add.init_address(street, city, state, zip);
		provider_to_add.edit_provider(name, p_id, address_to_add);

		cout << "\n\n" << provider_to_add << "\n\n";
		option = get_char("Is this the provider information correct? (y/n): ");
	}

	//ADD PROVIDER TO DB HERE


	return 1;
}



int Interactive_Terminal::remove_provider() {
	Provider to_find;
	string p_id;

	if (validate_provider("Please enter the 9-digit provider ID of the provider you would like to remove: ", to_find, p_id)) { //validate provider here.
		//REMOVE PROVIDER FROM DB HERE.

		return 1;
	}

	return 0;
}




int Interactive_Terminal::edit_provider() {
	Provider to_find;
	string p_id;

	if (validate_provider("Please enter the 9-digit provider ID of the provider you would like to edit: ", to_find, p_id)) { //validate provider here.
		//EDIT PROVIDER FROM DB HERE.

		return 1;
	}

	return 0;
}




int Interactive_Terminal::add_service_to_provider_directory() { return 0; }
int Interactive_Terminal::generate_member_reports() { return 0; }
int Interactive_Terminal::generate_provider_reports() { return 0; }



