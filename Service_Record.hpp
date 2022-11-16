#ifndef SERVICE_RECORD_HPP
#define SERVICE_RECORD_HPP

#include <iostream>
#include <string>

class Service_Record {
    public:

        Service_Record(std::string date, std::string sDate, int pID, int mID, int sID, std::string comments); //- initialized constructor
        Service_Record(std::string json); // - takes in a string json object and initializes Provider instance
        // implement = operator overload
        void display(); //- displays to CLI
        void toJSON();  //- returns a string json object representing the instance of Provider
        void set_date(std::string date);
        void set_sDate(std::string sDate);
        void set_comments(std::string comments);
        void set_pID(int pID);
        void set_mID(int mID);
        void set_sID(int sID);
        std::string get_date();
        std::string get_sDate();
        std::string get_comments();
        int get_pID();
        int get_mID();
        int get_sID();
    
    private:
        std::string date, sDate, comments;
        int pID, mID, sID;
};

#endif // SERVICE_RECORD_HPP