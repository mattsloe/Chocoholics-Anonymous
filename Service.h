#ifndef SERVICE_H
#define SERVICE_H

#include "ServiceLedger.h"

class Service {
    public:
        Service();
        ~Service();
        void set_name(std::string);
        void set_id(unsigned long);
        void set_fee(double);
    private:
        std::string name;
        unsigned long sID;
        double fee;
};

#endif // SERVICE_H