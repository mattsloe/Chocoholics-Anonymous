#ifndef PROVIDER_DB_H
# define PROVIDER_DB_H

#include "provider.h"

class Provider_Database {
	public:
		Provider_Database();
		~Provider_Database();
		bool validate_pid(std::string pid);  // check to see that there is a provider in db with given pid
		int add_provider();
		int delete_provider(std::string pid);
		int edit_provider(std::string pid);

	protected:

};

#endif // PROVIDER_DB_H