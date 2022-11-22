#ifndef SERVICE_RECORD_HPP
#define SERVICE_RECORD_HPP

#include "json.hpp"
#include <iostream>
#include <string>

class Service_Record {
    public:
        Service_Record(const Service_Record &);
        Service_Record(std::string date, std::string sDate, unsigned int pID, unsigned int mID, unsigned int sID, std::string comments); //- initialized constructor
        Service_Record(nlohmann::json); // - takes in a string json object and initializes Provider instance
        void display(); //- displays to CLI
        void set_date(std::string date);
        void set_sDate(std::string sDate);
        void set_comments(std::string comments);
        void set_pID(unsigned int pID);
        void set_mID(unsigned int mID);
        void set_sID(unsigned int sID);
        std::string get_date();
        std::string get_sDate();
        std::string get_comments();
        unsigned int get_pID();
        unsigned int get_mID();
        unsigned int get_sID();
    
        std::string to_string_exp();  //- returns a string json object representing the instance of the Service Record 
        Service_Record & operator = (const Service_Record &);

    private:
        std::string date, sDate, comments;
        unsigned int pID, mID, sID;
};

#endif // SERVICE_RECORD_HPP