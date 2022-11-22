#ifndef SERVICE_LEDGER_TESTER_HPP
#define SERVICE_LEDGER_TESTER_HPP

#include "Service_Ledger.hpp"

class Service_Ledger_tester {
    public:
        static void test_Service_Ledger_class();
        
        // tests
        static bool test_generate_EFT(Service_Ledger *);
        static bool test_generate_APR(Service_Ledger *);
        static bool test_new_transaction(Service_Ledger *);
};

#endif // SERVICE_LEDGER_TESTER_HPP