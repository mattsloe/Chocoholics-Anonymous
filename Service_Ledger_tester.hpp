#ifndef SERVICE_LEDGER_TESTER_HPP
#define SERVICE_LEDGER_TESTER_HPP

#include "Service_Ledger.hpp"

// Service Ledger tester
class SL_tester {
    public:
        static void test_Service_Ledger_class();
        static void create_SL(Service_Ledger *&);
        
        // tests
        static bool new_transaction_good_test(Service_Ledger *);
        static bool new_transaction_bad_test(Service_Ledger *);

        /*
        // don't know if we are going to do this yet
        static bool generate_EFT_test(Service_Ledger *);
        static bool generate_APR_test(Service_Ledger *);
        */
};

static void assert_test(bool);

// test data
nlohmann::json sr1{
    {"date","2022-11-25 00:33:32"},
    {"sDate","02/12/2022"},
    {"pID","155128738"},
    {"mID","235571762"},
    {"sID","247924"},
    {"comments" ,"Sed sagittis. Nam congue, risus semper porta volutpat, quam pede lobortis ligula, sit amet eleifend pede libero quis orci. Nullam molestie nibh in lectus." }};

nlohmann::json sr1b{
    {"date","2022-31-31 00:33:33"},
    {"sDate","03/13/2022"},
    {"pID","333333333"},
    {"pID","155128738"},
    {"mID","333333333"},
    {"sID","333333"},
    {"comments" ,"Sed sagittis. congue, risus semper porta volutpat, quam pede lobortis ligula, sit amet eleifend pede libero quis orci. Nullam molestie nibh in lectus." } };

nlohmann::json sr1c{
    {"date","2022-22-22 00:22:22"},
    {"sDate","02/22/2022"},
    {"pID","155128738"},
    {"mID","222222222"},
    {"sID","222222"},
    {"comments" ,"Sed Nam congue, risus semper porta volutpat, quam pede lobortis ligula, sit amet eleifend pede libero quis orci. Nullam molestie nibh in lectus." } };

nlohmann::json sr2{
    {"date","2022-22-22 00:22:22"},
    {"sDate","02/22/2022"},
    {"pID","222222222"},
    {"mID","222222222"},
    {"sID","222222"},
    {"comments" ,"Sed Nam congue, risus semper porta volutpat, quam pede lobortis ligula, sit amet eleifend pede libero quis orci. Nullam molestie nibh in lectus." } };

nlohmann::json sr3{
    {"date","2022-31-31 00:33:33"},
    {"sDate","03/13/2022"},
    {"pID","333333333"},
    {"mID","333333333"},
    {"sID","333333"},
    {"comments" ,"Sed sagittis. congue, risus semper porta volutpat, quam pede lobortis ligula, sit amet eleifend pede libero quis orci. Nullam molestie nibh in lectus." } };

#endif // SERVICE_LEDGER_TESTER_HPP