#ifndef PROVIDER_DIRECTORY_TESTER_HPP
#define PROVIDER_DIRECTORY_TESTER_HPP

#include "Provider_Directory.hpp"

class PD_Tester {
    public:
        static void test_Provider_Directory_class();
        static void create_PD(Provider_Directory *&);
        static bool find_valid(Provider_Directory *);
        static bool find_invalid(Provider_Directory *);
};

#endif // PROVIDER_DIRECTORY_TESTER_HPP