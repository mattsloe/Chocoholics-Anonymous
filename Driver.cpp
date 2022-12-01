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



bool validate_member(const string prompt, MemberDB &m_db) {
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
	if (m_db.get_member(m_id, to_find)) { //Replace true with function call to find member.
		if (!to_find.is_active())
			cout << "\n\nMember is suspended\n\n";
		else {
			cout << "\n\nVALIDATED\n\n";
			return true;
		}
	}
	else
		cout << "\n\nInvalid Member Number\n\n";

	return false;
}



//Need to be implemented. Will request user input for member, provider, and service ID's
bool validate_member(const string prompt, Member & to_find, string &m_id, MemberDB &m_db){
	char option = 'n';

	while (option != tolower('Y')) {
		cout << '\n';
		get_string(m_id, prompt);

		cout << "\n\n" << "Member ID: " << m_id << "\n\n";
		option = get_char("Is this the member ID correct? (y/n): ");
	}

	//FIND MEMBER.
	if (m_db.get_member(m_id, to_find)) { //Replace true with function call to find member.
		if (!to_find.is_active())
			cout << "\n\nMember is suspended\n\n";
		else {
			cout << "\n\nVALIDATED\n\n";
			return true;
		}
	}
	
	cout << "\n\nInvalid Member Number\n\n";
	
	return false;
}



bool validate_provider(const string prompt, Provider & to_find, string &p_id, Provider_Database & p_db) {
	char option = 'n';

	while (option != tolower('Y')) {
		cout << '\n';
		get_string(p_id, prompt);

		cout << "\n\n" << "Provider ID: " << p_id << "\n\n";
		option = get_char("Is this the provider ID correct? (y/n): ");
	}

	//FIND PROVIDER
	if (p_db.get_provider(p_id, to_find)) { //Replace true with function call to find provider.
		cout << "\n\n VALIDATED \n\n";
		return true;
	}
	
	cout << "\n\n Invalid Provider Number \n\n";

	return false;
}



bool validate_service(const string prompt, Service*& to_find, string& s_id, Provider_Directory & dir) {
	char option = 'y'; 

	while(option != tolower('N')) {

		char second_option = 'n';

		while (second_option != tolower('Y')) {
			cout << '\n';
			get_string(s_id, prompt);

			cout << "\n\n" << "Service ID: " << s_id << "\n\n";
			second_option = get_char("Is this the service ID correct? (y/n): ");
		}

		//FIND SERVICE
		if (dir.get_service(s_id, to_find)) { //Replace true with function call to find service.
			cout << "\n\n" << "Name of the service: " << to_find->get_name() << "\n\n";

			option = get_char("Is this the correct service name? (y/n): ");
			if(option == tolower('Y'))
				return true;
		}
		cout << "\n\n Invalid Service Number \n\n";
		option = get_char("Do you wish to try again? (y/n): ");
	}
	
	return false;
}







/////////////////////////////// DRIVER CLASS ///////////////////////////////////


Driver::Driver(): pterm(nullptr), iterm(nullptr), fterm(nullptr) //, directory(nullptr)
{
	pterm = new Provider_Terminal();
	iterm = new Interactive_Terminal();
	fterm = new Financial_Terminal();

	//directory = new Provider_Directory();

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
	/*
	if (directory) {
		delete directory;
		directory = nullptr;
	}
	*/
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
		3) Generate your individual provider report\n\t \
		4) Generate provider directory (list of available services)\n\t \
		5) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				validate_member("Please enter the 9-digit member ID number of the member you wish to validate: ", member_db);
				break;
			case 2:
				pterm->provide_service_to_member(member_db, ledger, directory, provider_db);
				break;
			case 3:
				pterm->generate_provider_report(provider_db, directory);
				break;
			case 4: 
				pterm->generate_provider_directory_report(directory);
				break;
		}
	}	
	
	cout << "\n\n" << endl;

	return;
}


	


