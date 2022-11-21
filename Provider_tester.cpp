// Ashton Sawyer 11/17
#include "provider.h"

using namespace::std;

void testProviderClass();
bool Provider_getPid_happy();
bool Provider_toFile_happy();
bool Provider_opEqual_match();
bool Provider_opEqual_noMatch();

void testAddressStruct();
bool Address_init_happy();
bool Address_init_badState();
bool Address_init_badZipLen();
bool Address_init_badZipChar();
bool Address_copyInit_happy();

// *********
// Provider Tests
// *********

void testProviderClass() {
	cout << "Testing Address" << endl;
	testAddressStruct();
	cout << "Finish Testing Address" << endl;

	cout << "Test 1: Init\tResult: " << ((Provider_init_happy()) ? "pass" : "fail") << endl;
	cout << "Test 2: Get PID\t Result: " << ((Provider_getPid_happy()) ? "pass" : "fail") << endl;
	cout << "Test 3: To File\t Result: " << ((Provider_toFile_happy()) ? "pass" : "fail") << endl;
	cout << "Test 4: Equal Operator Match\tResult: " << ((Provider_opEqual_match()) ? "pass" : "fail") << endl;
	cout << "Test 5: Equal Operator No Match\tResult: " << ((Provider_opEqual_noMatch()) ? "pass" : "fail") << endl;
	return;
}

bool Provider_init_happy() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	Provider prov("John Smith", 123456789, address);
	bool ret = true;

	if (prov.name != "John Smith") {
		cout << "\tError: Name initialized incorrectly" << endl;
		ret = false;
	}
	if (prov.pid != 123456789) {
		cout << "\tError: PID initialized incorrectly" << endl;
		ret = false;
	}

	return true;
	
}

bool Provider_init_maxPid() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	Provider prov("John Smith", 999999999, address);

	if (prov.pid != 999999999)
		return false;
	return true;
}

bool Provider_getPid_happy() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	Provider prov("John Smith", 123456789, address);

	if (prov.get_pid() != 123456789)
		return false;
	return true;
}

// unfinished
bool Provider_toFile_happy() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	Provider prov("John Smith", 123456789, address);
	
	string expected = "";
	if (prov.to_file() != expected)
		return false;
	return true;
}

bool Provider_opEqual_match() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	Provider prov("John Smith", 123456789, address);
	Provider prov2("John Smith", 123456789, address);

	if (!(prov == prov2))
		return false;
	return true;
}

bool Provider_opEqual_noMatch() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	Provider prov("John Smith", 123456789, address);
	Provider prov2("John Smith", 987654321, address);

	if (prov == prov2)
		return false;
	return true;
}

// *********
// Address Tests
// *********

void testAddressStruct() {
	cout << "Test 1: Init Happy\tResult: " << ((Address_init_happy()) ? "pass" : "fail") << endl;
	cout << "Test 2: Init Bad State\tResult: " << ((Address_init_badState()) ? "pass" : "fail") << endl;
	cout << "Test 3: Init Bad Zip Length\tResult: " << ((Address_init_badZipLen()) ? "pass" : "fail") << endl;
	cout << "Test 4: Init Bad Zip Characters\tResult: " << ((Address_init_badZipChar()) ? "pass" : "fail") << endl;
	cout << "Test 4: Copy Init\tResult: " << ((Address_copyInit_happy()) ? "pass" : "fail") << endl;
	return;
}

bool Address_init_happy() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	bool ret = true;

	if (address.street != "1234 n Street st") {
		cout << "\tError: Street not initialized correctly" << endl;
		ret = false;
	}
	if (address.city != "Portland") {
		cout << "\tError: City not initialized correctly" << endl;
		ret = false;
	}
	if (address.state != "OR") {
		cout << "\tError: State not initialized correctly" << endl;
		ret = false;
	}
	if (address.zip != "97203") {
		cout << "\tError: Zip not initialized correctly" << endl;
		ret = false;
	}

	return ret;
}

bool Address_init_badState() {
	Address address("1234 n Street st", "Portland", "OR", "97203");

	if (address.init_address("1234 n Street st", "Portland", "XRY", "97203"))
		return false;
	return true;

}

bool Address_init_badZipLen() {
	Address address("1234 n Street st", "Portland", "OR", "97203");

	if (address.init_address("1234 n Street st", "Portland", "OR", "972030") != -2)
		return false;
	return true;
}

bool Address_init_badZipChar() {
	Address address("1234 n Street st", "Portland", "OR", "97203");

	if (address.init_address("1234 n Street st", "Portland", "OR", "9720x") != -3)
		return false;
	return true;
}

bool Address_copyInit_happy() {

}