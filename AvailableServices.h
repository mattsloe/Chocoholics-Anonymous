#ifndef AVAILABLE_SERVICES_H
#define AVAILABLE_SERVICES_H

#include "Service.h"

class Available_Services {
    public:
        void add_service();
        void display();
        void read_to_file();
        void write_to_file();
        std::string validate_service_code();

    private:
        std::map<int, Service> services;
};

#endif // AVAILABLE_SERVICES_H