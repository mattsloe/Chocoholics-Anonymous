#include "Service_Record_tester.hpp"
using namespace std;

void Service_Record_tester::test_Service_Record_class() {
    Service_Record * sr = nullptr;
    cout << endl << endl;
    cout << "SERVICE RECORD TESTS STARTING..." << endl;

    cout << "Default Constuctor test ";
    (assert_test(default_constructor(sr)));
    delete_SR(sr);

    cout << "Copy Constuctor test    ";
    (assert_test(copy_constructor(sr)));
    delete_SR(sr);

    cout << "JSON Constuctor test    ";
    (assert_test(json_constructor(sr)));
    delete_SR(sr);

    cout << "Setting Date test       "; 
    (assert_test(setting_date(sr)));
    delete_SR(sr);
    
    cout << "Setting sID test        "; 
    (assert_test(setting_sID(sr)));
    delete_SR(sr);

    cout << "Setting mID test        "; 
    (assert_test(setting_mID(sr)));
    delete_SR(sr);

    cout << "Setting pID test        "; 
    (assert_test(setting_pID(sr)));
    delete_SR(sr);

    cout << "Setting comments test   "; 
    (assert_test(setting_comments(sr)));
    delete_SR(sr);

    cout << "SERVICE RECORD TESTS COMPLETE";
    cout << endl << endl;
}

void Service_Record_tester::create_SR(Service_Record *&s) {
    s = new Service_Record(j);
}

void Service_Record_tester::delete_SR(Service_Record*& s) {
    if (s == nullptr) 
        return
    delete s;
    s = nullptr;
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

    delete_SR(s);
    delete_SR(test);

    return compare; 
}

bool Service_Record_tester::json_constructor(Service_Record *s) {
    bool compare = false;

    create_SR(s);

    if (s->get_date() == test_date) 
        compare = true;
    else
        compare = false;
    if (s->get_sDate() == test_sDate)
        compare = true;
    else
        compare = false;
    if (s->get_pID() == test_pID) 
        compare = true;
    else
        compare = false;
    if (s->get_mID() == test_mID)
        compare = true;
    else
        compare = false;
    if (s->get_sID() == test_sID) 
        compare = true;
    else
        compare = false;
    if (s->get_comments() == test_comment) 
        compare = true;
    else
        compare = false;

    return compare;
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

bool Service_Record_tester::setting_pID(Service_Record *s) {
    string id = "123456789";
    create_SR(s);
    s->set_pID(id);
    return (s->get_pID() == id) ? true : false;
}

bool Service_Record_tester::setting_mID(Service_Record *s) {
    string id = "123456789";
    create_SR(s);
    s->set_pID(id);
    return (s->get_mID() == id) ? true : false;
}

bool Service_Record_tester::setting_sID(Service_Record *s) {
    string id = "123456";
    create_SR(s);
    s->set_sID(id);
    return (s->get_sID() == id) ? true : false;
}

bool Service_Record_tester::setting_comments(Service_Record *s) {
    string comment = "hi, what is good in the neighborhood?";
    create_SR(s);
    s->set_comments(comment);
    return (s->get_comments() == comment) ? true : false;
}

static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}