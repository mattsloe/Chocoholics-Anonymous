#ifndef PROVIDER_TESTER_HPP
# define PROVIDER_TESTER_HPP

#include "Provider.hpp"

using namespace std;

class Provider_tester {
	public: 
		void test_provider_class();
		void test_address_struct();    // called by test_provider_class()

		/* Provider Tests - unfinished */
		bool Provider_getPid_happy();
		bool Provider_toString_happy();
		bool Provider_toFile_happy();            // uses Service_Record fxn - maybe
		bool Provider_loadFile_happy();          // uses Service_Record fxn - maybe
		bool Provider_opEqual_match();
		bool Provider_opEqual_noMatch();
		bool Provider_opLess_less();
		bool Provider_opLess_more();
		bool Provider_runReport_happy();         // uses Service_Record fxn
		bool Provider_runManagerReport_happy();  // uses Service_Record fxn
		bool Provider_addService_happy();
		bool Provider_removeService_happy();
		bool Provider_removeService_empty();
		bool Provider_clearService_happy();



		/* Address Tests - finished */
		bool Address_init_happy();
		bool Address_set_badState();
		bool Address_set_badZipLen();
		bool Address_set_badZipChar();
		bool Address_copy_happy();
};

bool Provider_init_happy();              // friends w/ provider for ease of use
bool Provider_init_json();               // friends w/ provider for ease of use

/* Basic Test Data */
std::string street = "1234 n Street st";
std::string city = "Portland";
std::string state = "OR";
std::string zip = "97203";
std::string name = "John Smith";
std::string pid = "123456789";

Address a1(street, city, state, zip);
Provider prov(name, pid, a1);

nlohmann::json j = {
	{"name", name},
	{"pid", pid},
	{"street", street},
	{"city", city},
	{"state", state},
	{"zip", zip}
}

#endif // PROVIDER_TESTER_HPP