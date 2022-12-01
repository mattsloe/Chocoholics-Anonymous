//
// Created by Matt Loera on 11/14/22.
// Notes: this class relies on other components for data validation. Any data inputs longer than the max
//        will be chopped to fit the spec for the data field.
// ToDo: implement comparison operators
// ToDo: implement to_string_exp for exporting class data

#ifndef CHOCANDEV_MEMBER_H
#define CHOCANDEV_MEMBER_H
#include <string>
#include <iostream>
#include <ctime>
#include "json.hpp"
#include "Provider_Directory.hpp"
#include "Service_Record.hpp"
#include "Provider_Database.hpp"

class Member {
public:
    std::string name;
    std::string mid; //member id
    std::string address; //street address
    std::string city;
    std::string state;
    std::string zip;
    bool accountActive; //true means account active

    /*Constructors*/
    Member();
    Member(const Member&);
    Member(std::string  name,std::string  mid, bool accountActive,std::string address, std::string  city, std::string state, std::string zip);
    Member(nlohmann::json); //initialization from json string
    ~Member();

    /*Interface*/

    //runs the Member report and saves to /docs/member_reports/memberName_currentDate.txt
    //requires a reference to the current Provider_Directory to be passed in to run the report
    int run_member_report(Provider_Directory &, Provider_Database&)const;

    //@pre
    //@post returns name
    std::string  get_name()const;

    //@pre
    //@post returns MID
    std::string get_MID()const;

    //@pre
    //@post returns address in string form [City State,zip]
    std::string get_address()const;
    //@pre
    //@post returns account active status (false means account suspended)
    int is_active()const;

    //@pre
    //@post returns string representation of Member
     std::string to_string()const;

    //@pre
    //@post returns string representation of Member formatted for file export
    std::string  to_string_exp()const;

    //@pre
    //@post edits member name. Return 1 for success
    int set_name(const std::string&);

    //@pre
    //@post edits member MID. Return 1 for success
    int set_MID(const std::string&);

    //@pre
    //@post edits member street address. Max 25 chars. Return 1 for success
    int set_address(const std::string&);

    //@pre
    //@post edits city. Max 12 chars Return 1 for success
    int set_city(const std::string&);

    //@pre
    //@post edits state. Chops off any more than 2 characters Return 1 for success
    int set_state(const std::string&);

    //@pre
    //@post edits zipcode. Chops off any more than 5 characters Return 1 for success
    int set_zip(const std::string&);

    //@pre
    //@post toggles whether Member is active or suspended. returns value of accountActive
    bool toggle_active();

    //safe copies Member
    void copy(const Member&);

    //adds a service for the member
    int add_service(const Service_Record&);



    /*Overloaded Operators*/
    friend bool operator==(const Member& m1, const Member& m2); //compare by mid
    friend bool operator<(const Member& m1, const Member& m2); //compare by mid
    friend std::ostream& operator << (std::ostream &out, const Member& m);


private:
    void init();
    std::vector<Service_Record> serviceList;



};


#endif //CHOCANDEV_MEMBER_H
