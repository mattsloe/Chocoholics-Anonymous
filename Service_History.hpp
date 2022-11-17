#ifndef SERVICE_HISTORY_H
#define SERVICE_HISTORY_H

#include "Service_Info.hpp"
#include <forward_list>

class Service_History {
    public:
        void add_transaction();
        void write_to_file();
        void display();

    private:
        std::forward_list<Service_Info> history;
};

#endif // SERVICE_HISTORY_H