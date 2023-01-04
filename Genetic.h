#include <iostream>
#include <vector>

using namespace std;

class Genetic {
public:
    int verticesNumber = 48;
    vector<vector<int>> routes;
    vector<int> path;
    double mutationRate = 0.8;
    double crossoverRate = 0.8;
    int mutationType = 1;
    int timeLimit = 10;

    void readDataFromFile(const string& fileName);
    int getPathCost(vector<int> pathInstance);
    vector<int> getDefaultPath() const;
    vector<int> generateRandomPath() const;
    vector<vector<int>> generateInitialPopulation(int populationSize) const;
    void solveTSPUsingGeneticAlgorithm();

    vector<int> orderCrossover(vector<int> firstParent, vector<int> secondParent) const;

    vector<int> scrambleMutation(vector<int> &pathToMutate) const;

    vector<int> inversionMutation(vector<int> &pathToMutate) const;
};
