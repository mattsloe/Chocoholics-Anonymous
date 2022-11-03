#include "providerDB.h"

Provider_db::Provider_db() {
	
}

Provider_db::~Provider_db() {

}

//return false for no match, true for match
bool Provider_db::validate_pid(std::string pid) {
	return false;
}

int Provider_db::add_provider() {
	return 0;
}

int Provider_db::delete_provider(std::string pid) {
	return 0;
}

int Provider_db::edit_provider(std::string pid) {
	return 0;
}