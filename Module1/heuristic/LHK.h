//
// Created by gabri on 15/10/2020.
//

#ifndef MODULE1_LHK_H
#define MODULE1_LHK_H


#include <ostream>
#include "../problem/TSP.h"

struct Edge {
    int first;
    int last;

    Edge(int first, int last) {
        this->first = first;
        this->last = last;
    }

    Edge(){
        this->first = -1;
        this->last = -1;
    }

    virtual ~Edge() {

    }

    bool isValidEdge(){
        return this->first != -1 and this->last != -1;
    }

    void setNewVertex(int first, int last){
        this->first = first;
        this->last = last;
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
        os << "["<< edge.first << "]->[" << edge.last << "]";
        return os;
    }

    bool operator==(const Edge &rhs) const {
        return first == rhs.first &&
               last == rhs.last;
    }

    bool operator!=(const Edge &rhs) const {
        return !(rhs == *this);
    }

};

class LHK {

private:
    TSP tsp;
    int gain;
    Edge *L_leaves;
    int sizeLLeaves;
    Edge *L_into;
    int sizeLInto;
    int route_size;
    int *actualRoute;

public:
    LHK(const TSP &tsp, int routeSize);

    virtual ~LHK();

private:

    static bool sequentialExchangeCriterion(const Edge& a, const Edge& b);
    bool feasibilityCriterion(const Edge& a, const Edge& b);
    bool positiveGainCriterion(const Edge& leave, const Edge& into);
    bool disjunctivityCriterion(const Edge& leave, const Edge& into);
    bool isManipulated(const Edge& edge);
    Edge selectEdgeLeave();
    int* twoOptSwap(int *route, int i, int k);
    int getEdgeCost(const Edge& edge);
    Edge selectsEnteringEdge(const Edge& leave);
    void addEdgeLeaveList(const Edge& leave);
    void addEdgeIntoList(const Edge& into);
    bool isValidSwap(const Edge& leave, const Edge& into);

public:
    int run();

};


#endif //MODULE1_LHK_H
