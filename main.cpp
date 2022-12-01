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
		

//	MemberDBtester::testMemberDBClass();


	
	//PD_tester::test_Provider_Directory_class();
	//SL_tester::test_Service_Ledger_class();
	//Service_Record_tester::test_Service_Record_class();
//    MemberTester::testMemberClass();

	//Creating space between driver and any tests we decide to run above.

    Provider_Directory p("assets/services.json");
    Provider_Database pDB(p);
    Member m("Matt","111111111", true,"1234 something ln","city","st","12345");
    m.add_service(Service_Record("10-22-2020","10-23-2020","839496875","111111111","206689","A service")); //Cristobal Jezzard - Ocular Disease
    m.add_service(Service_Record("10-22-2020","10-22-2020","511584116","111111111","253969","2nd")); //Alvy Levane - Athletic Performance
    m.add_service(Service_Record("10-22-2020","10-22-2022","152730158","111111111","982798","more")); //Corabel Rustman - CFR
    m.run_member_report(p,pDB);
	cout << "\n\n\n\n\n\n";

	Driver term;

	term.start_driver();
	
	return 0;
}
