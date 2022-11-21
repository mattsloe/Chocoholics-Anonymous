cmake_minimum_required(VERSION 3.21)
project(Chocaholics-Anonymous-Software)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChocAn main.cpp Member.cpp Member.h json.hpp Service.hpp Service_Ledger.hpp Service_Record.hpp Available_Services.hpp MemberDB.cpp MemberDB.h MemberDB_tester.h Driver.hpp Driver.cpp)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
