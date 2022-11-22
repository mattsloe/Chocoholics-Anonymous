#ifndef SERVICE_RECORD_TESTER_HPP
#define SERVICE_RECORD_TESTER_HPP

#include "Service_Record.hpp"

class Service_Record_tester {
    public:
        // Main Driver Call 
        static void test_Service_Record_class();

        // tests
        static bool default_constructor(Service_Record *);
        static bool copy_constructor(Service_Record *);
        static bool json_constructor(Service_Record *);
};

#endif // SERVICE_RECORD_TESTER_HPP