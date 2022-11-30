//
// Created by Matt Loera on 11/16/22.
//
#ifndef _MEMBERDB_TESTER_
#define _MEMBERDB_TESTER_

#include <iostream>
#include <fstream>
#include <string>
#include "MemberDB.hpp"
using namespace std;
 class MemberDBtester {
 public:
    static bool test1(MemberDB *); //instantiate MemberDB blank
    static bool test2(MemberDB *); //Add 1 member to MemberDB, display
    static bool test3(MemberDB *); //instantiate with filename "test-members.json", display all
    static bool test4(MemberDB *); //retrieve a member by MID
    static bool test5(MemberDB *); //retrieve a member by MID that does not exist
    static bool test6(MemberDB *); //test delete_member()
    static bool test7(); //test DB with persistence
    static bool test8(); //test large DB with persistence
    static bool test9(); //does it come back from file properly?
    static bool test10(); //proper init from file

    static void createMemberInstance(Member*& mPtr){
        mPtr = new Member("0","123456789", true,"123 xolo ln","Portland","OR","12345");
        Service_Record toAdd("10-10-1010","10-20-1010","123456789", "123456789","666666","Here are some comments");
        Service_Record toAdd2("12-34-5678","10-20-1010","999999999", "888888888","666665","Comments for service 2");

        mPtr->add_service(toAdd);
        mPtr->add_service(toAdd2);
    }


    static void testMemberDBClass() {
        cout<< "==Testing MemberDB class: "<<endl;
        MemberDB *db_ptr;
//        cout << "Test 1: " << ((test1(db_ptr) == 0) ? "false" : "true") << endl;
//        cout << "Test 2: " << ((test2(db_ptr)==0)?"false":"true") << endl;
//        cout << "Test 3: " << ((test3(db_ptr)==0)?"false":"true") << endl;
//        cout << "Test 4: " << ((test4(db_ptr)==0)?"false":"true") << endl;
//        cout << "Test 5: " << ((test5(db_ptr)==0)?"false":"true") << endl;
//        cout << "Test 6: " << ((test6(db_ptr)==0)?"false":"true") << endl;
//        cout << "Test 7: " << ((test7()==0)?"false":"true") << endl;
//        cout << "Test 8: " << ((test8()==0)?"false":"true") << endl;
//        cout << "Test 9: " << ((test9()==0)?"false":"true") << endl;
        for (int i = 0; i < 100; ++i) {
         cout << "Test 10: " << ((test10()==0)?"false":"true") << endl;
        }
        cout << "Test 10: " << ((test10()==0)?"false":"true") << endl;

        cout<<"--------------------"<<endl;
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
    cout << m<<endl;
    return true;
}

bool MemberDBtester::test5(MemberDB* db_ptr){ //retrieve a member by mid=000000000
    string  filename = "assets/test-members.json";
    db_ptr = new MemberDB(filename);

    Member m;
    if (db_ptr->get_member("000000000",m)){
        delete db_ptr;
        return false;}
    else
    {delete db_ptr;
        return true;
    }

}

bool MemberDBtester::test6(MemberDB* db_ptr){ //retrieve a member by mid=000000000
    string  filename = "assets/test-members.json";
    db_ptr = new MemberDB(filename);

    Member m;
    db_ptr->delete_member("352858252");
    if (db_ptr->get_member("352858252",m)){
        cout << "Member still in db" << endl;
        delete db_ptr;
        return false;
    }
    else{
        cout << "Member deleted" << endl;
        delete db_ptr;
        return true;
    }
}

bool MemberDBtester::test7() {
    string  filename = "assets/test-members-small.json";
   MemberDB members(filename);

   members.display_all();
//   cout << endl << "deleting member...";
//    if (members.delete_member("984092090")) cout << "true" << endl;
//    else cout << "false"<< endl;
//
//    members.display_all();

    cout << endl << "adding members..."<<endl;
    Member* toAdd;
    createMemberInstance(toAdd);
    members.add_member(*toAdd);
    members.display_all();

    return true;
}

bool MemberDBtester::test8() {
    string  filename = "assets/test-members.json";
    MemberDB members(filename);

//    members.display_all();
//   cout << endl << "deleting member...";
//    if (members.delete_member("984092090")) cout << "true" << endl;
//    else cout << "false"<< endl;
//
//    members.display_all();

    cout << endl << "adding members..."<<endl;
    Member* toAdd;
    createMemberInstance(toAdd);
    members.add_member(*toAdd);
    members.display_all();

    return true;
}

bool MemberDBtester::test9() {
    string  filename = "assets/test-members.json";
    MemberDB members(filename);
    return true;
}

bool MemberDBtester::test10(){
    MemberDB members;
    members.display_all();
    return true;
}

#endif

