//
// Created by gabri on 09/11/2020.
//

#ifndef MODULE1_GRASP_H
#define MODULE1_GRASP_H


#include "../problem/TSP.h"

struct RCLElement {
    int node;
    int value;

    RCLElement(int node, int value) : node(node), value(value) {}
    RCLElement(){}
    bool operator<(const RCLElement &rhs) const {
        return value < rhs.value;
    }

    bool operator>(const RCLElement &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const RCLElement &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const RCLElement &rhs) const {
        return !(*this < rhs);
    }

};

class Grasp {
private:
    int maxIterations;
    int route_size;
    TSP *problem;
    std::vector<int> best_solution;
    int cost_best_solution;

    std::vector<int> twoOptSwap(const std::vector<int> &route, int i, int k);
    std::vector<int> greedyRandomizedConstruction();
    std::vector<int> localSearch(std::vector<int> solution);

    std::vector<RCLElement> createRCL(const std::vector<int> &partialSolution, const std::vector<int> &setCandidates);

public:
    Grasp(int maxIterations, TSP *problem, int routeSize);

    virtual ~Grasp();

    std::vector<int> run();


};


#endif //MODULE1_GRASP_H
