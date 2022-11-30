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
		Provider_Database(Provider_Directory &);
		Provider_Database(nlohmann::json, Provider_Directory &);  // init from json
		~Provider_Database();

		/* Interface */
		bool get_provider(std::string pid, Provider & to_fill);
		bool edit_provider(std::string pid, const Provider & to_copy);   // takes to_copy and copies it into provider w/ matching pid
		int add_provider(const Provider &);
		int delete_provider(std::string pid);
		int add_service(std::string pid, Service_Record & service);
		void generate_provider_reports();
		void generate_manager_report();
		void generate_single_report(std::string pid);
		void to_file();
		void load_file();

	protected:
		std::unordered_map<int, Provider> table; // maps Providers by PID
		std::vector<std::string> pids;           // list of pids in table to iterate through map
		Provider_Directory directory;            // for use with Provider fxns
};

#endif // PROVIDER_DB_H 