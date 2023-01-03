#include "BruteForce.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int BruteForce::getRouteWeight(vector<int> route) {
    int weight=0;
    for(int i =0; i<route.size()-1; i++){
        weight+=routes[route[i]][route[i+1]];
    }
    weight+=routes[route[route.size()-1]][route[0]];
    return weight;
}

void BruteForce::findBestSolutionUsingExhaustiveSearch(bool displayLogs) {
    vector<int> route = getDefaultRoute();
    int lowestWeight = getRouteWeight(route);
    vector<int> bestRoute = route;
    while(next_permutation(route.begin() + 1, route.end())) {
        int currentWeight = getRouteWeight(route);
        if(lowestWeight > currentWeight){
            lowestWeight = currentWeight;
            bestRoute = route;
        }
    }
    if(displayLogs){
        cout<<"cost:"<<lowestWeight<<endl;
        cout<<"path:"<<endl;
        for(int i: bestRoute){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


void BruteForce::measureTime() {
    for(int instanceVerticesNumbers: instancesVerticesNumbers){
        auto start_time = std::chrono::high_resolution_clock::now();
        for(int i=0;i<repeats;i++){
            generateRandomRoutes(instanceVerticesNumbers, false);
            findBestSolutionUsingExhaustiveSearch(false);
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = (end_time - start_time)/repeats;
        cout << "For " << instanceVerticesNumbers << "it took " <<time/chrono::milliseconds(1) << "ms to run.\n";
    }
}