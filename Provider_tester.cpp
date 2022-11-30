// Ashton Sawyer 11/17
#include "Provider_tester.hpp"

// *********
// Provider Tests
// *********

void Provider_tester::test_provider_class() {
	cout << endl;
	cout << "------------------------------------------";
	cout << "PROVIDER TESTS STARTING..." << endl;
	cout << "-----ADDRESS TESTS STARTING..." << endl;
	testAddressStruct();
	cout << "-----ADDRESS TESTS COMPLETE" << endl;

	cout << "Test 1: Init\tResult: " << ((Provider_init_happy()) ? "pass" : "fail") << endl;
	cout << "Test 2: Get PID\t Result: " << ((Provider_getPid_happy()) ? "pass" : "fail") << endl;
	cout << "Test 3: To File\t Result: " << ((Provider_toFile_happy()) ? "pass" : "fail") << endl;
	cout << "Test 4: Equal Operator Match\tResult: " << ((Provider_opEqual_match()) ? "pass" : "fail") << endl;
	cout << "Test 5: Equal Operator No Match\tResult: " << ((Provider_opEqual_noMatch()) ? "pass" : "fail") << endl;
	cout << "------------------------------------" << endl;
	return;
}

bool Provider_tester::Provider_init_happy() {
	bool ret = true;

	if (prov.name != name) {
		cout << "\tError: Name initialized incorrectly" << endl;
		ret = false;
	}
	if (prov.pid != pid) {
		cout << "\tError: PID initialized incorrectly" << endl;
		ret = false;
	}

	return ret;
	
}

bool Provider_tester::Provider_init_json() {
	Provider p(j);

	bool ret = true;

	if (p.name != name) {
		cout << "\tError: Name initialized incorrectly" << endl;
		ret = false;
	}
	if (p.pid != pid) {
		cout << "\tError: PID initialized incorrectly" << endl;
		ret = false;
	}
	if (p.address.street != street || p.address.city != city ||
		p.address.state != state || p.address.zip != zip) {
		cout << "\tError: Address initialized incorrectly" << endl;
		ret = false;
	}

	return ret;

}

bool Provider_tester::Provider_getPid_happy() {
	if (prov.get_pid() != pid)
		return false;
	return true;
}

bool Provider_tester::Provider_toString_happy() {
	std::string expected = "John Smith - 123456789\n1234 n Ivanhoe st\nPortland, OR 97203\n";

	if (prov.to_string() != expected)
		return false;
	return true;
}

// unfinished
bool Provider_tester::Provider_toFile_happy() {
	string expected = "{\"name\": \"John Smith\", \"pid\": \"123456789\", \"street\": \"9427 n Ivnanhoe st\", \"city\": \"Portland\", \"state\": \"OR\", \"zip\": \"97203\"}"; ;

	if (prov.to_file() != expected)
		return false;
	return true;
}

bool Provider_tester::Provider_loadFile_happy() {

}

bool Provider_tester::Provider_opEqual_match() {
	Provider p(name, pid, a1);

	if (!(prov == p))
		return false;
	return true;
}

bool Provider_tester::Provider_opEqual_noMatch() {
	Provider p(name, pid, a1);
	p.edit_provider("987654321");

	if (prov == prov2)
		return false;
	return true;
}

bool Provider_tester::Provider_opLess_less() {


}

bool Provider_tester::Provider_opLess_more() {

}

bool Provider_tester::Provider_runReport_happy() {

}

bool Provider_tester::Provider_runManagerReport_happy() {

}

bool Provider_tester::Provider_addService_happy() {

}

bool Provider_tester::Provider_removeService_happy() {

}

bool Provider_tester::Provider_removeService_empty() {

}

bool Provider_tester::Provider_clearService_happy() {

}

// *********
// Address Tests
// *********

void Provider_tester::test_address_struct() {
	cout << "\tTest 1: Init Happy\tResult: " << ((Address_init_happy()) ? "pass" : "fail") << endl;
	cout << "\tTest 2: Init Bad State\tResult: " << ((Address_set_badState()) ? "pass" : "fail") << endl;
	cout << "\tTest 3: Init Bad Zip Length\tResult: " << ((Address_set_badZipLen()) ? "pass" : "fail") << endl;
	cout << "\tTest 4: Init Bad Zip Characters\tResult: " << ((Address_set_badZipChar()) ? "pass" : "fail") << endl;
	cout << "\tTest 5: Copy Init\tResult: " << ((Address_copy_happy()) ? "pass" : "fail") << endl;
	return;
}

bool Provider_tester::Address_init_happy() {
	Address address("1234 n Street st", "Portland", "OR", "97203");
	bool ret = true;

	if (address.street != "1234 n Street st") {
		cout << "\t\tError: Street not initialized correctly" << endl;
		ret = false;
	}
	if (address.city != "Portland") {
		cout << "\t\tError: City not initialized correctly" << endl;
		ret = false;
	}
	if (address.state != "OR") {
		cout << "\t\tError: State not initialized correctly" << endl;
		ret = false;
	}
	if (address.zip != "97203") {
		cout << "\t\tError: Zip not initialized correctly" << endl;
		ret = false;
	}

	return ret;
}

bool Provider_tester::Address_set_badState() {
	Address address("1234 n Street st", "Portland", "OR", "97203");

	if (address.set_state("XRY"))
		return false;
	return true;

}

bool Provider_tester::Address_set_badZipLen() {
	Address address("1234 n Street st", "Portland", "OR", "97203");

	if (address.set_zip("972030"))
		return false;
	return true;
}

bool Provider_tester::Address_set_badZipChar() {
	if (address.set_zip("9720x"))
		return false;
	return true;
}

bool Provider_tester::Address_copy_happy() {
	Address a2;

	a2.copy_address(a1);
	if (!(a2.street == a1 && a2.city == a1.city && a2.state == a1.state && a2.zip == a1.zip)) {
		cout << "\t\tError: Not Copied Correctly" << endl;
		return false;
	}
	return true;

}