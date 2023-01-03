#include <iostream>
#include <vector>

using namespace std;

class TabuSearch {
public:
    int verticesNumber = 48;
    int timeLimit = 5;
    vector<vector<int>> routes;
    vector<int> path;

    void readDataFromFile(string fileName);
    int getPathCost(vector<int> pathInstance);
    vector<int> getDefaultTabuPath();
    vector<int> generateRandomPath();
    void solveTSPUsingTabuSearch();
};

