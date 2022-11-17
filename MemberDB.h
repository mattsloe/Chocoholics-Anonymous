//
// Created by Matt Loera on 11/16/22.
// Note: adding a member object to this structure involves hashing it to both hash tables
// Note: no validation is done on json datafiles. Invalid data or datafiles will cause undefined behavior
// ToDo: Create data structure
// ToDo: Implement file import/export for persistence
// ToDo: Implement protocol for accessing/editing Members
// ToDo: Implement Member report protocol
//

#ifndef CHOCAHOLICS_ANONYMOUS_SOFTWARE_MEMBERDB_H
#define CHOCAHOLICS_ANONYMOUS_SOFTWARE_MEMBERDB_H
#include <ios>
#include <unordered_map>
#include <fstream>

#include "Member.h"
#include "json.hpp"

class MemberDB {
public:
    std::unordered_map<std::string,Member*> mid_map; //maps Members to MID
    std::map<std::string ,Member*> name_map; //maps members by Name. Ordered for easy alphabetical access

    /*Constructors*/
    MemberDB(); //default
    explicit MemberDB(nlohmann::json); //initialized to json object
    explicit MemberDB(std::string filename); //initialized to data file
    ~MemberDB(); //destructor

    /*Interface*/

    int get_member(std::string mid,Member&);
    int add_member(const Member&);
    int delete_member(std::string mid);
    int display_all(); //returns number of members

    /*Overloaded Operators*/
private:
    int add_member(Member*);
    void init(nlohmann::json); //initialize with json object

};


#endif //CHOCAHOLICS_ANONYMOUS_SOFTWARE_MEMBERDB_H
