// Ashton Sawyer 11/1 
#include "Provider_Database.hpp"

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
	std::ofstream out_file("assets/provider_database.json");

	for (int i = 0; i < pids.size(); ++i) {
		out_file << (table.find(pids[i])).to_file();
	}
	out_file.close();
	return;
}

void Provider_Database::load_file() {

}

