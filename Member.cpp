//
// Created by Matt Loera on 11/14/22.
//

#include "Member.h"

Member::Member() {
   // init();
}

Member::Member(std::string name,std::string mid, bool accountActive,std::string address, std::string city, std::string state, std::string zip):
name(name),mid(mid),accountActive(accountActive),address(address),city(city), state(state), zip(zip)
{

}

bool operator==(const Member &m1, const Member &m2) {
    if ((m1.mid.compare(m2.mid)) == 0){
        return true;
    }
    return false;
}

bool operator<(const Member &m1, const Member &m2) {
    if ((m1.mid.compare(m2.mid)) > 0) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &out, const Member &m) {
    out << m.to_string();
    return out;
}

Member::~Member() = default;

std::string Member::get_name() const {
    return name;
}

std::string Member::get_MID() const {
    return mid;
}

//whole address formatted to string
std::string Member::get_address() const {
    std::string  out = address + " " +city + " " + state + ", " + zip;
    return out;
}

int Member::is_active() const {
    return accountActive;
}

//Format:
//[Name] - [MID]
//Account Active: [y/n]
//[Street Addr]
//[City] [ST], [zip]
std::string Member::to_string()const {
    std::string out = name + " - " + mid + "\nAccount Active: ";
    if (accountActive) out += "yes\n";
    else out += "no\n";
    out+= address + '\n';
    out += city +" "+ state +", "+ zip;
    return out;

}

//decide on format for this
std::string Member::to_string_exp()const {
    using json = nlohmann::json;
    std::string  s;

    //create json object
    json  j = {
            {"name",name},
            {"mid",mid},
            {"address",address},
            {"city",city},
            {"state",state},
            {"zip",zip},
            {"accountActive",accountActive}
    };
    s = j.dump(2); // the 2 is number of spaces for indent
    return s;
}

//max length 25
int Member::set_name(const std::string& n) {
    name = n.substr(0,25);
    return 1;
}

//max length 25
int Member::set_address(const std::string& a) {
    address = a.substr(0,25);
    return 1;
}

//max length 14
int Member::set_city(const std::string& c) {
    city = c.substr(0,14);
    return 1;
}

//length exactly 2
int Member::set_state(const std::string& s) {
    if (s.length() != 2 ){
        std::cout << "Invalid state!" << std::endl;
        return 0;
    }
    state = s;
    return 1;
}

//length exactly 5
int Member::set_zip(const std::string& z) {
    if (z.length()!=5 || !std::all_of(z.begin(),z.end(),::isdigit)) { //check if z represents a number
        std::cout<<"Invalid zipcode!" <<std::endl;
        return 0;
    }
    zip = z;
    return 1;
}

//flip accountActive. Return current status
bool Member::toggle_active() {
    accountActive = !accountActive;
    return accountActive;

}

void Member::init() {
    //get info from user
    std::string  tmp;
    bool flag = false;
    accountActive = true;
    while(!flag) {
        std::cout << "Name: ";
        std::getline(std::cin,tmp);
        flag = set_name(tmp);
    }
    flag = false;
    while(!flag){
        std::cout << "MID: ";
        std::getline(std::cin,tmp);
        flag = set_MID(tmp);
    }
    flag = false;
    while(!flag){
        std::cout << "Street Address: ";
        std::getline(std::cin,tmp);
        flag = set_address(tmp);
    }
    flag = false;
    while(!flag){
        std::cout << "City: ";
        std::getline(std::cin,tmp);
        flag = set_city(tmp);
    }
    flag = false;
    while(!flag){
        std::cout << "State: ";
        std::getline(std::cin,tmp);
        flag = set_state(tmp);
    }
    flag = false;
    while(!flag){
        std::cout << "Zipcode: ";
        std::getline(std::cin,tmp);
        flag = set_zip(tmp);
    }
}

//length exactly 9, only digits
int Member::set_MID(const std::string& s) {
    if (s.length()!=9 || !std::all_of(s.begin(),s.end(),::isdigit)) { //make sure s represents a number
       std::cout<< "Invalid MID!" << std::endl;
        return 0;
    }
    mid = s;
    return 1;
}

//json constructor
Member::Member(nlohmann::json j) {
name = j.value("name","not found"); //second param is the default value
mid = j.value("mid","not found");
address = j.value("address","not found");
city = j.value("city","not found");
state = j.value("state","not found");
zip = j.value("zip","not found");
accountActive = j["accountActive"].get<bool>(); //extracts bool from accountActive
}

//copy constructor
Member::Member(const Member& toCopy)
:name(toCopy.name), mid(toCopy.mid),address(toCopy.address),city(toCopy.city),state(toCopy.state),zip(toCopy.zip),accountActive(toCopy.accountActive)
{}

//copy
void Member::copy(const Member& toCopy){
    name = toCopy.name;
    mid = toCopy.mid;
    address = toCopy.address;
    city = toCopy.city;
    state = toCopy.state;
    zip = toCopy.zip;
    accountActive = toCopy.accountActive;
}

