#ifndef AVAILABLE_SERVICES_HPP
#define AVAILABLE_SERVICES_HPP

#include "Service.hpp"

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

#endif // AVAILABLE_SERVICES_HPP