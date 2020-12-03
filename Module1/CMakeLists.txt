cmake_minimum_required(VERSION 3.15)
project(Module1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Module1 main.cpp problem/TSP.cpp problem/TSP.h problem/TSPReader.cpp problem/TSPReader.h util/Splitter.cpp util/Splitter.h heuristic/LHK.cpp heuristic/LHK.h heuristic/Grasp.cpp heuristic/Grasp.h)