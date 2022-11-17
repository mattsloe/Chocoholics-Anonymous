//
// Created by Matt Loera on 11/16/22.
//
#ifndef _MEMBERDB_TESTER_
#define _MEMBERDB_TESTER_

#include <iostream>
#include <fstream>
#include "MemberDB.h"

 class MemberDBtester {
 public:
    static bool test1(MemberDB *); //instantiate MemberDB blank
    static bool test2(MemberDB *); //Add 1 member to MemberDB, display
    static bool test3(MemberDB *); //instantiate with filename "test-members.json", display all
    static bool test4(MemberDB *); //retrieve a member by MID
    static bool test5(MemberDB *); //

    static void testMemberDBClass() {
        using namespace std;
        MemberDB *db_ptr;
        cout << "Test 1: " << ((test1(db_ptr) == 0) ? "false" : "true") << endl;
//    cout << "Test 2: " << ((test2(db_ptr)==0)?"false":"true") << endl;
//    cout << "Test 3: " << ((test3(db_ptr)==0)?"false":"true") << endl;
//    cout << "Test 4: " << ((test4(db_ptr)==0)?"false":"true") << endl;
//    cout << "Test 5: " << ((test5(db_ptr)==0)?"false":"true") << endl;
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
    return false;
}
bool MemberDBtester::test3(MemberDB * db_ptr){
    return false;
}

bool MemberDBtester::test4(MemberDB* db_ptr){
    return false;
}

bool MemberDBtester::test5(MemberDB* db_ptr){
    return false;
}

#endif

