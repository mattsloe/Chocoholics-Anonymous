// FILE: main.cpp
// Authors: 
    // Nathaniel Waggoner
    // Kobe Norcross
    // Ashton Sawyer
    // Matt Loera
    // Yuki Yamada
#include <ios>

#include "Member_tester.h"
#include "MemberDB_tester.h"

int main()
{
    //tester code for Member class
    std::cout << "Testing member class" << std::endl;
    MemberTester::testMemberClass();
    std::cout << std::endl;

    //tester code for MemberDB
    std::cout << "Testing MemberDB: "<< std::endl;
    MemberDBtester::testMemberDBClass();
    std::cout << std::endl;

    return 0;
}
