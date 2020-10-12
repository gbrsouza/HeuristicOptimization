//
// Created by gabri on 11/10/2020.
//

#include <fstream>
#include <iostream>
#include "TSPReader.h"
#include "../util/Splitter.h"

TSP TSPReader::loadInstance(const std::string& path) {
    unsigned int dimension = 0;
    int **tmpData = nullptr;

    std::string line;
    std::ifstream instance (path);

    if (instance.is_open()){
        while (std::getline(instance, line)){
            if (line.find("DIMENSION") != std::string::npos)
                dimension = std::stoi(Splitter::split(line)[1]);

            if (line.find("EDGE_WEIGHT_SECTION") != std::string::npos){
                tmpData = static_cast<int **>(malloc(sizeof(int*) * dimension));
                for (int i=0; i<dimension; i++)
                    tmpData[i] = static_cast<int *>(malloc(sizeof(int) * dimension));

                for (int i=0; i<dimension; i++)
                    tmpData[i][i] = 0;

                for (int i=0; i<dimension-1; i++){
                    std::getline(instance, line);
                    std::cout << "line: " << line << std::endl;
                    std::vector<std::string> values = Splitter::split(line);

                    for (int k=0; k<values.size();k++)
                        std::cout << values[k] << " ";
                    std::cout << std::endl;

                    for (unsigned int j=dimension-1; j>i; j--){
                        int value = std::stoi(values[(dimension-i-1)-(j-i)]);
                        tmpData[j][i] = value;
                        tmpData[i][j] = value;
                    }
                }
            }
        }
        instance.close();
    } else std::cout << "Unable to open file" << path;

    TSP tsp(dimension, tmpData);
    return tsp;
}
