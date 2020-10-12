cmake_minimum_required(VERSION 3.15)
project(Module1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Module1 main.cpp algorithm/TSP.cpp algorithm/TSP.h algorithm/TSPReader.cpp algorithm/TSPReader.h util/Splitter.cpp util/Splitter.h)