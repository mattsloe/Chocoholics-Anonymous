#ifndef SERVICE_LEDGER_H
#define SERVICE_LEDGER_H

#include "ServiceRecord.h"
#include <map>

class ServiceLedger {
    public:
        void new_transaction();
        void generate_APR();
        void generate_EFT(); 

    private:
        std::map<int, ServiceRecord> ledger;
};

#endif // SERVICE_LEDGER_H