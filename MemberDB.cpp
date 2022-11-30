//
// Created by Matt Loera on 11/16/22.
//

#include "MemberDB.hpp"

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
       std::cout<<"Cant open file!!"<<std::endl; //error
    }
    infile >> j;
    infile.close();
    init(j); //init with extracted json data
}

//destructor
//must delete all dynamically allocated memory
MemberDB::~MemberDB() {

}

int MemberDB::get_member(std::string mid, Member & m) {
    if (mid_map.find(mid) == mid_map.end()) return false;
    m.copy(*mid_map[mid]);
    return true;
}

int MemberDB::add_member(const Member & toAdd) {
    //create a copy of passed in member
    Member* m = new Member(toAdd);

    //add member
    add_member(m);

    return 1;
}

int MemberDB::delete_member(std::string mid) {
    //if member not in db return false
    if (mid_map.find(mid) == mid_map.end()) return false; //no matching member to delete
    //delete member from both maps
    Member* toDelete = mid_map[mid];
    if (mid_map.erase(mid) == 0){
        std::cout<< "Error: erasing from mid_map" << std::endl;
        return false;
    }
    if (name_map.erase(toDelete->name) == 0){
        std::cout<<"Error: erasing from name_map"<<std::endl;
        return false;
    }
    return true;
}

int MemberDB::add_member(Member * toAdd) {
    mid_map[toAdd->get_MID()] = toAdd;
    name_map[toAdd->get_name()] = toAdd;
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

//display inorder of name
int MemberDB::display_all() {
    print_map(" ",name_map);
    return mid_map.size();
}

void MemberDB::print_map(std::string comment, const std::map<std::string,Member*>& m) {
        std::cout << comment;
        // iterate
        for (const auto& [key, value] : m)
            std::cout << std::endl << *value << std::endl;

        std::cout << std::endl;
}