void Driver::start_iterm() {
	
	int option = 0;

	cout << "Welcome to the interactive terminal! This is the terminal where you, the valued ChocAn manager, can manage your members, providers, and generate reports individually or in bulk for a given database/directory.\n" << endl;

	while(option <= 12) {
		option = (int) get_long("Please enter a number for the action you would like to take:\n\t \
		1)  Display the member database\n\t \
		2)  Add a member\n\t \
		3)  Remove a member\n\t \
		4)  Edit a member\n\t \
		5)  Display the provider database\n\t \
		6)  Add a provider\n\t \
		7)  Remove a provider\n\t \
		8)  Edit a provider\n\t \
		9)  Add service to provider directory\n\t \
		10) Generate member reports\n\t \
		11) Generate provider reports\n\t \
		12) Display provider directory\n\t \
		13) Exit terminal\n> ");
		
		switch(option) {
			case 1:
				iterm->display_member_db(member_db);
				break;
			case 2:
				iterm->add_member(member_db);
				break;
			case 3:
				iterm->remove_member(member_db);
				break;
			case 4:
				iterm->edit_member(member_db);
				break;
			case 5:
				iterm->display_provider_db(provider_db);
				break;
			case 6:
				iterm->add_provider(provider_db);
				break;
			case 7:
				iterm->remove_provider(provider_db);
				break;
			case 8:
				iterm->edit_provider(provider_db);
				break;
			case 9:
				iterm->add_service_to_provider_directory(directory);
				break;
			case 10:
				iterm->generate_member_reports(member_db, provider_db, directory);
				break;
			case 11:
				iterm->generate_provider_reports(provider_db, directory);
				break;
			case 12:
				iterm->display_provider_directory(directory);
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
				fterm->suspend_reinstate_member(member_db);
				break;
			case 2:
				fterm->generate_EFT(ledger, directory);
				break;
			case 3:
				fterm->generate_APR(ledger, directory);
				break;
		}
	}	
	
	cout << "\n\n" << endl;

	return;
}




/////////////////////////////// PROVIDER_TERMINAL CLASS ///////////////////////////////////


int Provider_Terminal::provide_service_to_member(MemberDB& m_db, Service_Ledger & ledger, Provider_Directory & dir, Provider_Database & p_db) {
	Member m_to_find;
	string m_id;

	Provider p_to_find;
	string p_id;

	Service* s_to_find;
	string s_id;

	Service_Record record;
	string date;
	string service_date;
	string comments;

	if (validate_provider("Please enter the 9-digit provider ID of the provider you would like to validate: ", p_to_find, p_id, p_db)) {
		if (validate_member("Please enter the 9-digit member ID of the member you would like to validate: ", m_to_find, m_id, m_db)) { //Member validated

			get_string(date, "Enter the current date (MM-DD-YYYY): ");
			get_string(service_date, "Enter the date the service was provided to the member (MM-DD-YYYY): ");

			if (validate_service("Please enter the 6-digit service ID to locate in the provider directory: ", s_to_find, s_id, dir)) { //Service validated
				//Build Service record
				get_string(comments, "Enter any comments about the service provided to the member: \n");

				record.set_date(date);
				record.set_sDate(service_date);
				record.set_mID(m_id);
				record.set_pID(p_id);
				record.set_sID(s_id);
				record.set_comments(comments);

				cout << "\n\nThis is the final service record: \n\n";

				record.display();

				cout << "\n\n";

				//Add Service Record to Member, Provider, and Service Ledger
				cout << "Adding service record to the global ledger...\n";
				ledger.new_transaction(record);


				cout << "Adding service record to the provider database...\n";
				p_to_find.add_service(record, dir);
				p_db.edit_provider(p_id, p_to_find);


				cout << "Adding service record to the member database...\n";
				m_to_find.add_service(record);
				m_db.edit(m_id, m_to_find);

				//Write Service Record to disc here (currently not implemented).

				return 1;
			}
		}
	}

	return 0;
}

//Call function from providerDB (single report for a specific pID)
int Provider_Terminal::generate_provider_report(Provider_Database & p_db, Provider_Directory & dir) { 
	
	Provider to_find;
	string p_id;

	//Technically, any provider can run a report on any other provider... This is a limit of the implementation at this time.
	if (validate_provider("Please enter the 9-digit member ID that you would like to generate a report for: ", to_find, p_id, p_db)) {
		//CALL MEMBERDB REPORT FUNCTION HERE
		cout << "Generating report for the following provider ID: " << p_id << "\n\n";
		p_db.generate_single_report(p_id, dir);

		return 1;
	}

	return 0;
} 



//Generate provider directory (list of services) to email to a provider.
int Provider_Terminal::generate_provider_directory_report(Provider_Directory & dir) { 
	cout << "\n\nThis option is not implemented\n\n";
	return 0; 
}




