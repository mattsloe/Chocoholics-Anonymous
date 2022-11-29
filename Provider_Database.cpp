// Ashton Sawyer 11/1 
#include "providerDB.h"

Provider_Database::Provider_Database() {
	
}

Provider_Database::~Provider_Database() {

}

//return false for no match, true for match
bool Provider_Database::validate_pid(std::string pid) {
	return false;
}

int Provider_Database::add_provider() {
	return 0;
}

int Provider_Database::delete_provider(std::string pid) {
	return 0;
}

int Provider_Database::edit_provider(std::string pid) {
	return 0;
}

void Provider_Database::to_file() {

}

void Provider_Database::load_file() {

}
