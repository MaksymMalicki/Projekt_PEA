cmake_minimum_required(VERSION 3.23)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp BruteForce.cpp DynamicTSP.cpp DynamicTSP.h TSP.cpp TSP.h Menu.cpp Menu.h SimulatedAnnealing.cpp SimulatedAnnealing.h TabuSearch.cpp TabuSearch.h Genetic.cpp Genetic.h)
