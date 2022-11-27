cmake_minimum_required(VERSION 3.21)
project(Chocaholics-Anonymous-Software)

set(CMAKE_CXX_STANDARD 14)

add_executable(ChocAn Provider_Directory.hpp Driver.hpp Driver.cpp json.hpp main.cpp Member.cpp Member.h  Member_tester.h Member_tester.cpp MemberDB.cpp MemberDB.h MemberDB_tester.h Service_Ledger.hpp Service_Record.hpp   )

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
