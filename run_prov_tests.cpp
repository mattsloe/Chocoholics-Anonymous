#include "Provider_tester.hpp"
#include "Provider_Database_tester.hpp"

int main() {
	Provider_tester::test_provider_class();
	ProviderDB_tester::test_Provider_Database_class();
	return 0;
}