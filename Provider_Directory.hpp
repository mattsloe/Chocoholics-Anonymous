#ifndef PROVIDER_DIRECTORY_HPP
#define PROVIDER_DIRECTORY_HPP

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unordered_map>

class Service {
    public:
        Service();
        Service(nlohmann::json);
        Service(std::string, std::string, double);
        Service(const Service &);
        bool set_name(std::string);
        bool set_fee(double);
        bool set_sID(const std::string &);
        std::string get_name();
        std::string get_sID();
        double get_fee();

        void display();
        void operator = (const Service &);
        std::string to_string_exp();

    private:
        std::string name;
        std::string sID;
        double fee;
};

class Provider_Directory {
    public:
        Provider_Directory(std::string); // file name reading in constructor
        void init(nlohmann::json); // create DS with json object
        void create_new_service(); // allows the provider to create a new service that they wish to offer
        void display(); // displays all available services to the terminal
        void read_from_file(); // read Services from Services.json
        void write_to_file(); // write Services to Services.json
        std::string validate_service_code(std::string); // pass in a service ID and the correct string will be returned
        bool get_service(std::string, Service *&); // pass in the service ID to retrieve the Service, alongside a service object, returns fail if the service ID can not be found

        // the following functions allow for easy access to the needed data as you just need to pass in the service code and catch it with a new string
        std::string get_name(std::string);
        std::string get_fee(std::string);

    private:
        std::unordered_map<std::string, Service> services;
            // string Service ID mapped to Service
} provider_directory;


std::string fee_output(double);

#endif // PROVIDER_DIRECTORY_HPP