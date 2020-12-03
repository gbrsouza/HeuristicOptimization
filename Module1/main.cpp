#include <iostream>
#include <algorithm>
#include <limits.h>
#include <chrono>
#include "problem/TSP.h"
#include "problem/TSPReader.h"
#include "heuristic/LHK.h"
#include "heuristic/Grasp.h"
#include <thread>



int main() {
    std::string path = R"(C:\Users\gabri\Documents\codigos\HeuristicOptimization\Module1\instance\brazil58.tsp)";

    int rounds = 1;
    for (int i=0; i<rounds; i++){
        TSP tsp = TSPReader::loadInstance(path);
        std::cout << tsp << std::endl;

        //
        Grasp grasp = Grasp(100, &tsp, (int)tsp.getDimension()+1);

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        auto bestSolution = grasp.run();
        tsp.setBestSolution(bestSolution);
        LHK lhk =  LHK(tsp, (int)tsp.getDimension()+1);
        auto costLHK = lhk.run();
        std::cout << "Cost after LHK: " << costLHK << std::endl;
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        int duration_in_milisseconds = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
        std::cout << "time(ms)" << duration_in_milisseconds << std::endl;
    }


//    std::cout << "res: " << res << std::endl;

//    int min=INT_MAX;
//    int max=INT_MIN;
//    int avg=0;
//    int avg_time = 0;
//    for (int i=0; i<rounds; i++){
//        if (results[i]<min) min = results[i];
//        if (results[i]>max) max = results[i];
//        avg += results[i];
//        avg_time += times[i];
//    }
//
//    std::cout << "min: " << min << "\n max: " << max << "\navg: " << avg/rounds << std::endl;
//    std::cout << "time avg: " << avg_time << std::endl;

    return 0;
}
