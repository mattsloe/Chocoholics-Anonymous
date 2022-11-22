#ifndef SERVICE_LEDGER_HPP
#define SERVICE_LEDGER_HPP

#include "Service_Record.hpp"
#include "json.hpp"
#include <map>
#include <utility>

class Service_Ledger {
    public:
        ~Service_Ledger();
        void new_transaction(Service_Record *&);
        // update with 
        void generate_APR(const Available_Services &);
        void generate_EFT(const Available_Services &); 

    private:
        std::multimap<int, Service_Record*&> ledger;
};

#endif // SERVICE_LEDGER_HPP