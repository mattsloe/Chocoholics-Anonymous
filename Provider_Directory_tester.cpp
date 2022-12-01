#include "Provider_Directory_tester.hpp"

using namespace std;

void PD_tester::test_Provider_Directory_class() {
    Provider_Directory *p = nullptr;
    cout << endl;
    cout << "PROVIDER DIRECTORY TESTS STARTING..." << endl;
    cout << "File Constructor test                  ";
    (assert_test(file_constructor(p)));
    delete_PD(p);

    cout << "Validate Service Code (Success) test   ";
    (assert_test(validateID_success(p)));
    delete_PD(p);

    cout << "Validate Service Code (Failure) test   ";
    (assert_test(validateID_fail(p)));
    delete_PD(p);

    cout << "PROVIDER DIRECTORY TESTS COMPLETE";
    cout << endl;
}

void PD_tester::create_PD(Provider_Directory *&p) {
    p = new Provider_Directory();
    p = new Provider_Directory(file_name);
}

void PD_tester::delete_PD(Provider_Directory*& p) {
    if (!p)
        return;
    delete p;
    p = nullptr;
}

bool PD_tester::file_constructor(Provider_Directory *p) {
    string id = "903295";
    Service * service = nullptr;

    create_PD(p);
    p->get_service(id, service);

    // data retrieved from line 21 of services.json
    if (service->get_name() == "Okuma"
        && service->get_sID() == id 
        && service->get_fee() == 770.72)
        return true;

    return false;
}

bool PD_tester::validateID_success(Provider_Directory *p) {
    string id = "903295";
    string out;
    create_PD(p);
    out = p->validate_service_code(id);
    if (out == "Okuma")
        return true;
    return false;
}

bool PD_tester::validateID_fail(Provider_Directory *p) {
    string id = "000000";
    string out;
    create_PD(p);
    out = p->validate_service_code(id);
    if (out == "INVALID SERVICE CODE")
        return true;
    return false;
}


static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}