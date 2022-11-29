#include "Service_Ledger_tester.hpp"

using namespace std;

void SL_tester::test_Service_Ledger_class() {
    Service_Ledger * s = nullptr;

    cout << "SERVICE LEDGER TESTS STARTING..." << endl;
    cout << "New Transaction good path test                  ";
    (assert_test(new_transaction_good_test(s)));
    cout << "New Transaction bad path test                   ";
    (assert_test(new_transaction_bad_test(s)));
    /*
    cout << "Generate EFT test                               ";
    (assert_test(generate_EFT_test(s)));
    cout << "Generate APR test                               ";
    (assert_test(generate_APR_test(s)));
    */
    cout << "SERVICE LEDGER TESTS COMPLETE" << endl;
}

static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}