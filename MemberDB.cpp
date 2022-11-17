//
// Created by Matt Loera on 11/16/22.
//

#include "MemberDB.h"

MemberDB::MemberDB() = default;

//initialized with json object
MemberDB::MemberDB(nlohmann::json j) {
    init(j);
}

//initialized with a file name

MemberDB::MemberDB(std::string filename) {
    nlohmann::json j;
    std::ifstream infile(filename);
    if (!infile.is_open())
    {
       //error
    }
    infile >> j;
    infile.close();
    init(j); //init with extracted json data
}

//destructor
//must delete all dynamically allocated memory
MemberDB::~MemberDB() {

}

int MemberDB::get_member(std::string mid, Member &) {
    return 0;
}

int MemberDB::add_member(const Member &) {
    return 0;
}

int MemberDB::delete_member(std::string mid) {
    return 0;
}

int MemberDB::add_member(Member *) {
    return 0;
}

void MemberDB::init(nlohmann::json j) {
    using json = nlohmann::json;

    //j is an array of Member objects
    //elm is each Member in the array
    for (auto& elm: j.items()) {
        json object = elm.value();
        add_member(new Member(object)); //add member by object
    }
}


