#ifndef MEMBER_TEST_H
#define MEMBER_TEST_H


#include <iostream>
#include <fstream>
#include "Member.hpp"
using namespace std;

void testMemberClass();
bool test1(Member*); //Default constructor. Results in valid object
bool test2(Member*); // Initialized constructor (hardcoded). Results in valid object with hardcoded fields
bool test3(Member*); //add/edit data
bool test4(Member*); //test for proper json output
bool test5(Member*); //test for proper json initialization from file

void createMemberInstance(Member*&); //creates Member with test data

void testMemberClass() {
    Member* m_ptr;
//    cout << "Test 1: " << ((test1(m_ptr)==0)?"false":"true") << endl;
//    cout << "Test 2: " << ((test2(m_ptr)==0)?"false":"true") << endl;
//    cout << "Test 3: " << ((test3(m_ptr)==0)?"false":"true") << endl;
    cout << "Test 4: " << ((test4(m_ptr)==0)?"false":"true") << endl;
    cout << "Test 5: " << ((test5(m_ptr)==0)?"false":"true") << endl;
    return;
}

bool test1(Member* mPtr){
    mPtr = new Member();
    if (mPtr == nullptr) return false;
    cout<< *mPtr << endl;
    delete mPtr;
    return true;
}
bool test2(Member* mPtr){
    mPtr = new Member("Matt","123456789", true,"123 xolo ln","Portland","OR","12345");
    if(mPtr == nullptr) return false;
    cout << *mPtr << endl;
    delete mPtr;
    return true;
}
bool test3(Member* mPtr){
    return false;
}

bool test4(Member* mPtr){
    createMemberInstance(mPtr);
    cout <<endl<< mPtr->to_string_exp() << endl;
    return true;
}

bool test5(Member* mPtr){

    //create a testfile
    Member* test;
    createMemberInstance(test);
    ofstream out("member.json");
    out << test->to_string_exp() << endl;

    //initialize using json object
    ifstream in("member.json");
    nlohmann::json  j = nlohmann::json ::parse(in); //instantiate object using parse with the infile stream
    mPtr = new Member(j);
    cout << endl << *mPtr << endl;
    return true;
}

void createMemberInstance(Member*&  mPtr){
    mPtr = new Member("Matt","123456789", true,"123 xolo ln","Portland","OR","12345");
    return;
}




#endif
