#ifndef SERVICE_LEDGER_HPP
#define SERVICE_LEDGER_HPP

#include "Service_Record.hpp"
#include <map>

class Service_Ledger {
    public:
        void new_transaction();
        void generate_APR();
        void generate_EFT(); 

    private:
        std::map<int, Service_Record> ledger;
};

#endif // SERVICE_LEDGER_HPP