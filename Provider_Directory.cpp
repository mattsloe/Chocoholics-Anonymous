#include "Provider_Directory.hpp"

using namespace std;
using json = nlohmann::json;

// ----------------------- Service Implementation ---------------------------
Service::Service(json j) {
    set_name(j.value("name", "not found"));
    set_sID(j.value("sID", "not found"));
    set_fee(j.value("fee", 0.0));
}

Service::Service() : name(), sID(), fee(0.0) {}

Service::Service(string name, string sID, double fee) : name(name), sID(sID), fee(fee) {}

Service::Service(const Service & s) : name(s.name), sID(s.sID), fee(s.fee) {} 

void Service::operator = (const Service &s) {
    set_name(s.name);
    set_sID(s.sID);
    set_fee(s.fee);
}

bool Service::set_name(string name) {
    this->name = name.substr(0, 25);
    return true;
}

bool Service::set_fee(double fee) {
    this->fee = fee;
    return true;
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

// ----------------------- Provider Directory Implementation ---------------------------
Provider_Directory::Provider_Directory(string file_name) {
   read_from_file(file_name);
}

void Provider_Directory::init(nlohmann::json j) {
    for (auto& elm: j.items()) {
        json object = elm.value();
        Service service = (Service(object));
        services.emplace(service.get_sID(), service);
    }
}

void Provider_Directory::create_new_service() {
    bool valid = false;
    string name, sID;
    double fee;
    Service service = Service();

    while (!valid) {
        cout << "Please enter a new name for the service to be provided: ";
        cin >> name; 
        service.set_name(name);
        valid = true;
    }
    valid = false;

    while (!valid) {
        cout << "Please enter a new Service ID that has not been used in the past: ";
        cin >> sID;
        service.set_sID(sID);
        valid = true;
    }
    valid = false;

    while (!valid) {
        cout << "Lastly, please enter the fee for this service to be provided: ";
        cin >> fee;
        service.set_fee(fee);
        valid = true;
    }
    valid = false;

    services.emplace(sID, service);
}

void Provider_Directory::display() {
    for (auto it = services.begin(); it != services.begin(); it++) {
        it->second.display();
    }
}

void Provider_Directory::read_from_file(string file_name) {
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
    string file_name = "assets/services.json";
    fstream out;
    
    out.open(file_name);
    if (!out.is_open()) {
        cout << "Can't open Services file!!" << endl;
        return;
        exit(-25);
    }
    
    out << "{";
    for (auto it = services.begin(); it != services.end(); it++) {
        out << it->second.to_string_exp();
        if (it != services.end()) {
            out << "," << endl;
        }
    }
    out << "}";
}

string Provider_Directory::validate_service_code(string sID) {
    string out;
    auto val = services.find(sID);
    if (val == services.end()) {
        out = "INVALID SERVICE CODE";
    }
    out = val->second.get_name();
    return out;
}

bool Provider_Directory::get_service(string sID, Service *& service) {
    auto val = services.find(sID);
    if (val == services.end()) {
        // fail
        service = nullptr;
        return false;
    }
    service = new Service(val->second);
    return true;
}

string Provider_Directory::get_name(string sid) {
    auto service = services.find(sid);
    string name = service->second.get_name();
    return name;
}

string Provider_Directory::get_fee(string sid) {
    return fee_output(this->get_fee_d(sid));
}

double Provider_Directory::get_fee_d(string sid) {
    auto service = services.find(sid);
    return service->second.get_fee();
}
// --------------------------------------------------

string fee_output(double x) {
    string out;
    out += "$";
    out += to_string(x);
    return out;
}