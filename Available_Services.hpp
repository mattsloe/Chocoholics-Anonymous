#ifndef AVAILABLE_SERVICES_HPP
#define AVAILABLE_SERVICES_HPP

#include "Service.hpp"

class Available_Services {
    public:
        ~Available_Services();
        void create_new_service();
        void display();
        void read_from_file(std::string);
        void write_to_file(std::string);
        std::string validate_service_code(unsigned long);
        Service *&get_service(unsigned long sID);

    private:
        std::map<int, Service*&> services;
};

#endif // AVAILABLE_SERVICES_HPP