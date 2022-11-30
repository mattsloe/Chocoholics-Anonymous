#ifndef PROVIDER_TESTER_HPP
# define PROVIDER_TESTER_HPP

#include "Provider.hpp"

using namespace std;

class Provider_tester {
	public: 
		Provider_tester() = default;

		static void test_provider_class();
		static void test_address_struct();              // called by test_provider_class()

		/* Provider Tests - unfinished */
		static bool Provider_getPid_happy();
		static bool Provider_toString_happy();
		static bool Provider_toFile_happy();            // uses Service_Record fxn 
		static bool Provider_loadFile_happy();          // uses Service_Record + Provider_Directory
		static bool Provider_opEqual_match();
		static bool Provider_opEqual_noMatch();
		static bool Provider_runReport_happy();         // uses Service_Record fxn
		static bool Provider_runManagerReport_happy();  // uses Service_Record fxn
		static bool Provider_addService_happy();


		/* Address Tests - finished */
		static bool Address_init_happy();
		static bool Address_set_badState();
		static bool Address_set_badZipLen();
		static bool Address_set_badZipChar();
		static bool Address_copy_happy();

};

bool Provider_init_happy();              // friends w/ provider for ease of use
bool Provider_init_json();               // friends w/ provider for ease of use

/* Generic Test Data */
std::string street = "1234 n Street st";
std::string city = "Portland";
std::string state = "OR";
std::string zip = "97203";
std::string name = "John Smith";
std::string pid = "123456789";

Address a1(street, city, state, zip);
Provider prov(name, pid, a1);
Service_Record sr("123", "234", "123456789", "123456789", "012345", "hi world");
Provider_Directory d("assets/services.json"); 

nlohmann::json j_obj = {
	{"name", name},
	{"pid", pid},
	{"street", street},
	{"city", city},
	{"state", state},
	{"zip", zip},
	{"serviceList", "[]"}
};


#endif // PROVIDER_TESTER_HPP