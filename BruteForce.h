//
// Created by Maksym Malicki on 25/10/2022.
//

#ifndef PROJECT1_BRUTEFORCE_H
#define PROJECT1_BRUTEFORCE_H
#include <vector>
#include "TSP.h"
using namespace std;

class BruteForce : public TSP {
public:
    int getRouteWeight(vector<int> route);
    void findBestSolutionUsingExhaustiveSearch(bool displayLogs);
    void measureTime();
};


#endif //PROJECT1_BRUTEFORCE_H