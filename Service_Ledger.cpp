#include "Service_Ledger.hpp"
using namespace std;
using json = nlohmann::json;

void Service_Ledger::new_transaction(Service_Record &record) {
    string id = record.get_pID();
    auto check = this->ledger.find(id);
    auto r = Service_Record(record); // copy passed in record

    // append record to list when collision happens
    if (check->first == id) {
        ledger[id].push_back(r); 
        return;
    }
    
    // create a new vector and append record 
    vector<Service_Record> provider;
    provider.push_back(r);
    // add it to the ledger
    ledger.emplace(record.get_pID(), provider);
}

void Service_Ledger::generate_APR() {
    map<string, int> providers;
    string sid = "", file_name = "AccountsPayableReport";
    int total_providers = 0, total_services = 0, num_consultations = 0;
    double total_fee = 0.0;
    ofstream out;

    file_name += current_date_time();
    file_name += ".txt";
    out.open(file_name);
    if (!out.is_open()) {
        cerr << "Unable to open file!!" << endl;
        exit(-17);
    }

    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        sid = it->first;

        if (providers.find(sid) == providers.end()) continue;
        providers.emplace(sid, 0);

        total_providers++;
        num_consultations = 0;

        for (auto pit = ledger[sid].begin(); pit != ledger[sid].end(); pit++) {
            total_fee += provider_directory.get_fee_d(sid);
            total_services++;
            num_consultations++;
        }

        // output to file
        out << provider_directory.get_name(sid) << " (" << sid << ")\t" << "total consultations: " << to_string(num_consultations) << "," << "total fee: " << fee_output(total_fee) << endl;

    }

    out << "Total number of Providers who provided services: " << to_string(total_providers) << endl;
    out << "Total number of Services provided: " << to_string(total_services);

    out.close();
}

void Service_Ledger::generate_EFT() {
    map<string, int> providers;
    string file_name = "EFTdata", sid;
    double pay_check = 0;
    ofstream out;

    file_name += current_date_time();
    file_name += ".txt";
    out.open(file_name);
    if (!out.is_open()) {
        cerr << "Unable to open file!!" << endl;
        exit(-17);
    }

    for (auto it = ledger.begin(); it != ledger.end(); it++) {

        sid = it->first;

        if (providers.find(sid) == providers.end()) continue;
        providers.emplace(sid, 0);
        pay_check = 0;

        for (auto provider_transactions = ledger[sid].begin(); provider_transactions != ledger[sid].end(); provider_transactions++) {
            pay_check += provider_directory.get_fee_d(sid);
        }

        // output the data to the file
        out << provider_directory.get_name(sid) << " (" << sid << ")\t" << "Paycheck: " << to_string(pay_check) << endl;
    }

    out.close();
}