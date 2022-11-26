#include "Service_Record_tester.hpp"
using namespace std;

void Service_Record_tester::test_Service_Record_class() {
    Service_Record * sr = nullptr;
    cout << endl;
    cout << "------------------------------------------";
    cout << "SERVICE RECORD TESTS STARTING..." << endl;

    cout << "Default Constuctor test ";
    (assert_test(default_constructor(sr)));
    cout << "Copy Constuctor test    ";
    (assert_test(copy_constructor(sr)));
    cout << "JSON Constuctor test    ";
    (assert_test(json_constructor(sr)));
    cout << "Setting Date test       "; 
    (assert_test(setting_date(sr)));
    cout << "Setting sID test        "; 
    (assert_test(setting_sID(sr)));
    cout << "Setting mID test        "; 
    (assert_test(setting_mID(sr)));
    cout << "Setting pID test        "; 
    (assert_test(setting_pID(sr)));
    cout << "Setting comments test   "; 
    (assert_test(setting_comments(sr)));

    cout << "SERVICE RECORD TESTS COMPLETE" << endl;
    cout << "------------------------------------------";
    cout << endl;
}

void Service_Record_tester::create_SR(Service_Record *&s) {
    s = new Service_Record();
    // create json
}

bool Service_Record_tester::default_constructor(Service_Record *s) {
    s = new Service_Record();
    return (s == false) ? false : true;
}

bool Service_Record_tester::setting_date(Service_Record *s) {
    create_SR(s);

}

static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}