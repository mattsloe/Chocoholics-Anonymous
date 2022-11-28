#ifndef SERVICE_LEDGER_HPP
#define SERVICE_LEDGER_HPP

#include "Provider_Directory.hpp"
#include "Service_Record.hpp"
#include "json.hpp"
#include <map>
#include <vector>
#include <utility>

class Service_Ledger {
    public:
        Service_Ledger();
        ~Service_Ledger();
        void new_transaction(Service_Record &);
        void generate_APR();
        void generate_EFT(); 

    private:
        std::unordered_map<std::string, std::vector<Service_Record>> ledger;
};

#endif // SERVICE_LEDGER_HPP