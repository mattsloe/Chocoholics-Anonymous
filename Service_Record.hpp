#ifndef SERVICE_RECORD_HPP
#define SERVICE_RECORD_HPP

#include "json.hpp"
#include <iostream>
#include <string>
#include <ctime>

class Service_Record {
    public:
        Service_Record();
        Service_Record(const Service_Record &);
        Service_Record(std::string date, std::string sDate, std::string pID, std::string mID, std::string sID, std::string comments); //- initialized constructor
        Service_Record(nlohmann::json); // - takes in a string json object and initializes Provider instance
        void display(); //- displays to CLI
        void set_date(std::string date);
        void set_sDate(std::string sDate);
        bool set_comments(std::string comments);
        bool set_pID(std::string pID);
        bool set_mID(std::string mID);
        bool set_sID(std::string sID);
        std::string get_date();
        std::string get_sDate();
        std::string get_comments();
        std::string get_pID();
        std::string get_mID();
        std::string get_sID();
        std::string to_string_exp();  //- returns a string json object representing the instance of the Service Record 
        Service_Record & operator = (const Service_Record &);

        // functionality to create a Service Record
        void create_Service_Record();
        bool input_date();
        std::string input_sDate();
        void input_comments();

    private:
        std::string date;
        std::string sDate;
        std::string pID; 
        std::string mID; 
        std::string sID;
        std::string comments;
};

static std::string current_date_time();
static std::string get_part_date(int); // gets letters to represent month, day, and year
static std::string input_ID(int); // gets a valid ID with the correct size
static bool valid_id(int, std::string); // checks if the string passed in is valid to use

#endif // SERVICE_RECORD_HPP