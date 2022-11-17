//
// Created by Matt Loera on 11/16/22.
//
#ifndef _MEMBERDB_TESTER_
#define _MEMBERDB_TESTER_

#include <iostream>
#include <fstream>
#include <string>
#include "MemberDB.h"
using namespace std;
 class MemberDBtester {
 public:
    static bool test1(MemberDB *); //instantiate MemberDB blank
    static bool test2(MemberDB *); //Add 1 member to MemberDB, display
    static bool test3(MemberDB *); //instantiate with filename "test-members.json", display all
    static bool test4(MemberDB *); //retrieve a member by MID
    static bool test5(MemberDB *); //retrieve a member by MID that does not exist

    static void testMemberDBClass() {
        MemberDB *db_ptr;
        cout << "Test 1: " << ((test1(db_ptr) == 0) ? "false" : "true") << endl;
        cout << "Test 2: " << ((test2(db_ptr)==0)?"false":"true") << endl;
        cout << "Test 3: " << ((test3(db_ptr)==0)?"false":"true") << endl;
//      cout << "Test 4: " << ((test4(db_ptr)==0)?"false":"true") << endl;
//      cout << "Test 5: " << ((test5(db_ptr)==0)?"false":"true") << endl;
        return;
    }
private:
    MemberDBtester(); //static class
};

bool MemberDBtester::test1(MemberDB* db_ptr){
   db_ptr = new MemberDB();
   delete db_ptr;
   return true;
}
bool MemberDBtester::test2(MemberDB* db_ptr){
    //create a member to add
    Member m("Name","123456789", true,"123 xolo ln","portland","OR","12345");
    //try to add Member to DB
    db_ptr = new MemberDB();
    db_ptr->add_member(m);
    int n = db_ptr->display_all();
    cout <<endl<< "Number of members: " << n << endl;
    return true;
}
bool MemberDBtester::test3(MemberDB * db_ptr){
    std::string  filename = "assets/test-members.json";
    db_ptr = new MemberDB(filename);
    int n = db_ptr->display_all();
    cout <<endl<< "Number of members: " << n << endl;
    return true;
}

bool MemberDBtester::test4(MemberDB* db_ptr){//retrieve a member by mid=352858252 Randolf Christoffe
    string  filename = "assets/test-members.json";
    db_ptr = new MemberDB(filename);

    Member m;
    db_ptr->get_member("352858252",m);
    cout << m;
    return true;
}

bool MemberDBtester::test5(MemberDB* db_ptr){ //retrieve a member by mid=000000000
    string  filename = "assets/test-members.json";
    db_ptr = new MemberDB(filename);

    Member m;
    if (db_ptr->get_member("000000000",m))
        return false;
    else
        return true;
}

#endif

