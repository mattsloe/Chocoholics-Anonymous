#include "Service_Ledger.hpp"
using namespace std;
using json = nlohmann::json;

Service_Ledger::~Service_Ledger() {
    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        delete it->second;
        it->second = nullptr;
    }
}
void Service_Ledger::new_transaction(Service_Record *&record) {
    ledger.emplace(record->get_pID(), record);
}

void Service_Ledger::generate_APR(Provider_Directory & dir) {
    map<int, int> providers;
    int total_providers = 0;
    int total_services = 0;
    double total_fee = 0.0;

    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        if (providers.find(it->first) == providers.end()) continue;

        // found the provider so add it to the checklist
        providers.emplace(it->first, 0);
        total_providers++;
        for (auto pit = ledger.equal_range(it->first); pit != ledger.equal_range(it->first); ++pit) {
            total_services++;
            total_fee += dir.search(it->first);
        }
    }
}

void Service_Ledger::generate_EFT() {

}