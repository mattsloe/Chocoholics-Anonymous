//Ashton Sawyer 11/1

#ifndef PROVIDER_DB_H
# define PROVIDER_DB_H

#include <unordered_map>
#include <functional>
#include "provider.h"

class Provider_Database {
	public:
		/* Constructors */
		Provider_Database();
		~Provider_Database();

		/* Interface */
		int get_provider(std::string pid, const Provider &); 
		int add_provider(const Provider &);
		int delete_provider(std::string pid);
		int edit_provider(std::string pid);
		int add_service(std::string pid, Service_Record * service);
		void to_file();
		void load_file();

	protected:
		std::unordered_map<int, Provider> table; // maps Providers by PID
};

#endif // PROVIDER_DB_H 