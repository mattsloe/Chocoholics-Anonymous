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
    bool valid = false;
    string name, sID;
    double fee;
    Service * service = new Service();

    while (!valid) {
        cout << "Please enter a new name for the service to be provided: ";
        cin >> name; 
        service->set_name(name);    
    }
    valid = false;

    while (!valid) {
        cout << "Please enter a new Service ID that has not been used in the past: ";
        cin >> sID;
        service->set_sID(sID);
    }
    valid = false;

    while (!valid) {
        cout << "Lastly, please enter the fee for this service to be provided: ";
        cin >> fee;
    }
    valid = false;

    services.emplace(sID, service);
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

Service::Service() : name(""), sID(""), fee(0.0) {}

Service::Service(string name, string sID, double fee) : name(name), sID(sID), fee(fee) {}

Service::Service(const Service & s) : name(s.name), sID(s.sID), fee(s.fee) {} 

//Service & Service::operator = (const Service &s) {
void Service::operator = (const Service &s) {
    set_name(s.name);
    set_sID(s.sID);
    set_fee(s.fee);
}

bool Service::set_name(string name) {
    if (name.length() > 25) {
        cout << "Invalid Service name!" << endl;
        return false;
    }
    this->name = name.substr(0, 25);
    return true;
}

bool Service::set_fee(double fee) {
    this->fee = fee;
}

bool Service::set_sID(const string& s) {
    if (s.length() != 6 || !all_of(s.begin(),s.end(),::isdigit)) { //make sure s represents a number
       cout<< "Invalid service code!" << endl;
       return false;
    }
    sID = s;
    return true;
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