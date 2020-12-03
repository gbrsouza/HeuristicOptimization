//
// Created by gabri on 15/10/2020.
//

#include <iostream>
#include <climits>
#include "LHK.h"

int *LHK::twoOptSwap(int *route, int i, int k) {
    int newRoute[route_size];
    int count = 0;

//    std::cout << "criei a nova rota\n";

    for (int f=0; f<i; f++) {
        newRoute[count] = route[f];
        count++;
    }

    for (int f=k; f>=i; f--){
        newRoute[count] = route[f];
        count++;
    }

    for (int f=k+1; f<route_size; f++){
        newRoute[count] = route[f];
        count++;
    }

    if (i==0)
        newRoute[route_size-1] = route[k];

    for (int i=0; i<route_size; i++){
        route[i] = newRoute[i];
    }

//    std::cout << "fiz a troca\n";

    return route;
}

Edge LHK::selectEdgeLeave() {
    int maxEdgeCost = -1;
    Edge edgeToLeave = Edge();
    for (int i=0; i<route_size-2; i++){
        int costEdge = getEdgeCost(Edge(actualRoute[i], actualRoute[i+1]));
        if (costEdge > maxEdgeCost and !isManipulated(Edge(actualRoute[i], actualRoute[i+1]))){
            maxEdgeCost = costEdge;
            edgeToLeave.setNewVertex(i, i+1);
        }
    }
    return edgeToLeave;
}

Edge LHK::selectsEnteringEdge(const Edge& leave) {
    int minEdgeCost = INT_MAX ;
    Edge edgeToEnter = Edge();
    for (int i=0; i<route_size-1;  i++){
        if (i != leave.first) {
            int costEdge = getEdgeCost(Edge(actualRoute[leave.first], actualRoute[i]));
            if (costEdge < minEdgeCost and !isManipulated(Edge(actualRoute[leave.first], actualRoute[i]))) {
                minEdgeCost = costEdge;
                edgeToEnter.setNewVertex(leave.first, i);
            }
        }
    }
    return edgeToEnter;

//    for (int i=0; i<route_size-1;  i++){
//        if (i != leave.first) {
//            if (!isManipulated(Edge(actualRoute[leave.first], actualRoute[i]))) {
//                return Edge(leave.first, i);
//            } else if (!isManipulated(Edge(actualRoute[i], actualRoute[leave.first]))){
//                return Edge(i, leave.first);
//            }
//        }
//    }
//
//    for (int i=0; i<route_size-1;  i++){
//        if (i != leave.last) {
//            if (!isManipulated(Edge(actualRoute[leave.last], actualRoute[i]))) {
//                return Edge(leave.last, i);
//            } else if (!isManipulated(Edge(actualRoute[i], actualRoute[leave.last]))){
//                return Edge(i, leave.last);
//            }
//        }
//    }
//
//    return Edge(-1, -1);


}

int LHK::getEdgeCost(const Edge& edge) {
    return tsp.getCost(edge.first, edge.last);
}