/////////////////////////////// INTERACTIVE_TERMINAL CLASS ///////////////////////////////////


int Interactive_Terminal::display_member_db(MemberDB & m_db) {
	int total = m_db.display_all();
	cout << "\n\n" << "The total number of members is: " << total << "\n\n";
	return 1; 
}



int Interactive_Terminal::add_member(MemberDB &m_db) {

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
	
	if (m_db.add_member(member_to_add))
		cout << "\n\nAdd successful\n\n";
	else
		cout << "\n\nAdd failed\n\n";

	return 1;
}



int Interactive_Terminal::remove_member(MemberDB& m_db) {
	Member to_find;
	string m_id;

	if (validate_member("Please enter the 9-digit member ID of the member you would like to remove: ", to_find, m_id, m_db)) { //validate member here.
		//REMOVE MEMBER FROM DB HERE.
		if (m_db.delete_member(m_id))
			cout << "\n\nDelete successful\n\n";
		else
			cout << "\n\nDelete failed\n\n";

		return 1;
	}

	return 0;
}




int Interactive_Terminal::edit_member(MemberDB& m_db) {
	Member	member_to_edit, to_find;
	string	m_id;
	string	name, \
			street, \
			city, \
			state, \
			zip;

	m_db.display_all();
	if (validate_member("Please enter the 9-digit member ID of the member you would like to edit: ", to_find, m_id, m_db)) { //validate provider here.
		//EDIT PROVIDER FROM DB HERE.
		cout << "\n\n" << to_find << "\n\n";
		char edit = get_char("Would you like to edit the member? (y/n): ");

		if (edit == tolower('Y')) {

			char option = 'n';

			while (option != tolower('Y')) {
				get_string(name, "Please enter the name of the member: ");
				get_string(street, "Please enter the street address of the member: ");
				get_string(city, "Please enter the city in which the member resides: ");
				get_string(state, "Please enter the state in which the member resides: ");
				get_string(zip, "Please enter the zipcode of the member: ");

				member_to_edit.set_name(name);
				member_to_edit.set_address(street);
				member_to_edit.set_city(city);
				member_to_edit.set_state(state);
				member_to_edit.set_zip(zip);
				member_to_edit.set_MID(m_id);

				cout << "\n\n" << member_to_edit << "\n\n";
				option = get_char("Is this the member information correct? (y/n): ");

				if (m_db.edit(m_id, member_to_edit)) {
					cout << "\n\nEdit successful\n\n";
				}
				else
					cout << "\n\nEdit failed\n\n";
			}
		}

		return 1;
	}

	return 0;
}



int Interactive_Terminal::display_provider_db(Provider_Database & p_db) { 
	int total = p_db.display_all();
	cout << "\n\n" << "The total number of providers is: " << total << "\n\n"; 
	return 1; 
}



int Interactive_Terminal::add_provider(Provider_Database & p_db) {

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
	if (p_db.add_provider(provider_to_add))
		cout << "\n\n Add successful \n\n";
	else
		cout << "\n\n Add failed \n\n";

	return 1;
}



int Interactive_Terminal::remove_provider(Provider_Database & p_db) {
	Provider to_find;
	string p_id;

	if (validate_provider("Please enter the 9-digit provider ID of the provider you would like to remove: ", to_find, p_id, p_db)) { //validate provider here.
		//REMOVE MEMBER FROM DB HERE.
		if (p_db.delete_provider(p_id))
			cout << "\n\nDelete successful\n\n";
		else
			cout << "\n\nDelete failed\n\n";

		return 1;
	}

	return 0;
}




int Interactive_Terminal::edit_provider(Provider_Database & p_db) {
	Provider provider_to_edit, to_find;
	string p_id;
	Address	 address_to_edit;
	string	name, \
		street, \
		city, \
		state, \
		zip;

	p_db.display_all();
	if (validate_provider("Please enter the 9-digit provider ID of the provider you would like to edit: ", to_find, p_id, p_db)) { //validate provider here.
		//EDIT PROVIDER FROM DB HERE.
		cout << "\n\n" << to_find << "\n\n";
		char edit = get_char("Would you like to edit the provider? (y/n): ");
			
		if (edit == tolower('Y')) {
				
			char option = 'n';
				
			while (option != tolower('Y')) {
				get_string(name, "Please enter the name of the provider: ");
				get_string(street, "Please enter the street address of the provider: ");
				get_string(city, "Please enter the city in which the provider resides: ");
				get_string(state, "Please enter the state in which the provider resides: ");
				get_string(zip, "Please enter the zipcode of the provider: ");

				address_to_edit.init_address(street, city, state, zip);
				provider_to_edit.edit_provider(name, p_id, address_to_edit);

				cout << "\n\n" << provider_to_edit << "\n\n";
				option = get_char("Is this the provider information correct? (y/n): ");

				if (p_db.edit_provider(p_id, provider_to_edit)) {
					cout << "\n\n Edit successful\n\n";
				}
				else
					cout << "\n\n Edit failed\n\n";
			}
		}
		
		return 1;
	}

	return 0;
}




