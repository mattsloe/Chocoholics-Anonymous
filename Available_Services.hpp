#ifndef AVAILABLE_SERVICES_HPP
#define AVAILABLE_SERVICES_HPP

#include "Service.hpp"

class Available_Services {
    public:
        ~Available_Services();
            // destructs the dynamically allocated memory
        void create_new_service();
            // allows the provider to create a new service that they wish to offer
        void display();
            // displays all available services to the terminal
        void read_from_file(std::string);
        void write_to_file(std::string);
        std::string validate_service_code(unsigned long);
            // pass in a service ID and the correct string will be returned
        bool get_service(unsigned long, Service *&);
            // pass in the service ID to retrieve the Service, alongside a service object
            // returns fail if the service ID can not be found

    private:
        std::map<int, Service*&> services;
};

#endif // AVAILABLE_SERVICES_HPP