int LHK::run() {
//    std::cout << "Solução Inicial:\n";
//    for (int i=0; i<route_size; i++)
//        std::cout << tsp.getBestSolution()[i] << " ";
//    std::cout << std::endl;


    while (true) {
//        std::cout << "Aresta que vai sair:";
        Edge e_leave = selectEdgeLeave();
//        std::cout << e_leave << std::endl;

        if (!e_leave.isValidEdge()) break;

//        std::cout << "Aresta que vai entrar:";
        Edge e_enter = selectsEnteringEdge(e_leave);
//        std::cout << e_enter << std::endl;

        if (!e_enter.isValidEdge()) break;

        Edge real_e_leave = Edge(actualRoute[e_leave.first], actualRoute[e_leave.last]);
        Edge real_e_enter = Edge(actualRoute[e_enter.first], actualRoute[e_enter.last]);
//        Edge real_e_leave_2 = Edge(actualRoute[e_enter.last], actualRoute[e_enter.last+1]);


        if (isValidSwap(e_leave, e_enter)) {
            addEdgeLeaveList(real_e_leave);
            addEdgeIntoList(real_e_enter);
//            addEdgeLeaveList(real_e_leave_2);

//            std::cout << "L_sai = [";
//            for (int p=0; p<sizeLLeaves; p++)
//                std::cout<< L_leaves[p] << ", ";
//            std::cout << std::endl << "L_entra = [";
//            for (int p=0; p<sizeLInto; p++)
//                std::cout<< L_into[p];
//            std::cout << std::endl;

//            if (e_leave.first == e_enter.first) {
            actualRoute =
                    e_leave.last < e_enter.last ? twoOptSwap(actualRoute, e_leave.last, e_enter.last) : twoOptSwap(
                            actualRoute, e_enter.last, e_leave.last);
//            } else if (e_leave.last == e_enter.last){
//                actualRoute =
//                        e_leave.first < e_enter.first ? twoOptSwap(actualRoute, e_leave.first, e_enter.first) : twoOptSwap(
//                                actualRoute, e_enter.first, e_leave.first);
//            }

//            std::cout << "nova rota:\n";
//            for (int i = 0; i < route_size; i++)
//                std::cout << actualRoute[i] << " ";
//            std::cout << std::endl;

            int cost = tsp.costOfSolution(actualRoute);
            //std::cout << "Novo Custo: " << cost << std::endl;
            if (cost < tsp.getBestCost()) {
                tsp.setBestSolution(actualRoute);
                tsp.setBestCost(cost);

            }
        }else break;
    }
    //std::cout << "condição de parada alcançada\n";
//    std::cout << tsp;
    return tsp.getBestCost();
}

LHK::LHK(const TSP &tsp, int routeSize) : tsp(tsp), route_size(routeSize) {
    this->gain = 0;
    this->L_leaves = static_cast<Edge *>(malloc(sizeof(Edge) * (routeSize*routeSize)));
    this->L_into = static_cast<Edge *>(malloc(sizeof(Edge) * (routeSize*routeSize)));
    this->actualRoute = static_cast<int *>(malloc(sizeof(int) * routeSize));
    for (int i=0; i<routeSize; i++)
        actualRoute[i] = tsp.getBestSolution()[i];
    this->sizeLInto = 0;
    this->sizeLLeaves = 0;
}

LHK::~LHK() {
    free(L_leaves);
    free(L_into);
    free(actualRoute);
}

bool LHK::sequentialExchangeCriterion(const Edge& a, const Edge& b) {
    return a.first == b.first or a.first == b.last;
}

bool LHK::feasibilityCriterion(const Edge& a, const Edge& b) {
    return true;
}

bool LHK::positiveGainCriterion(const Edge& leave, const Edge& into) {
    int totalGain = gain + (getEdgeCost(leave) - getEdgeCost(into));
    return totalGain>=0;
}

bool LHK::disjunctivityCriterion(const Edge& leave, const Edge& into) {
    for (int i=0; i<sizeLLeaves; i++)
        if (leave == L_leaves[i] or L_leaves[i] == into) return false;

    for (int i=0; i<sizeLInto; i++)
        if (into == L_into[i] or leave == L_leaves[i]) return false;
    return true;
}

void LHK::addEdgeLeaveList(const Edge& leave) {
    this->L_leaves[sizeLLeaves] = leave;
    sizeLLeaves++;
}

void LHK::addEdgeIntoList(const Edge& into) {
    this->L_into[sizeLInto] = into;
    sizeLInto++;
}

bool LHK::isManipulated(const Edge& edge) {
    for (int i=0; i<sizeLInto; i++)
        if (L_into[i] == edge or L_leaves[i] == edge) return true;

    return false;
}

bool LHK::isValidSwap(const Edge& leave, const Edge& into) {
    Edge e_leave = Edge(actualRoute[leave.first], actualRoute[leave.last]);
    Edge e_into = Edge(actualRoute[into.first], actualRoute[into.last]);
    return sequentialExchangeCriterion(e_leave, e_into) and
           feasibilityCriterion(e_leave, e_into) and
           disjunctivityCriterion(e_leave, e_into) and
           positiveGainCriterion(e_leave, e_into);
}



