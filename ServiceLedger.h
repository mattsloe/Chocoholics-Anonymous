#ifndef SERVICE_LEDGER_H
#define SERVICE_LEDGER_H

#include "ServiceRecord.h"

class ServiceLedger {
    public:
        ServiceLedger();
        ServiceRecord get_ServiceRecord(int pID);
        void create_ServiceRecord();
        void add_ServiceRecord();

    private:
    // data structure of Service Records
};

#endif // SERVICE_LEDGER_H