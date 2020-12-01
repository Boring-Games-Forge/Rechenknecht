cmake_minimum_required(VERSION 3.5)

project(RechnerTest LANGUAGES CXX)


find_package(Qt5Test REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(RechnerTest tst_rechner.cpp ../rechner.cpp ../rechner.h)
#add_test(NAME Rechner COMMAND test_case1)
target_link_libraries(RechnerTest PRIVATE Qt5::Gui Qt5::Test)

