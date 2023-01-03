//
// Created by Maksym Malicki on 26/10/2022.
//

#include "TSP.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std;

void TSP::generateRandomRoutes(int n, bool showLogs) {
    verticesNumber = n;
    vector<vector<int>> newRoutes(verticesNumber, vector<int>(verticesNumber, 0));
    for(int i=0; i<verticesNumber; i++){
        for(int j=0; j<verticesNumber; j++){
            int randomValue = rand()%10;
            newRoutes[i][j] = randomValue;
            newRoutes[j][i] = randomValue;
        }
    }
    for(int i=0; i<verticesNumber; i++){
        newRoutes[i][i] = -1;
    }
    if(showLogs){
        for(int i=0; i<verticesNumber; i++){
            for(int j=0;j<verticesNumber;j++){
                cout<<newRoutes[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    routes = newRoutes;
}

void TSP::readRoutesFromFile(string dir) {
    ifstream input_file(dir);
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
    for(int i=0; i<verticesNumber; i++){
        for(int j=0;j<verticesNumber;j++){
            cout<<newRoutes[i][j]<<" ";
        }
        cout<<endl;
    }
    routes = newRoutes;
    cout<<verticesNumber<<endl;
    input_file.close();
}

vector<int> TSP::getDefaultRoute() const{
    vector<int> defaultRoute;
    for(int i=0;i<verticesNumber;i++){
        defaultRoute.push_back(i);
    }
    return defaultRoute;
}


