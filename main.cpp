// FILE: main.cpp
// Authors: 
    // Nathaniel Waggoner
    // Kobe Norcross
    // Ashton Sawyer
    // Matt Loera
 
#include <iostream>

#include "Driver.hpp"

//#include "Member_tester.cpp"
//#include "Service_Record_tester.hpp"
#include "Service_Ledger_tester.hpp"
#include "Provider_Directory_tester.hpp"
//#include "Member_tester.hpp"
//#include "MemberDB_tester.hpp"

int main()
{
   	using namespace std;

   	//Add testing below. 
	/*
	MemberDBtester::testMemberDBClass();
	PD_tester::test_Provider_Directory_class();
	SL_tester::test_Service_Ledger_class();
	Service_Record_tester::test_Service_Record_class();
    MemberTester::testMemberClass();

	//Creating space between driver and any tests we decide to run above.

	cout << "\n\n\n\n\n\n";
	*/

	Driver term;

	term.start_driver();
	
	return 0;
}
