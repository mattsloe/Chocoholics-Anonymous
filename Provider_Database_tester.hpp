#ifndef PROVIDER_DATABASE_TESTER_HPP
# define PROVIDER_DATABASE_TESTER_HPP
#include "Provider_Database.hpp"

class ProviderDB_tester {
	public:
		static void test_Provider_Database_class();
		
		static bool getProvider_happy();
		static bool getProvider_empty();
		static bool getProvider_notFound();
		static bool addProvider_happy();
		static bool deleteProvider_happy();
		static bool deleteProvider_empty();
		static bool genProvReports_happy();
		static bool genManagerReports_happy();
		static bool genSingleReport_happy();
		static bool toFile_happy();
		static bool loadFile_happy();

};

#endif // PROVIDER_DATABASE_TESTER_HPP