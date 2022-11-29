cmake_minimum_required(VERSION 3.21)
project(Chocaholics-Anonymous-Software)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChocAn 
                Driver.hpp Driver.cpp 
                json.hpp main.cpp 
                #Member.cpp Member.hpp Member_tester.hpp Member_tester.cpp 
                #MemberDB.cpp MemberDB.hpp MemberDB_tester.hpp
                Provider_Directory.hpp Provider_Directory.cpp 
                Provider_Directory_tester.hpp Provider_Directory_tester.cpp
                Service_Ledger.hpp Service_Ledger.cpp 
                Service_Record.hpp Service_Record.cpp
                Service_Record_tester.hpp Service_Record_tester.cpp
                Provider.hpp Provider.cpp #Provider_tester.cpp
                )

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
