#ifndef SERVICE_RECORD_TESTER_HPP
#define SERVICE_RECORD_TESTER_HPP

#include "Service_Record.hpp"

class Service_Record_tester {
    public:
        // Main Driver Call 
        static void test_Service_Record_class();
        static void create_SR(Service_Record *&);

        // constructor tests
        static bool default_constructor(Service_Record *);
        static bool copy_constructor(Service_Record *);
        static bool json_constructor(Service_Record *);

        // data storing tests
        static bool setting_date(Service_Record *);
        static bool setting_sDate(Service_Record *);
        static bool setting_sID(Service_Record *);
        static bool setting_mID(Service_Record *);
        static bool setting_pID(Service_Record *);
        static bool setting_comments(Service_Record *);
};

static void assert_test(bool);

#endif // SERVICE_RECORD_TESTER_HPP