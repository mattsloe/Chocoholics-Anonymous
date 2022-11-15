#include "Service_Record.hpp"
using namespace std;

Service_Record::Service_Record(string date, string sDate, int pID, int mID, int sID, string comments) : 
date(date), sDate(sDate), pID(pID), mID(mID), sID(sID), comments(comments) {}

Service_Record::Service_Record(string json) {

}

void Service_Record::display() {
    cout << "Date: " << this->date << endl;
    cout << "Service Date: " << this->sDate << endl;
    cout << "Provider ID: " << this->pID << endl;
    cout << "Member ID: " << this->mID << endl;
    cout << "Service ID: " << this->sID << endl;
    cout << "Additional Comments: " << this->comments << endl;
    return;
}

void Service_Record::toJSON() {
    return;
}

// setters/getters
void Service_Record::set_date(std::string date) {
    this->date = date;
}

void Service_Record::set_sDate(std::string sDate) {
    this->sDate = sDate;
}

void Service_Record::set_comments(std::string comments) {
    this->comments = comments;
}

void Service_Record::set_pID(int pID) {
    this->pID = pID;
}

void Service_Record::set_mID(int mID) {
    this->mID = mID;
}

void Service_Record::set_sID(int sID) {
    this->sID = sID;
}

std::string Service_Record::get_date() {
    return this->date;
}

std::string Service_Record::get_sDate() {
    return this->sDate;
}

std::string Service_Record::get_comments() {
    return this->comments;
}

int Service_Record::get_pID() {
    return this->pID;
}

int Service_Record::get_mID() {
    return this->mID;
}

int Service_Record::get_sID() {
    return this->sID;
}