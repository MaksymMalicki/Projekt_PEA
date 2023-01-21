#include "Genetic.h"
#include <chrono>
#include <random>
#include <fstream>
#include <utility>
#include <cstdlib>
void Genetic::readDataFromFile(const string& fileName) {
    ifstream input_file(fileName);
    if(!input_file.is_open()){
        cout<<"Nie udalo sie otworzyc pliku!"<<endl;
        return;
    }
    input_file>>verticesNumber;
    vector<vector<int>> newRoutes(verticesNumber, vector<int>(verticesNumber, 0));
    for(int i=0; i<verticesNumber; i++){
        for(int j=0;j<verticesNumber;j++){
            input_file>>newRoutes[i][j];
        }
    }

    routes = newRoutes;
    cout<<verticesNumber<<endl;
    input_file.close();
}

void printVector(vector<int> vec){
    for(int i : vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

int Genetic::getPathCost(vector<int> pathInstance) {
    int cost = 0;
    for(int i=1; i<pathInstance.size(); i++){
        cost += routes[pathInstance[i-1]][pathInstance[i]];
    }
    cost += routes[pathInstance[pathInstance.size()-1]][pathInstance[0]];
    return cost;
}

vector<int> Genetic::getDefaultPath() const{
    vector<int> newPath = {};
    for(int i=0; i<verticesNumber; i++){
        newPath.push_back(i);
    }
    return newPath;
}

void Genetic::solveTSPUsingGeneticAlgorithm() {
    auto start = std::chrono::high_resolution_clock::now();
    vector<vector<int>> population;
    vector<int> permutation = getDefaultPath();
    for (int i = 0; i < populationSize; i++) {
        shuffle(permutation.begin(), permutation.end(), std::mt19937(std::random_device()()));
        population.push_back(permutation);
    }
    vector<int> result = population[0];
    for(vector<int> populationPath: population){
        if(getPathCost(populationPath)< getPathCost(result)){
            result = populationPath;
        }
    }
    vector<int> measureTimes;
    int sizeOfTournament = 4;
    while(true){
        vector<vector<int>> newPopulation;
        for(int i=0; i<populationSize; i++){
            int tournamentResult = INT_MAX;
            for(int j=0; j<sizeOfTournament; j++){
                int randomIndex = rand()%populationSize;
                if(getPathCost(population[randomIndex])< tournamentResult){
                    tournamentResult = getPathCost(population[randomIndex]);
                    permutation = population[randomIndex];
                }
            }
            newPopulation.push_back(permutation);
        }
        population = newPopulation;
        random_device rd;
        mt19937 g(rd());
        uniform_real_distribution<double> crossoverDistribution(0, 1);
        for(int i=0; i<populationSize-1; i=i+2){
            double crossoverProbability = crossoverDistribution(g);
            vector<int> firstChild, secondChild;
            if(crossoverProbability <= crossoverRate){
                int p1, p2;
                do {
                    p1 = rand() % populationSize;
                    p2 = rand() % populationSize;
                } while (!(p1 - p2));
                firstChild = orderCrossover(newPopulation[p1], newPopulation[p2]);
                secondChild = orderCrossover(newPopulation[p2], newPopulation[p1]);
                population[i] = firstChild;
                population[i + 1] = secondChild;
            }
        }
        for(int i=0; i<populationSize; i++){
            uniform_real_distribution<double> mutationDistribution(0, 1);
            double mutationProbability = mutationDistribution(g);
            if(mutationProbability <= mutationRate) {
                vector<int> afterMutation;
                int randomIndex = rand() % populationSize;
                if (mutationType == 1) {
                    afterMutation = inversionMutation(population[randomIndex]);
                } else if (mutationType == 2) {
                    afterMutation = swapMutation(population[randomIndex]);
                }
                population[randomIndex] = afterMutation;
            }
        }

        for(const vector<int>& populationPath: population){
            if(getPathCost(populationPath)< getPathCost(result)){
                result = populationPath;
            }
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        int timeNow = int(elapsed.count());
        if(std::find(measureTimes.begin(), measureTimes.end(), timeNow) == measureTimes.end() && timeNow%10==0){
            measureTimes.push_back(timeNow);
            cout<<timeNow<<": "<<getPathCost(result)<<endl;
        }
        if(elapsed.count() > timeLimit){
            break;
        }
    }
    cout<<"path: "<<endl;
    for(int i : result){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Total cost: "<<getPathCost(result)<<endl;
    cout<<endl<<endl;
}

bool isElementInVector(const vector<int>& v, int element){
    for(int i : v){
        if(i==element) return true;
    }
    return false;
}

vector<int> Genetic::orderCrossover(vector<int> firstParent, vector<int> secondParent) const{
    int subsetStartIndex;
    int subsetEndIndex;
    do {
        subsetStartIndex = rand() % verticesNumber;
        subsetEndIndex = rand() % verticesNumber;
    } while (!(subsetStartIndex - subsetEndIndex));
    if (subsetStartIndex > subsetEndIndex) swap(subsetStartIndex, subsetEndIndex);
    vector<int> child;

    child.resize(firstParent.size(), -1);
    for(int i=subsetStartIndex; i<subsetEndIndex+1; i++){
        child[i] = firstParent[i];
    }
    for(int i=(subsetEndIndex+1)%verticesNumber; i<(subsetEndIndex+1)%verticesNumber+verticesNumber; i++){
        int nextNumber = i;
        if(!isElementInVector(child, -1)){
            break;
        }
        while(isElementInVector(child, secondParent[nextNumber%verticesNumber])){
            nextNumber++;
        }
        child[i%verticesNumber] = secondParent[nextNumber%verticesNumber];
    }
    return child;
}

vector<int> Genetic::inversionMutation(vector<int> pathToMutate) const{
    int subsetStartIndex = rand()%(verticesNumber-1);
    int subsetEndIndex = rand()%verticesNumber;
    if(subsetStartIndex>subsetEndIndex) swap(subsetStartIndex, subsetEndIndex);
    reverse( pathToMutate.begin() + subsetStartIndex, pathToMutate.begin() + subsetEndIndex);
    return pathToMutate;
}

vector<int> Genetic::swapMutation(vector<int> pathToMutate) const {
    int p1, p2;
    do {
        p1 = rand() % verticesNumber;
        p2 = rand() % verticesNumber;
    } while (!(p1 - p2));
    swap(pathToMutate[p1], pathToMutate[p2]);
    return pathToMutate;
}

