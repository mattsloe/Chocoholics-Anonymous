//Ashton Sawyer 11/1

#ifndef PROVIDER_DB_H
# define PROVIDER_DB_H

#include <unordered_map>
#include <functional>
#include "provider.h"

class Provider_Database {
	public:
		Provider_Database();
		~Provider_Database();
		bool validate_pid(std::string pid);  // check to see that there is a provider in db with given pid
		int add_provider();
		int delete_provider(std::string pid);
		int edit_provider(std::string pid);
		void to_file();
		void load_file();

	protected:
		unordered_map<int, Provider>
};

#endif // PROVIDER_DB_H 