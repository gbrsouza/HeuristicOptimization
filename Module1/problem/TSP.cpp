//
// Created by gabri on 11/10/2020.
//

#include <chrono>
#include <random>
#include <algorithm>
#include <iostream>
#include "TSP.h"

TSP::TSP(unsigned int dimension, int **data) : dimension(dimension), data(data) {
    this->sizeSolution = dimension+1;
    this->setBestSolution(this->genRandomSolution());
    this->setBestCost(this->costOfSolution(this->bestSolution));
}

TSP::~TSP() {
    for (int i=0; i<dimension; i++)
        free(this->data[i]);
    free(this->data);

    free(this->bestSolution);
}

int TSP::getCost(int a, int b) {
    return this->data[a][b];
}

void TSP::setEdgeCost(int a, int b, int cost) {
    this->data[a][b] = cost;
}

void TSP::setBestSolution(int *newBestSolution) {
    this->bestSolution = newBestSolution;
}

void TSP::setBestSolution(std::vector<int> newBestSolution) {
    for(int i=0; i<this->sizeSolution; i++){
        bestSolution[i] = newBestSolution[i];
    }
    bestCost = costOfSolution(newBestSolution);
}

bool TSP::isValidSolution(const std::vector<int> solution){
    int *tmpSolution = static_cast<int *>(malloc(sizeof(int) * solution.size()));
    for (int i=0; i<solution.size();i++)
        tmpSolution[i] = solution[i];
    bool res = isValidSolution(tmpSolution);
    free(tmpSolution);
    return res;
}

bool TSP::isValidSolution(const int *solution) {
    // check if return to start pointer
    if (solution[0] != solution[sizeSolution]) return false;

    // check that there is no repetition
    for (int i=1; i<sizeSolution; i++){
        for (int j=1; j<sizeSolution; j++){
            if (j!=i and solution[i] == solution[j]) return false;
        }
    }

    // check if all ways are possible
    int startPointer, endPointer;
    for (int i=0; i<sizeSolution; i++){
        startPointer = solution[i];
        endPointer = solution[i+1];
        if (this->data[startPointer][endPointer] == -1 or this->data[startPointer][endPointer] == 0)
            return false;
    }

    return true;
}

int *TSP::genRandomSolution() {
    std::vector<int> startSolution;
    for (int i=0; i<dimension; i++)
        startSolution.push_back(i);

    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    do {
        std::shuffle(startSolution.begin(), startSolution.end(), e);
        startSolution.push_back(startSolution[0]);
    }while(isValidSolution(startSolution));

    int *solution = static_cast<int *>(malloc(sizeof(int) * startSolution.size()));
    for (int i=0; i<startSolution.size(); i++)
        solution[i] = startSolution[i];

    return solution;
}

unsigned int TSP::getDimension() const {
    return dimension;
}

void TSP::setDimension(unsigned int dimension) {
    TSP::dimension = dimension;
}

int *TSP::getBestSolution() const {
    return bestSolution;
}




int TSP::getBestCost() const {
    return bestCost;
}

void TSP::setBestCost(int bestCost) {
    TSP::bestCost = bestCost;
}

int **TSP::getData() const {
    return data;
}

void TSP::setData(int **data) {
    TSP::data = data;
}

void TSP::setBestSolution2(int *bestSolution) {
    TSP::bestSolution = bestSolution;
}

std::ostream &operator<<(std::ostream &os, const TSP &tsp) {
    os << "dimension: " << tsp.dimension << "\n bestSolution: ";
    for (auto i=0; i<tsp.sizeSolution; i++)
        os << tsp.bestSolution[i] << " ";

    os << "\n bestCost: " << tsp.bestCost << "\n";
//    for (auto i=0; i<tsp.dimension; i++){
//        for (auto j=0; j<tsp.dimension; j++)
//            os << tsp.data[i][j] << " ";
//        os << " \n";
//    }
    return os;
}

int TSP::costOfSolution(const int *solution) {
    int cost = 0;
    for (int i=0; i<this->sizeSolution-1; i++) {
        cost += this->data[solution[i]][solution[i + 1]];
    }

    return cost;
}

int TSP::costOfPartialSolution(const int partialSolution[], int size){
    int cost = 0;
    for (int i=0; i<size-1; i++){
        cost += this->data[partialSolution[i]][partialSolution[i+1]];
    }

    return cost;
}

int TSP::getEdgeCost(const int a, const int b) {
    return data[a][b];
}

int TSP::costOfSolution(const std::vector<int> &solution) {
    int cost = 0;
    for (int i=0; i<this->sizeSolution-1; i++) {
        cost += this->data[solution[i]][solution[i + 1]];
    }

    return cost;
}