int Interactive_Terminal::add_service_to_provider_directory(Provider_Directory & dir) { 
	cout << "\n\n";
	dir.create_new_service();
	cout << "\n\n";
	return 1; 
}



int Interactive_Terminal::display_provider_directory(Provider_Directory & dir) {
	dir.display();
	return 1;
}




//Call function from memberDB (single report for a specific mID or the entire database.
int Interactive_Terminal::generate_member_reports(MemberDB& m_db, Provider_Database & p_db, Provider_Directory & dir) { 
	
	int option = 0;

	while (option <= 2) {
		option = (int) get_long("Which option would you prefer?\n\t \
							1) Generate an individual member report\n\t \
							2) Generate the entire member database\n>");
		switch (option) {
		case 1:
		{
			cout << "\n\nThis option is not implemented.\n\n";
			/*
			Member to_find;
			string m_id;

			if (validate_member("Please enter the 9-digit member ID that you would like to generate a report for: ", to_find, m_id, m_db)) {
				//CALL MEMBERDB REPORT FUNCTION HERE
				
			}
			*/
		}
		break;
		case 2:
			//CALL MEMBERDB REPORT FUNCTION HERE
			cout << "\n\nRunning member reports on entire database...\n\n";
			m_db.run_member_reports(dir, p_db);
			break;
		}
	}

	return 1; 
} 


int Interactive_Terminal::generate_provider_reports(Provider_Database & p_db, Provider_Directory & dir) { 
	int option = 0;

	while (option <= 2) {
		option = (int)get_long("Which option would you prefer?\n\t \
							1) Generate an individual provider report\n\t \
							2) Generate the entire provider database\n>");
		switch (option) {
		case 1:
		{
			Provider to_find;
			string p_id;

			if (validate_provider("Please enter the 9-digit member ID that you would like to generate a report for: ", to_find, p_id, p_db)) {
				//CALL MEMBERDB REPORT FUNCTION HERE
				cout << "\n\nRunning report for the following provider ID: " << p_id << "\n\n";
				p_db.generate_single_report(p_id, dir);
			}
		}
		break;
		case 2:
			//CALL MEMBERDB REPORT FUNCTION HERE
			cout << "\n\nRunning provider reports on entire database...\n\n";
			p_db.generate_provider_reports(dir);
			break;
		}
	}

	return 1;
}



/////////////////////////////// FINANCIAL_TERMINAL CLASS ///////////////////////////////////

int Financial_Terminal::generate_EFT(Service_Ledger& ledger, Provider_Directory & dir) {

	cout << "\n\nGenerating EFT Data\n\n";
	ledger.generate_EFT(dir);
	return 1;
}



int Financial_Terminal::generate_APR(Service_Ledger& ledger, Provider_Directory & dir) {

	cout << "\n\nGenerating APR Data\n\n";
	ledger.generate_APR(dir);
	return 1;
}



int Financial_Terminal::suspend_reinstate_member(MemberDB& m_db) {
	Member to_find;
	string m_id;

	m_db.display_all();

	char option = 'n';

	while (option != tolower('Y')) {
		cout << '\n';
		get_string(m_id, "Please enter the 9-digit member ID of the member you wish to suspend/reinstate: ");

		cout << "\n\n" << "Member ID: " << m_id << "\n\n";
		option = get_char("Is this the member ID correct? (y/n): ");
	}

	if (m_db.get_member(m_id, to_find)) {
		cout << "\nMember Before:\n\n" << to_find << "\n\n";

		to_find.toggle_active();
		m_db.edit(m_id, to_find);
		
		cout << "\nMember after:\n\n" << to_find << "\n\n";

		return 1;
	}

	return 0;
}