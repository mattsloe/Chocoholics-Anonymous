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
        static bool generate_EFT_test(Service_Ledger *);
        static bool generate_APR_test(Service_Ledger *);
};

static void assert_test(bool);

#endif // SERVICE_LEDGER_TESTER_HPP