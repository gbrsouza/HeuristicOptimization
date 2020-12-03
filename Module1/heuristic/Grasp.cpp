//
// Created by gabri on 09/11/2020.
//

#include <random>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <ctime>
#include "Grasp.h"

Grasp::Grasp(int maxIterations, TSP *problem, int routeSize) : maxIterations(maxIterations), route_size(routeSize),
                                                               problem(problem) {}

Grasp::~Grasp() {

}

std::vector<int>Grasp::twoOptSwap(const std::vector<int> &route, int i, int k) {
    std::vector<int> newRoute(route.size());
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

    for (int f=k+1; f<route.size(); f++){
        newRoute[count] = route[f];
        count++;
    }

    if (i==0)
        newRoute[route.size()-1] = route[k];

//    for (int i=0; i<route_size; i++){
//        route[i] = newRoute[i];
//    }

//    std::cout << "fiz a troca\n";

    return newRoute;
}

std::vector<RCLElement> Grasp::createRCL (const std::vector<int> &partialSolution, const std::vector<int> &setCandidates){
    int sizeCandidates = setCandidates.size();
    int sizeSolution = partialSolution.size();

    int auxSolution[sizeSolution+1];
    for (int i=0; i<sizeSolution; i++)
        auxSolution[i] = partialSolution[i];

    // verificar o custo de inserção de cada elemento
    RCLElement elements[sizeCandidates];
    for (int i=0; i<sizeCandidates; i++){
        auxSolution[sizeSolution] = setCandidates[i];
        int cost = problem->costOfPartialSolution(auxSolution, sizeSolution+1);
        elements[i] = RCLElement(setCandidates[i], cost);
    }

    // selecionar os elementos da rcl com alpha=0.3
    // Find the size of the array
    int minCost = INT_MAX;
    int maxCost = 0;

    for (int i=0; i<sizeCandidates; i++){
        if (elements[i].value < minCost) minCost = elements[i].value;
        if (elements[i].value > maxCost) maxCost = elements[i].value;
    }

    std::vector<RCLElement> RCL;
    for (int i=0; i<sizeCandidates; i++){
        int limit = minCost + 0.3*(maxCost - minCost);
        if (elements[i].value <= limit)
            RCL.push_back(elements[i]);
    }

    return RCL;
}

std::vector<int> Grasp::greedyRandomizedConstruction() {
    std::vector<int> route;
    std::vector<int> set_candidates(route_size-1);

    for (int i=0; i<route_size-1; i++)
        set_candidates[i] = i;

    std::srand(std::time(0));
    auto randomPos = (std::rand()%(set_candidates.size()))+1;
    route.push_back(set_candidates[randomPos]);
    int actualSizeSolution = 1;

    auto index = std::find(set_candidates.begin(), set_candidates.end(), randomPos);
    set_candidates.erase(index);
    std::vector<RCLElement> RCL;
    while (!set_candidates.empty()){
        RCL = this->createRCL(route, set_candidates);
        randomPos = (std::rand() % (RCL.size())); // define the range

        route.push_back(RCL[randomPos].node);
        actualSizeSolution++;

        index = std::find(set_candidates.begin(), set_candidates.end(), RCL[randomPos].node);
        set_candidates.erase(index);
    }
    route.push_back(route[0]);
    return route;
}

std::vector<int> Grasp::run() {
    std::vector<int> bestSolution;
    int bestCost = INT_MAX;

    for (int i=0; i<maxIterations; i++){
        auto route = this->greedyRandomizedConstruction();
        route = this->localSearch(route);
        int cost = problem->costOfSolution(route);
        if (cost < bestCost){
            bestSolution = route;
            bestCost = cost;
        }
    }

    std::cout << "\n----------------\nbest Solution with GRASP\n----------------\n";
    for (int i=0; i< bestSolution.size(); i++)
        std::cout << bestSolution[i] << " ";
    std::cout << std::endl << "best cost: " << bestCost << std::endl;

    return bestSolution;
}

std::vector<int> Grasp::localSearch(std::vector<int> solution) {
    std::vector<int> auxSolution;
    int bestCost = problem->costOfSolution(solution);
    int loopsWithoutUpgrade = 0;
    while (loopsWithoutUpgrade < solution.size()){
        auto i = (std::rand() % (solution.size()-1));
        auto j = (std::rand() % (solution.size()-1));
        if (i != j){
            if (i < j) auxSolution = twoOptSwap(solution, i, j);
            else auxSolution = twoOptSwap(solution, j, i);
            int cost = problem->costOfSolution(auxSolution);
            if (cost < bestCost) {
                solution = auxSolution;
                bestCost = cost;
            }
            else loopsWithoutUpgrade++;
        }
    }
    return solution;
}


