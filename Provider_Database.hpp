//Ashton Sawyer 11/1
// wrappers -> when doing things give back ref for driver to print

#ifndef PROVIDER_DB_H
# define PROVIDER_DB_H

#include <unordered_map>
#include "Provider.hpp"
#include "json.hpp"

class Provider_Database {
	public:
		/* Constructors */
		Provider_Database();
		explicit Provider_Database(nlohmann::json)  // init from json
		~Provider_Database();

		/* Interface */
		int get_provider(std::string pid, const Provider &); 
		int add_provider(const Provider &);
		int delete_provider(std::string pid);
		int edit_provider(std::string pid, Provider & to_fill);
		int add_service(std::string pid, Service_Record * service);
		void to_file();
		void load_file();

	protected:
		std::unordered_map<int, Provider> table; // maps Providers by PID
};

#endif // PROVIDER_DB_H 