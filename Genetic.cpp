#include "Genetic.h"
#include <chrono>
#include <random>
#include <fstream>
#include <utility>

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
    for(int i=0; i<verticesNumber; i++){
        for(int j=0;j<verticesNumber;j++){
            cout<<newRoutes[i][j]<<" ";
        }
        cout<<endl;
    }
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

vector<int> Genetic::generateRandomPath() const{
    std::random_device rd;
    std::mt19937 generator(rd());
    vector<int> randomPath = getDefaultPath();
    shuffle(randomPath.begin(), randomPath.end(), generator);
    return randomPath;
}

vector<vector<int>> Genetic::generateInitialPopulation(int populationSize) const {
    vector<vector<int>> population;
    vector<int> populationMember;
    for(int i=0; i<populationSize; i++){
        populationMember = generateRandomPath();
        population.push_back(populationMember);
    }
    return population;
}

void Genetic::solveTSPUsingGeneticAlgorithm() {
    auto start = std::chrono::high_resolution_clock::now();
    vector<vector<int>> population = generateInitialPopulation(30);
    vector<vector<int>> newPopulation;
    vector<vector<int>> filteredPopulation;
    int sizeOfTournament = 5;
    while(true){
        for(int i=0; i<population.size(); i++){
            int randomIndex = rand()%population.size();
            vector<int> bestPathOfTournament = population[randomIndex];
            for(int j=0; j<sizeOfTournament-1; j++){
                randomIndex = rand()%population.size();
                if(getPathCost(population[randomIndex])< getPathCost(bestPathOfTournament)){
                    bestPathOfTournament = population[randomIndex];
                }
            }
            newPopulation.push_back(bestPathOfTournament);
        }
        for(int i=0; i<population.size(); i++){
            population[i].clear();
            population[i] = newPopulation[i];
            newPopulation[i].clear();
        }

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        if(elapsed.count() > timeLimit){
            break;
        }
    }
    cout<<"path: "<<endl;
    for(int i : path){
        cout<<i<<" ";
    }
    cout<<path[0]<<endl;
    cout<<"Total cost: "<<getPathCost(path)<<endl;
    cout<<endl<<endl;
}

void Genetic::orderCrossover(){

}

void Genetic::partiallyMatchedCrossover(){

}

void Genetic::inversionMutation(vector<int> &pathToMutate){

}

void Genetic::scrambleMutation(vector<int> &pathToMutate){
    int k = rand()%verticesNumber;
    for(int i=0; i<k; i++){

    }
}
