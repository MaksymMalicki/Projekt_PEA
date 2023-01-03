//
// Created by Maksym Malicki on 26/10/2022.
//

#ifndef PROJECT1_TSP_H
#define PROJECT1_TSP_H
#include <vector>

using namespace std;

class TSP {
public:
    vector<vector<int> > routes;
    int verticesNumber=0;
    int startNode = 0;
    vector<int> instancesVerticesNumbers = {9,10,11,12,13,14,15};
    vector <int> DPinstanceVerticesNumbers = {19,20,21,22,23,24,25};
    int repeats = 1;

    void generateRandomRoutes(int verticesNumber, bool showLogs);
    void readRoutesFromFile(string fileName);
    vector<int> getDefaultRoute() const;

};


#endif //PROJECT1_TSP_H
