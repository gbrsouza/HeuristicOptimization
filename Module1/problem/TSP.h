//
// Created by gabri on 11/10/2020.
//

#ifndef MODULE1_TSP_H
#define MODULE1_TSP_H


#include <string>
#include <ostream>
#include <vector>


class TSP {
private:
    unsigned int dimension;
    unsigned int sizeSolution;
    int **data;
    int *bestSolution;
    int bestCost;

    int* genRandomSolution();

public:

    TSP(unsigned int dimension, int **data);

    virtual ~TSP();

    friend std::ostream &operator<<(std::ostream &os, const TSP &tsp);

    unsigned int getDimension() const;

    void update_solution_to_random_solution();

    void setDimension(unsigned int dimension);

    int *getBestSolution() const;

    void setBestSolution1(int *bestSolution);

    int getBestCost() const;

    void setBestCost(int bestCost);

    int **getData() const;

    void setData(int **data);

    void setBestSolution2(int *bestSolution);

    int getCost(int a, int b);

    void setEdgeCost(int a, int b, int cost);

    void setBestSolution(int *newBestSolution);

    bool isValidSolution(const int *solution);

    bool isValidSolution(std::vector<int> solution);

    int costOfSolution (const int *solution);
    int costOfSolution (const std::vector<int> &solution);

    int getEdgeCost (const int a, const int b);

    int costOfPartialSolution(const int partialSolution[], int size);


    void setBestSolution(std::vector<int> newBestSolution);
};


#endif //MODULE1_TSP_H
