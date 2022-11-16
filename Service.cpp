#include "Service.hpp"

Service::Service() : name(), sID(0), fee(0.0) {}

Service::Service(string name, unsigned long sID, double fee) : name(name), sID(sID), fee(fee) {}

void Service::set_name(string name) {
    this->name = name;
}

void Service::set_id(unsigned long sID) {
    this->sID = sID;
}

void Service::set_fee(double fee) {
    this->fee = fee;
}

std::string Service::get_name() {
    return this->name;
}

void Service::display() {
    cout << "Service Name: " << name << endl;
    cout << "Service ID Number: " << sID << endl;
    cout << "Service Fee: " << fee_output(this->fee) << endl;
}

string fee_output(double x) {
    string out;
    out += "$";
    out += x;
    set_precision(3);
    //return ("%" + x);
    return out;
}