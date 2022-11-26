#include "Provider_Directory_tester.hpp"

using namespace std;

void PD_tester::test_Provider_Directory_class() {
    Provider_Directory *p = nullptr;
    cout << endl;
    cout << "------------------------------------------";
    cout << "PROVIDER DIRECTORY TESTS STARTING..." << endl;

    cout << "Find Valid test ";
    (assert_test(find_valid(p)));
    cout << "Find invalid test    ";
    (assert_test(find_invalid(p)));

    cout << "PROVIDER DIRECTORY TESTS COMPLETE" << endl;
    cout << "------------------------------------------";
    cout << endl;
}

bool PD_tester::find_valid(Provider_Directory *p) {

}

bool PD_tester::find_invalid(Provider_Directory *p) {

}


static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}