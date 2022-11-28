#include "Provider_Directory_tester.hpp"

using namespace std;

void PD_tester::test_Provider_Directory_class() {
    Provider_Directory *p = nullptr;
    cout << endl;
    cout << "------------------------------------------";
    cout << "PROVIDER DIRECTORY TESTS STARTING..." << endl;

    cout << "File Constructor test";
    (assert_test(file_constructor(p)));
    cout << "Validate Service Code (Success) test ";
    (assert_test(validateID_success(p)));
    cout << "Validate Service Code (Failure) test ";
    (assert_test(validateID_fail(p)));

    cout << "PROVIDER DIRECTORY TESTS COMPLETE" << endl;
    cout << "------------------------------------------";
    cout << endl;
}

void PD_tester::create_PD(Provider_Directory *&p) {
    string file_name = "assets/services.json";
    p = new Provider_Directory(file_name);
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
    create_PD(p);
}

bool PD_tester::validateID_fail(Provider_Directory *p) {

}


static void assert_test(bool ret) {
    cout << ((ret == false) ? "FAIL" : "PASS") << endl;
}