#include "provider.h"

class Provider_db {
	public:
		Provider_db();
		~Provider_db();
		bool validate_pid(std::string pid);  // check to see that there is a provider in db with given pid
		int add_provider();
		int delete_provider(std::string pid);
		int edit_provider(std::string pid);

	protected:

};