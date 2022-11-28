#ifndef PROVIDER_DIRECTORY_TESTER_HPP
#define PROVIDER_DIRECTORY_TESTER_HPP

#include "Provider_Directory.hpp"

class PD_tester {
    public:
        static void test_Provider_Directory_class();
        static void create_PD(Provider_Directory *&);

        static bool file_constructor(Provider_Directory *);
        static bool validateID_success(Provider_Directory *);
        static bool validateID_fail(Provider_Directory *);
};

static void assert_test(bool);

#endif // PROVIDER_DIRECTORY_TESTER_HPP