#include "Service_Record.hpp"
using namespace std;

Service_Record::Service_Record(string date, string sDate, int pID, int mID, int sID, string comments) : 
date(date), sDate(sDate), pID(pID), mID(mID), sID(sID), comments(comments) {}

Service_Record::Service_Record(string json) {

}

void Service_Record::display() {

}

void toJSON() {

}