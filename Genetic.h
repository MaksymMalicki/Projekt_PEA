#include <iostream>
#include <vector>

using namespace std;

class Genetic {
public:
    int verticesNumber = 48;
    vector<vector<int>> routes;
    vector<int> path;
    double temperature;
    double coolingRatio = 0.9999999;
    int timeLimit = 10;

    void readDataFromFile(const string& fileName);
    int getPathCost(vector<int> pathInstance);
    vector<int> getDefaultPath() const;
    vector<int> generateRandomPath() const;
    vector<vector<int>> generateInitialPopulation(int populationSize) const;
    void solveTSPUsingGeneticAlgorithm();

    void orderCrossover();

    void partiallyMatchedCrossover();

    void scrambleMutation(vector<int> &pathToMutate);

    void inversionMutation(vector<int> &pathToMutate);
};
