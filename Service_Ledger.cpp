#include "Service_Ledger.hpp"
using namespace std;
using json = nlohmann::json;

Service_Ledger::Service_Ledger() {
    read_from_file();
}

void Service_Ledger::read_from_file() {
    string file_name = "assets/service_records.json";
    json j;
    ifstream in;
    in.open(file_name);
    in >> j;
    //init(j);
    return;
}

//void Service_Ledger::init

Service_Ledger::~Service_Ledger() {
    write_to_file();
}

void Service_Ledger::write_to_file() {
    string file_name = "assets/service_records.json";
    ofstream o;
    json j_ledger;
    json j_vec;

    o.open(file_name);
    
    if (!o.is_open()) {
        cerr << "Could not open the file!!" << endl;
        return;
    }

    for (auto it = ledger.begin(); it != ledger.end(); it++) {
        j_ledger["pID"] = vec_to_string(it->first);
    }

    j_ledger >> o;
    o.close();

    return;
}

std::string Service_Ledger::vec_to_string(const string& pID) {
    string out;
    out += "{";
    for (auto it = this->ledger[pID].begin(); it != this->ledger[pID].end(); it++) {
        out += it->to_string_exp();
    }
    out += "}";
    return out;
}

void Service_Ledger::new_transaction(Service_Record &record) {
    auto new_record = Service_Record(record); // copy passed in record
    string id = new_record.get_pID();
    auto check = this->ledger.find(id);

    // append record to list at the service code when collision happens
    if (in_ledger(id)) {
        ledger[id].push_back(new_record); 
        return;
    }
    
    // create a new vector and append record, then add it to the ledger
    vector<Service_Record> provider;
    provider.push_back(new_record);
    ledger.emplace(id, provider);
}

void Service_Ledger::generate_APR(Provider_Directory &provider_directory) {
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

void Service_Ledger::generate_EFT(Provider_Directory &provider_directory) {
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

bool Service_Ledger::in_ledger(string id) {
    auto val = ledger.find(id);
    if (val->first == id && val != ledger.end())
        return true;
    return false;
}