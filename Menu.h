#include "BruteForce.h"
#include "DynamicTSP.h"
#include "SimulatedAnnealing.h"
#include "TabuSearch.h"
#include "Genetic.h"

class Menu {
public:
    BruteForce bf = BruteForce();
    DynamicTSP dp = DynamicTSP();
    SimulatedAnnealing sa = SimulatedAnnealing();
    TabuSearch ts = TabuSearch();
    Genetic ga = Genetic();
    void displayMenu();
    void displayBFMenu();
    void displayDPMenu();
    void displayHeuristicsMenu();
    void displayGeneticAlgorithmMenu();
};

