#ifndef PROVIDER_DIRECTORY_TESTER_HPP
#define PROVIDER_DIRECTORY_TESTER_HPP

class PD_tester {
    public:
        static void test_Provider_Directory_class();
        static void create_PD(Provider_Directory *&);
        static bool find_valid(Provider_Directory *);
        static bool find_invalid(Provider_Directory *);
};

static void assert_test(bool);

#endif // PROVIDER_DIRECTORY_TESTER_HPP