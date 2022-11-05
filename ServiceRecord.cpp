// FILE: ServiceRecord.cpp
// Author: Kobe Norcross
/*
    ~ Decription ~
    This is the implementation of the Service Records class.
*/

#include "ServiceRecord.h"
using namespace std;

ServiceRecord::ServiceRecord() : date(), sDate(), comments(), pID(0), mID(0), sID(0) {}

ServiceRecord::ServiceRecord(string date, string sDate, int pID, int mID, int sID, string comments) : date(date), sDate(sDate), comments(comments), pID(pID), mID(mID), sID(sID) {}


void display() {
    return;
}

void toJSON() {
    return;
}

// setters/getters
void ServiceRecord::set_date(std::string date) {
    this->date = date;
}

void ServiceRecord::set_sDate(std::string sDate) {
    this->sDate = sDate;
}

void ServiceRecord::set_comments(std::string comments) {
    this->comments = comments;
}

void ServiceRecord::set_pID(int pID) {
    this->pID = pID;
}

void ServiceRecord::set_mID(int mID) {
    this->mID = mID;
}

void ServiceRecord::set_sID(int sID) {
    this->sID = sID;
}

std::string ServiceRecord::get_date() {
    return this->date;
}

std::string ServiceRecord::get_sDate() {
    return this->sDate;
}

std::string ServiceRecord::get_comments() {
    return this->comments;
}

int ServiceRecord::get_pID() {
    return this->pID;
}

int ServiceRecord::get_mID() {
    return this->mID;
}

int ServiceRecord::get_sID() {
    return this->sID;
}