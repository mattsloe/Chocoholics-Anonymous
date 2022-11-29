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

// test data
static std::string test_date = "07/17/2022 12:23:57";
static std::string test_sDate = "07/17/2022";
static std::string test_pID = "123456789";
static std::string test_mID = "012345678";
static std::string test_sID = "123456";
static std::string test_comment = "Hello worlHello worlHello worlHello worlHello worlHello worlHello worlHello worlHello worlHello worl";
    // 100 chars to test the capability

nlohmann::json j = {
    {"date",test_date},
    {"sDate",test_sDate},
    {"pID",test_pID},
    {"mID",test_mID},
    {"sID",test_sID},
    {"comments",test_comment}
};

#endif // SERVICE_RECORD_TESTER_HPP