#ifndef SERVICE_HPP
#define SERVICE_H

#include "Service_Ledger.hpp"
#include <iomanip>
#include "json.h"

class Service {
    public:
        Service();
        Service(std::string, unsigned long, double);
        void set_name(std::string);
        void set_id(unsigned long);
        void set_fee(double);
        std::string get_name();
        void display();

        // writing to file
        // write to json or string to return

        // = operator overload

    private:
        std::string name;
        unsigned long sID;
        double fee;
};

std::string fee_output(double);

#endif // SERVICE_HPP