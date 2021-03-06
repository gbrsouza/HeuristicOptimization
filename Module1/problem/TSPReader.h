//
// Created by gabri on 11/10/2020.
//

#ifndef MODULE1_TSPREADER_H
#define MODULE1_TSPREADER_H


#include <string>
#include "TSP.h"

struct EuclideanNode{
    int id;
    float x;
    float y;

    EuclideanNode(int id, float x, float y);

    static int calcCostEdge(const EuclideanNode& a, const EuclideanNode& b);

    virtual ~EuclideanNode();
};

class TSPReader {

public:

    static TSP loadInstance(const std::string& path);

};


#endif //MODULE1_TSPREADER_H
