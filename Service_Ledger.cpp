#include "Service_Ledger.hpp"
using namespace std;

Service_Ledger::~Service_Ledger() {
    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        // write to file?
        delete it->second;
        it->second = nullptr;
    }
    // delete ledger 
}
void Service_Ledger::new_transaction(Service_Record *&record) {
    //ledger.insert(pair<int,Service_Record*&>(record->get_mID(), record));
    ledger.emplace(record->get_pID(), record);
}

void Service_Ledger::generate_APR() {
    map<int, int> providers;
    int total_providers = 0;
    int total_services = 0;
    double total_fee = 0.0;

    // loop through and gain data
    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        // check for curr provider
        if (providers.find(it->first) == providers.end()) continue;
        // found the provider so add it to the checklist
        providers.emplace(it->first, 0);
        total_providers++;
        for (auto pit = ledger.equal_range(it->first); pit != ledger.equal_range(it->first); ++pit) {
            // output provider data
            total_services++;
            total_fee += pit->second.get_fee;
        }
    }
}

void Service_Ledger::generate_EFT() {

}