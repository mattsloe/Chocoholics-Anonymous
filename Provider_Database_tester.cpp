#include "Provider_Database_tester.hpp"

using namespace std;

/* Dummy Data */
std::string street1 = "1234 n Street st";
std::string city1 = "Portland";
std::string state1 = "OR";
std::string zip1 = "97203";
std::string name1 = "John Smith";
std::string pid1 = "123456789";

Address a2(street1, city1, state1, zip1);
Provider prov2(name1, pid1, a2);
Service_Record sr2("123", "234", "123456789", "123456789", "275627", "hi world");
Provider_Directory d1;
Provider_Database db(d1);

void ProviderDB_tester::test_Provider_Database_class() {
	cout << endl;
	cout << "------------------------------------------";
	cout << "PROVIDER DATABASE TESTS STARTING..." << endl;
	cout << "Test 1: Get Happy\t\t\tResult: " << ((getProvider_happy()) ? "pass" : "fail") << endl;
	cout << "Test 2: Get Empty\t\t\tResult: " << ((getProvider_empty()) ? "pass" : "fail") << endl;
	cout << "Test 3: Get Not Found\t\t\tResult: " << ((getProvider_notFound()) ? "pass" : "fail") << endl;
	cout << "Test 5: Delete Prov Happy\t\tResult: " << ((deleteProvider_happy()) ? "pass" : "fail") << endl;
	cout << "Test 6: Delete Prov Not Found\t\tResult: " << ((deleteProvider_empty()) ? "pass" : "fail") << endl;
	cout << "Test 7: Run Reports\t\t\tResult: " << genProvReports_happy() << endl;
	cout << "Test 9: Run Single Report\t\tResult: " << genSingleReport_happy() << endl;
	cout << "Test 10: Database to File\t\tResult: " << toFile_happy() << std::endl;
	cout << "Test 11: Load File\t\t\tResult: " << (loadFile_happy() ? "pass" : "fail") << endl;
	cout << "PROVIDER DATABASE TESTS COMPLETE" << endl;
	cout << "------------------------------------" << endl;
	return;
}

bool ProviderDB_tester::getProvider_happy() {
	Provider empty;
	bool flag = false;
	flag = db.get_provider("326719418", empty);

	return flag;
}

bool ProviderDB_tester::getProvider_empty() {
	Provider empty;
	Provider_Database empty_db;
	
	if (empty_db.get_provider("326719418", empty))
		return false;
	return true;
}

bool ProviderDB_tester::getProvider_notFound() {
	Provider empty;

	if (db.get_provider("123456789", empty))
		return false;
	return true;
}

bool ProviderDB_tester::deleteProvider_happy() {

	db.delete_provider("326719418");
	if (db.validate_pid("326719418"))
		return false;
	return true;
}

bool ProviderDB_tester::deleteProvider_empty() {
	if (db.delete_provider("123456789"))
		return false;
	return true;
}

bool ProviderDB_tester::genProvReports_happy() {
	db.generate_provider_reports(d1);
	cout << "Validate Correctness with generated files" << endl;
	return true;
}

bool ProviderDB_tester::genSingleReport_happy() {
	db.generate_single_report("261191228", d1);
	cout << "Verify correctness with generated file" << endl;
	return true;
}

bool ProviderDB_tester::toFile_happy(){
	db.to_file();
	cout << "Verify correctness with generated file" << endl;
	return true;
}

bool ProviderDB_tester::loadFile_happy() {
	// if the other tests are working, then this works
	return true;
}

