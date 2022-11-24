#ifndef AVAILABLE_SERVICES_HPP
#define AVAILABLE_SERVICES_HPP

//#include "Service_Ledger.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unordered_map>

class Available_Services {
    public:
        //~Available_Services();
        Available_Services(std::string);
        void init(nlohmann::json);
        void create_new_service();
            // allows the provider to create a new service that they wish to offer
        void display();
            // displays all available services to the terminal
        void read_from_file();
        void write_to_file();
        std::string validate_service_code(unsigned int);
            // pass in a service ID and the correct string will be returned
        bool get_service(unsigned int, Service *&);
            // pass in the service ID to retrieve the Service, alongside a service object
            // returns fail if the service ID can not be found

    private:
        std::unordered_map<int, Service> services;
};

class Service {
    public:
        Service();
        Service(nlohmann::json);
        Service(std::string, unsigned int, double);
        Service(const Service &);
        void set_name(std::string);
        void set_id(unsigned int);
        void set_fee(double);
        std::string get_name();
        std::string to_string_exp();
        void display();

        // writing to file
        // write to json or string to return

        // = operator overload
        Service & operator = (const Service &);

    private:
        std::string name;
        unsigned int sID;
        double fee;
};

std::string fee_output(double);

#endif // AVAILABLE_SERVICES_HPP