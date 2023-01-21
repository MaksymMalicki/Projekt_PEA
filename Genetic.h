#include <iostream>
#include <vector>

using namespace std;

class Genetic {
public:
    int verticesNumber;
    vector<vector<int>> routes;
    vector<int> path;
    double mutationRate = 0.01;
    double crossoverRate = 0.8;
    int mutationType;
    int timeLimit = 120;
    int populationSize;

    void readDataFromFile(const string& fileName);
    int getPathCost(vector<int> pathInstance);
    vector<int> getDefaultPath() const;
    void solveTSPUsingGeneticAlgorithm();
    vector<int> orderCrossover(vector<int> firstParent, vector<int> secondParent) const;
    vector<int> inversionMutation(vector<int> pathToMutate) const;
    vector<int> swapMutation(vector<int> pathToMutate) const;
};
