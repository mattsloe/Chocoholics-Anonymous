#include "Service_Ledger.hpp"
using namespace std;
using json = nlohmann::json;

/*
Service_Ledger::~Service_Ledger() {
    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        delete it->second;
        //it->second = nullptr;
    }
}
*/

void Service_Ledger::new_transaction(Service_Record &record) {
    string id = record.get_pID();
    auto check = ledger.find(id);

    // append record to list when collision happens
    if (check->first == id) {
        ledger[id].push_back(record); 
        return;
    }
    
    // create a new vector and append record 
    vector<Service_Record &> provider;
    provider.push_back(record);
    // add it to the ledger
    ledger.emplace(record.get_pID(), provider);
}

void Service_Ledger::generate_APR() {
    map<string, int> providers;
    int total_providers = 0;
    int total_services = 0;
    double total_fee = 0.0;

    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        if (providers.find(it->first) == providers.end()) continue;
        providers.emplace(it->first, 0);
        total_providers++;
        for (auto pit = ledger[it->first].begin(); pit != ledger[it->first].end(); pit++) {
            total_fee += provider_directory.get_fee(it->first);
            total_services++;
        }
    }
}

void Service_Ledger::generate_EFT() {
    Service * service = nullptr;
    map<string, int> providers;
    string file_name = "EFTdata";
    string date = "";
    string sid;
    double pay_check = 0;
    fstream f(file_name+date);
    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        sid = it->first;
        if (providers.find(sid) == providers.end()) continue;
        providers.emplace(sid, 0);
        pay_check = 0;
        for (auto provider_transactions = ledger[sid].begin(); provider_transactions != ledger[sid].end(); provider_transactions++) {
            pay_check += provider_directory.get_fee(sid);
            delete service;
            service = nullptr;
        }
        // output the data to the file
    }
}