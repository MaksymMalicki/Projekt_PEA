#include <iostream>
#include <vector>

using namespace std;

class SimulatedAnnealing {
public:
    int verticesNumber = 48;
    vector<vector<int>> routes;
    vector<int> path;
    double temperature;
    double coolingRatio = 0.9999999;
    int timeLimit = 10;

    void readDataFromFile(string fileName);
    int getPathCost(vector<int> pathInstance);
    void solveTSPUsingSimulatedAnnealing();
    double getInitialTemperature();
    vector<int> getDefaultPath(int range);
    vector<int> swapElementsInPath(int range, vector<int> oldPath);
};

