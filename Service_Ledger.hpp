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
        void new_transaction(Service_Record &);
        void generate_APR(Provider_Directory *);
        void generate_EFT(Provider_Directory *); 
        bool in_ledger(std::string);

    private:
        std::unordered_map<std::string, std::vector<Service_Record>> ledger;
};

#endif // SERVICE_LEDGER_HPP