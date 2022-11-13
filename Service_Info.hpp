#ifndef SERVICE_INFO_HPP
#define SERVICE_INFO_HPP

#include "Service_Ledger.hpp"

class Service_Info {
    public:
        Service_Info(std::string, std::string, std::string);
        void set_date(std::string);
        void set_p_name(std::string);
        void set_s_name(std::string);
        void display();

    private:
        std::string date, p_name, s_name;
            // p_name = provider name
            // s_name = service name
};

#endif // SERVICE_INFO_HPP