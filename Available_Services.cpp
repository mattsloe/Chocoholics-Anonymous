#include "Available_Services.hpp"
using namespace std;

Available_Services::~Available_Services() {
    for (auto it = services.begin(); it != services.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
    // destruct map?
}

void Available_Services::create_new_service() {
    // input data
    // add it to the data structure
}

void Available_Services::display() {
    for (auto it = services.begin(); it != services.begin(); it++) {
        it->second->display();
    }
}

void Available_Services::read_from_file(string provider_name) {
    // open file and load it into the map
}

void Available_Services::write_to_file(string provider_name) {

}

string Available_Services::validate_service_code(unsigned long sID) {
    string out;
    auto val = services.find(sID);
    if (val == services.end()) {
        out = "INVALID SERVICE CODE";
    }
    out = val->second->get_name();
    return out;
}

Service *&Available_Services::get_service(unsigned long sID) {
    Service *ret = new Service;
    auto val = services.find(sID);
    if (val == services.end()) {
        // fail
    }
    ret = val->second;
    return ret;
}