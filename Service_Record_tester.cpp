#include "Service_Record_tester.h"
using namespace std;

static void Service_Record::test_Service_Record_class() {
    Server_Record * sr = nullptr;
    cout << endl;
    cout << "------------------------------------------"
    cout << "SERVICE RECORD TESTS STARTING..." << endl;
    cout << "Default Constuctor test " <<  (assert_tests(default_constructor(sr)));
    cout << "Copy Constuctor test    " <<  (assert_tests(copy_constructor(sr)));
    cout << "JSON Constuctor test    " <<  (assert_tests(json_constructor(sr)));
    cout << "Setting Date test       " << (assert_tests(setting_date(sr)));
    cout << "Setting sID test        " << (assert_tests(setting_sID(sr)));
    cout << "Setting mID test        " << (assert_tests(setting_mID(sr)));
    cout << "Setting pID test        " << (assert_tests(setting_pID(sr)));
    cout << "Setting comments test   " << (assert_tests(setting_comments(sr)));
    cout << "SERVICE RECORD TESTS COMPLETE" << endl;
    cout << "------------------------------------------"
    cout << endl;
}

static void create_SR(Service_Record *& s) {
    s = new Service_Record();
}

static bool setting_date(test_Service_Record_class * sr) {
    create_SR(sr);

}

static void assert_tests(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}