//
// Created by Maksym Malicki on 26/10/2022.
//

#include "DynamicTSP.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


void printVector(vector<vector<int>> vec, int verticesNumber){
    for(int i=0; i<verticesNumber; i++){
        for(int j=0;j<verticesNumber;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DynamicTSP::findBestSolutionUsingDynamicApproach(bool showLogs) {
    cout<<"vertices: "<<verticesNumber<<endl;
    vector<vector<int>> pathCostMemory(verticesNumber, vector<int>((1<<verticesNumber)-1, -1));
    int minWeight = getMinWeight(pathCostMemory, 1, 0);
    vector<int> optimalPath = findOptimalPath(pathCostMemory, {});
    if(showLogs){
        cout<<"Minimal weight: "<<minWeight<<endl;
        cout<<"Path: "<<endl;
        for(int i : optimalPath){
            cout<<i<<" ";
        }
        cout<<endl;

    }
}

int DynamicTSP::getMinWeight(vector<vector<int>> &pathCostMemory, int mask, int startCity) {
    if(mask == (1<<verticesNumber)-1) return routes[startCity][0];
    if(pathCostMemory[startCity][mask]!=-1) return pathCostMemory[startCity][mask];
    int cost = INT_MAX;

    for(int i=0; i<verticesNumber; i++){
        if((mask&(1<<i))==0){
            int newCostForGivenMask = routes[startCity][i]
                    + getMinWeight(pathCostMemory, (mask^(1<<i)), i);
            if(cost>newCostForGivenMask){
                cost = newCostForGivenMask;
            }
        }
    }
    pathCostMemory[startCity][mask] = cost;
    return cost;
}

vector<int> DynamicTSP::findOptimalPath(vector<vector<int>> pathCostMemory, vector<int> path){
    int mask = 1;
    int startCity = startNode;
    int totalCost = 0;
    path.push_back(startCity);
    for(int j=0; j<verticesNumber-1; j++){
        int newCity = 0;
        int cost=INT_MAX;
        for(int i=0; i<verticesNumber; i++){
            if(i!=startNode && (mask&(1<<i))==0){
                if(routes[startCity][i]+pathCostMemory[i][mask|(1<<i)]<=cost){
                    newCity=i;
                    cost = routes[startCity][i]+pathCostMemory[i][mask|(1<<i)];
                }
            }
        }
        totalCost += routes[startCity][newCity];
        path.push_back(newCity);
        mask = mask^(1<<newCity);
        startCity = newCity;
    }
    totalCost += routes[startCity][startNode];
    cout<<"Minimal weight (path finder): "<<totalCost<<endl;
    path.push_back(startNode);
    return path;
}

void DynamicTSP::measureTime() {
    for(int instanceVerticesNumbers: DPinstanceVerticesNumbers){
        auto start_time = std::chrono::high_resolution_clock::now();
        for(int i=0;i<repeats;i++){
            generateRandomRoutes(instanceVerticesNumbers, false);
            findBestSolutionUsingDynamicApproach(false);
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = (end_time - start_time)/repeats;
        cout << "For " << instanceVerticesNumbers << " it took " <<time/chrono::milliseconds(1) << "ms to run.\n";
    }
}