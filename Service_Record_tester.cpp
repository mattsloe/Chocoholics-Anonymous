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
    s = new Service_Record(j);
}

bool Service_Record_tester::default_constructor(Service_Record *s) {
    s = new Service_Record();
    return (s == nullptr) ? false : true;
}

bool Service_Record_tester::copy_constructor(Service_Record *s) {
    bool compare = false;
    Service_Record * test = nullptr;
    string date = "123"
    , sDate = "234"
    , pID = "123456789"
    , mID = "123456789"
    , sID = "012345"
    , comment = "hi world";
    nlohmann::json j = {
    {"date",date},
    {"sDate",sDate},
    {"pID",pID},
    {"mID",mID},
    {"sID",sID},
    {"comments",comment}
    };

    create_SR(s);
    create_SR(test);

    if (s->get_date() == test->get_date()) 
        compare = true;
    else
        compare = false;
    if (s->get_sDate() == test->get_sDate()) 
        compare = true;
    else
        compare = false;
    if (s->get_pID() == test->get_pID()) 
        compare = true;
    else
        compare = false;
    if (s->get_mID() == test->get_mID()) 
        compare = true;
    else
        compare = false;
    if (s->get_sID() == test->get_sID()) 
        compare = true;
    else
        compare = false;
    if (s->get_comments() == test->get_comments()) 
        compare = true;
    else
        compare = false;

    return compare; 
}

bool Service_Record_tester::json_constructor(Service_Record *s) {
    create_SR(s);
}

bool Service_Record_tester::setting_date(Service_Record *s) {
    string date = "08/17/2019 07:17:57";
    create_SR(s);
    s->set_date(date);
    return (s->get_date() == date) ? true : false; 
}

bool Service_Record_tester::setting_sDate(Service_Record *s) {
    string date = "08/17/2019";
    create_SR(s);
    s->set_sDate(date);
    return (s->get_sDate() == date) ? true : false; 
}

static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}