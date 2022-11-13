#ifndef SERVICE_HPP
#define SERVICE_H

#include "Service_Ledger.hpp"

class Service {
    public:
        Service(std::string, unsigned long, double);
        void set_name(std::string);
        void set_id(unsigned long);
        void set_fee(double);

    private:
        std::string name;
        unsigned long sID;
        double fee;
};

#endif // SERVICE_HPP