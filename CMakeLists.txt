cmake_minimum_required(VERSION 3.10)
project(Project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project2
    Project2.cpp
    QuadProbing.cpp
    anomaly.cpp
    logger.cpp
    tester.cpp
)
