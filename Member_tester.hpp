#include <iostream>
#include <fstream>
#include "Member.hpp"
using namespace std;
class MemberTester{
public:
    static bool test1(Member *); //Default constructor. Results in valid object
    static bool test2(Member *); // Initialized constructor (hardcoded). Results in valid object with hardcoded fields
    static bool test3(Member *); //add/edit data
    static bool test4(Member *); //test for proper json output
    static bool test5(Member *); //test for proper json initialization from file
    static bool test6(Member *); //test copy constructor
    static bool test7(Member*); //test .copy() function

    static bool test8(); //test add_service() function
    static bool test9(); //test multiple add_service()
    static bool test10(); //test add_service() with json export


    static void createMemberInstance(Member *&); //creates Member with test data

    static void testMemberClass() {

        cout << "==Testing Member Class: "<<endl;
        Member *m_ptr;
//      cout << "Test 1: " << ((test1(m_ptr)==0)?"false":"true") << endl;
//      cout << "Test 2: " << ((test2(m_ptr)==0)?"false":"true") << endl;
//      cout << "Test 3: " << ((test3(m_ptr)==0)?"false":"true") << endl;
//        cout << "Test 4: " << ((test4(m_ptr) == 0) ? "false" : "true") << endl;
//         cout << "Test 5: " << ((test5(m_ptr) == 0) ? "false" : "true") << endl;
//         cout << "Test 6:" << ((test6(m_ptr)==0) ? "false" : "true") << endl;
//        cout << "Test 7:" << ((test7(m_ptr)==0) ? "false" : "true") << endl;
    cout << "Test 8: " << ((test8()==0) ? "false" : "true") << endl;
        cout << "Test 9: " << ((test9()==0) ? "false" : "true") << endl;
        cout << "Test 10: " << ((test10()==0) ? "false" : "true") << endl;
         cout<<"--------------------"<<endl;
        return;
}
private:
    MemberTester(); //static class
};

bool MemberTester::test1(Member* mPtr){
    mPtr = new Member();
    if (mPtr == nullptr) return false;
    cout<< *mPtr << endl;
    delete mPtr;
    return true;
}
bool MemberTester::test2(Member* mPtr){
    mPtr = new Member("Matt","123456789", true,"123 xolo ln","Portland","OR","12345");
    if(mPtr == nullptr) return false;
    cout << *mPtr << endl;
    delete mPtr;
    return true;
}
bool MemberTester::test3(Member* mPtr){
    return false;
}

bool MemberTester::test4(Member* mPtr){
    createMemberInstance(mPtr);
    cout <<endl<< mPtr->to_string_exp() << endl;
    delete mPtr;
    return true;
}

bool MemberTester::test5(Member* mPtr){

    //create a testfile
    Member* test;
    createMemberInstance(test);
    ofstream out("assets/member.json");
    out << test->to_string_exp() << endl;

    //initialize using json object
    ifstream in("assets/member.json");
    nlohmann::json  j = nlohmann::json ::parse(in); //instantiate object using parse with the infile stream
    mPtr = new Member(j);
    cout << endl << *mPtr << endl;
    delete mPtr;
    return true;
}

bool MemberTester::test6(Member * mPtr){
    createMemberInstance(mPtr);
    Member test(*mPtr);
    cout <<endl<<test<<endl;
    delete mPtr;
    return true;
}

void MemberTester::createMemberInstance(Member*&  mPtr){
    mPtr = new Member("Matt","123456789", true,"123 xolo ln","Portland","OR","12345");
    Service_Record toAdd("10-10-1010","10-20-1010","123456789", "123456789","666666","Here are some comments");
    Service_Record toAdd2("12-34-5678","10-20-1010","999999999", "888888888","666665","Comments for service 2");

    mPtr->add_service(toAdd);
    mPtr->add_service(toAdd2);

}

bool MemberTester::test7(Member * mPtr) {
    createMemberInstance(mPtr);
    Member test;
    test.copy(*mPtr);
    cout << test << endl;
    if (*mPtr == test) return true;
    return false;
}

bool MemberTester::test8() { //test addService()
    //create a service
    Service_Record toAdd("10-10-1010","10-20-1010","123456789", "123456789","666666","Here are some comments");

    Member * test;
    createMemberInstance(test);
    //add it to the Member
    test->add_service(toAdd);
    //display member
    test->to_string();
    //display json
    cout << endl<< test->to_string_exp() << endl;
    return true;
}

bool MemberTester::test9() {
    //create a service
    Service_Record toAdd("10-10-1010","10-20-1010","123456789", "123456789","666666","Here are some comments");
    Service_Record toAdd2("12-34-5678","10-20-1010","999999999", "888888888","666665","Comments for service 2");

    Member * test;
    createMemberInstance(test);
    //add it to the Member
    test->add_service(toAdd);
    test->add_service(toAdd2);
    //display member
    test->to_string();
    //display json
    cout << endl<< test->to_string_exp() << endl;
    return true;
}

bool MemberTester::test10() { //test json import
    //CREATE MEMBER WITH SERVICES ADDED
    Member * test;
    createMemberInstance(test);
    cout << endl << *test << endl;

    return true;
}
