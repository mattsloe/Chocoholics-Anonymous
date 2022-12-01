//
// Created by Matt Loera on 11/16/22.
//

#include "MemberDB.hpp"

MemberDB::MemberDB(){
    this->filename = data_filename;
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

//initialized with json object
MemberDB::MemberDB(nlohmann::json j) {
    init(j);
}

//initialized with a file name

MemberDB::MemberDB(std::string filename) {
    this->filename = filename;
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
    using json = nlohmann::json;
    //write to file
    std::ofstream  out(filename);
    json j = json::array();
    for (auto value = name_map.begin(); value != name_map.end(); value++) {
        j.push_back(json::parse((value->second)->to_string_exp())); //push back member
    }
    out << j.dump(2);
    out.close();

    //delete memory
    for(auto value = mid_map.begin(); value != mid_map.end(); value++) {
        delete value->second;
    }
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
//        for (const auto& [key, value] : m)
        for(auto value = m.begin(); value != m.end(); value++)
            std::cout << std::endl << *(value->second) << std::endl;

        std::cout << std::endl;
}

int MemberDB::get(std::string mid, Member & retrieve) {
    Member m;
    if (!get_member(mid,m)) return false;
    retrieve.copy(*(mid_map[mid]));
    return 0;
}

int MemberDB::edit(std::string mid,const Member & toEmplace ) {
    Member * m = new Member();
    if (!get_member(mid,*m)) return false; //return false if member not found
    delete m;
    m = new Member(toEmplace);
    delete_member(mid);
    add_member(m);
    return true;
}

//run member report for each member
int MemberDB::run_member_reports(Provider_Directory& directory, Provider_Database& pDB) const {
    int flag = 1;
    for(auto value = name_map.begin(); value != name_map.end(); value++) {
        std::cout << "Generating Record for " << value->first << "..." ;
        if (value->second->run_member_report(directory,pDB))
            std::cout << "done";
        else flag = 0;
        std::cout << std::endl;
    }
    return flag;
}


