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

void Service_Ledger::generate_APR(const Available_Services &dir) {
    map<int, int> providers;
    int total_providers = 0;
    int total_services = 0;
    double total_fee = 0.0;

    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        if (providers.find(it->first) == providers.end()) continue;
        providers.emplace(it->first, 0);
        total_providers++;
        for (auto pit = ledger.equal_range(it->first); pit != ledger.equal_range(it->first); ++pit) {
            total_services++;
            total_fee += dir.search(it->first);
        }
    }
}

void Service_Ledger::generate_EFT(const Available_Services &dir) {
    map<int, int> providers;
    string file_name = "EFTdata";
    string date = "";
    double pay_check = 0;
    fstream f(file_name+date);
    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        if (providers.find(it->first) == providers.end()) continue;
        providers.emplace(it->first, 0);
        pay_check = 0;
        for (auto provider_transactions = ledger.equal_range(it->first); provider_transactions != ledger.equal_range(it->first); provider_transactions++) {
            pay_check += dir.get_service_fee(provider_transactions->first);
        }
        // output the data to the file
    }
}