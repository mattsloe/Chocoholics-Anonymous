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

void SL_tester::create_SL(Service_Ledger *&s) {
    s = new Service_Ledger();
    Service_Record s1 = Service_Record(sr1);
    Service_Record s2 = Service_Record(sr2);
    Service_Record s3 = Service_Record(sr3);
    s->new_transaction(s1);
    s->new_transaction(s2);
    s->new_transaction(s3);
}

bool SL_tester::new_transaction_good_test(Service_Ledger* s) {
    Service_Record s1b, s1c;
    create_SL(s);

    s1b = Service_Record(sr1b);
    s1c = Service_Record(sr1c);
    s->new_transaction(s1b);
    s->new_transaction(s1c);

    
}

static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}