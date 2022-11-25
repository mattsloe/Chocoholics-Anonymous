#include "Provider_Directory.hpp"

using namespace std;
using json = nlohmann::json;

// ----------------------- Provider Directory Implementation ---------------------------
/*
Provider_Directory::~Provider_Directory() {
    for (auto it = services.begin(); it != services.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
    // destruct map?
}
*/

void Provider_Directory::init(nlohmann::json j) {
    for (auto& elm: j.items()) {
        json object = elm.value();
        services.emplace(Service(object));
    }
}

void Provider_Directory::create_new_service() {
    string name;
    unsigned int sid;
    double fee;
    Service * service = nullptr;
    map<unsigned int, Service*&>::iterator new_service;

    cout << "Please enter a new name for the service to be provided: ";
    cin >> name; 
    // add verifcation 

    cout << "Please enter a new Service ID that has not been used in the past: ";
    cin >> sid;
    // add search to make sure it won't collide

    cout << "Lastly, please enter the fee for this service to be provided: ";
    cin >> fee;
    // add verifcation 

    service = new Service(name, sid, fee);
    services.emplace(sid, service);
}

void Provider_Directory::display() {
    for (auto it = services.begin(); it != services.begin(); it++) {
        it->second.display();
    }
}

void Provider_Directory::read_from_file() {
    // open file and load it into the map
    string file_name = "Services.json";
    json j;
    ifstream infile(file_name);
    if (!infile.is_open()) { 
        cerr << "Can't open Services file!!" << endl;
        exit(-24);
    }
    infile >> j;
    infile.close();
    init(j);
}

void Provider_Directory::write_to_file() {
    string file_name = "Services.txt";
    fstream out.open(file_name);

    json j_umap(this->services);
/*
    for (auto it = services.begin(); it != services.end(); it++) {
        out << it->second.to_string_exp();
    }
    */
}

string Provider_Directory::validate_service_code(unsigned int sID) {
    string out;
    auto val = services.find(sID);
    if (val == services.end()) {
        out = "INVALID SERVICE CODE";
    }
    out = val->second.get_name();
    return out;
}

bool Provider_Directory::get_service(unsigned int sID, Service *& service) {
    auto val = services.find(sID);
    if (val == services.end()) {
        // fail
        return false;
    }
    service = new Service(val->second);
    return true;
}

// --------------------------------------------------

// ----------------------- Service Implementation ---------------------------
Service::Service(json j) {
    /*
    set_name(j.value("name", "not found"));
    set_id(j.value("sID", "not found"));
    set_fee(j.value("fee", "not found"));
    */
    this->name = j.value("name", "not found");
    this->sID = j.value("sID", 0);
    this->fee = j.value("fee", 0.00);
}

Service::Service() : name(), sID(0), fee(0.0) {}

Service::Service(string name, unsigned int sID, double fee) : name(name), sID(sID), fee(fee) {}

Service::Service(const Service & s) : name(s.name), sID(s.sID), fee(s.fee) {} 

//Service & Service::operator = (const Service &s) {
void Service::operator = (const Service &s) {
    set_name(s.name);
    set_id(s.sID);
    set_fee(s.fee);
}

void Service::set_name(string name) {
    this->name = name;
}

void Service::set_id(unsigned int sID) {
    this->sID = sID;
}

void Service::set_fee(double fee) {
    this->fee = fee;
}

string Service::get_name() {
    return this->name;
}

string Service::get_sID() {
    return this->sID;
}

double Service::get_fee() {
    return this->fee;
}

string Service::to_string_exp() {
    string out;
    json j = {
        {"name", name},
        {"sID", sID},
        {"fee", fee}
    };
    out = j.dump(2);
    return out;
}

void Service::display() {
    cout << "Service Name: " << name << endl;
    cout << "Service ID Number: " << sID << endl;
    cout << "Service Fee: " << fee_output(this->fee) << endl;
}

// --------------------------------------------------

string fee_output(double x) {
    string out;
    out += "$";
    setprecision(3);
    out += x;
    //return ("%" + x);
    return out;
}