//
// Created by Maksym Malicki on 26/10/2022.
//

#ifndef PROJECT1_DYNAMICTSP_H
#define PROJECT1_DYNAMICTSP_H
#include "TSP.h"
#include <vector>
#include <string>

using namespace std;

class DynamicTSP : public TSP{
public:
    void findBestSolutionUsingDynamicApproach(bool showLogs);
    int getMinWeight(vector<vector<int>> &memo, int mask, int startCity);
    vector<int> findOptimalPath(vector<vector<int>> memo, vector<int> path);
    void measureTime();
};


#endif //PROJECT1_DYNAMICTSP_H
