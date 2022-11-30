#include "Provider_Database_tester.hpp"

using namespace std;

/* Dummy Data */
std::string street = "1234 n Street st";
std::string city = "Portland";
std::string state = "OR";
std::string zip = "97203";
std::string name = "John Smith";
std::string pid = "123456789";
std::string filename = "assets/test-providers.json";

Address a1(street, city, state, zip);
Provider prov(name, pid, a1);
Service_Record sr("123", "234", "123456789", "123456789", "012345", "hi world");
Provider_Directory d("assets/services.json");
//Provider_Database db(filename, d);

void ProviderDB_tester::test_Provider_Database_class() {
	cout << endl;
	cout << "------------------------------------------";
	cout << "PROVIDER DATABASE TESTS STARTING..." << endl;
	cout << "Test 1: Get Happy\t\t\t\tResult: " << ((getProvider_happy()) ? "pass" : "fail") << endl;
	cout << "Test 2: Get Empty\t\t\t\tResult: " << ((getProvider_empty()) ? "pass" : "fail") << endl;
	cout << "Test 3: Get Not Found\t\t\t\tResult: " << ((getProvider_notFound()) ? "pass" : "fail") << endl;
	cout << "Test 4: Add Prov\t\tResult: " << ((addProvider_happy()) ? "pass" : "fail") << endl;
	cout << "Test 5: Delete Prov Happy\t\tResult: " << ((deleteProvider_happy()) ? "pass" : "fail") << endl;
	cout << "Test 6: Delete Prov Not Found\t\t\tResult: " << ((deleteProvider_empty()) ? "pass" : "fail") << endl;
	cout << "Test 7: Run Reports\t\t\tResult: " << genProvReports_happy() << endl;
	cout << "Test 8: Run Manager Report\t\tResult: " << genManagerReports_happy() << endl;
	cout << "Test 9: Run Single Report\t\tResult: " << genSingleReport_happy() << endl;
	cout << "Test 10: Database to File\t\tResult: " << toFile_happy() << std::endl;
	cout << "Test 11: Load File\t\t\tResult: " << (loadFile_happy() ? "pass" : "fail") << endl;
	cout << "PROVIDER DATABASE TESTS COMPLETE" << endl;
	cout << "------------------------------------" << endl;
	return;
}

bool ProviderDB_tester::getProvider_happy() {
	return false;
}

bool ProviderDB_tester::getProvider_empty() {
	return false;
}

bool ProviderDB_tester::getProvider_notFound() {
	return false;
}

bool ProviderDB_tester::addProvider_happy() {
	return false;
}

bool ProviderDB_tester::deleteProvider_happy() {
	return false;
}

bool ProviderDB_tester::deleteProvider_empty() {
	return false;
}

bool ProviderDB_tester::genProvReports_happy() {
	return true;
}

bool ProviderDB_tester::genManagerReports_happy() {
	return true;
}

bool ProviderDB_tester::genSingleReport_happy() {
	return true;
}

bool ProviderDB_tester::toFile_happy(){
	return true;
}

bool ProviderDB_tester::loadFile_happy() {
	return false;
}

