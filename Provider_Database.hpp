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
		Provider_Database(nlohmann::json, Provider_Directory &);        // init from json
		~Provider_Database();                                           // save to file

		/* Interface */
		bool get_provider(std::string pid, Provider & to_fill);
		bool validate_pid(std::string pid);
		bool edit_provider(std::string pid, const Provider & to_copy);   // takes to_copy and copies it into provider w/ matching pid
		int add_provider();
		bool add_provider(Provider&);
		bool delete_provider(std::string pid);
		void generate_provider_reports(Provider_Directory &);
		void generate_single_report(std::string pid, Provider_Directory &);
		void to_file();
		void load_file(std::string file_name, Provider_Directory &);
		int display_all();

	protected:
		std::unordered_map <std::string, Provider*> table; // maps Providers by PID
		std::vector<std::string> pids;                      // list of pids in table to iterate through map
		std::string data_filename;
        const char* FILENAME = "assets/test-providers.json";

		void init(nlohmann::json, Provider_Directory &);  // init from json obj
}; 

#endif // PROVIDER_DB_H 