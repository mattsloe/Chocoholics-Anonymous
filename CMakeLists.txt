cmake_minimum_required(VERSION 3.21)
project(Chocaholics-Anonymous-Software)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChocAn main.cpp Member.cpp Member.h json.hpp Service.hpp Service_History.hpp Service_Info.hpp Service_Ledger.hpp Service_Record.hpp Available_Services.hpp "Provider_tester.cpp")
