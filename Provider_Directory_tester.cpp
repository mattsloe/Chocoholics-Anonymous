#include "Provider_Directory_tester.hpp"


void Provider_Directory_tester::test_Provider_Directory_class() {
    Provider_Directory *p = nullptr;
    cout << endl;
    cout << "------------------------------------------";
    cout << "PROVIDER DIRECTORY TESTS STARTING..." << endl;

    cout << "Find Valid test ";
    (assert_test(default_constructor(p)));
    cout << "Find valid test    ";
    (assert_test(find_valid(p)));
    cout << "Find invalid test    ";
    (assert_test(find_invalid(p)));

    cout << "PROVIDER DIRECTORY TESTS COMPLETE" << endl;
    cout << "------------------------------------------";
    cout << endl;
}