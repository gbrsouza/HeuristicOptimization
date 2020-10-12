#include <iostream>
#include "algorithm/TSPReader.h"

int main() {
    std::string path = R"(C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\instance\bayg29.tsp)";
    TSP tsp = TSPReader::loadInstance(path);
    std::cout << tsp;
    return 0;
}
