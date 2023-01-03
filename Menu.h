#include "BruteForce.h"
#include "DynamicTSP.h"
#include "SimulatedAnnealing.h"
#include "TabuSearch.h"


class Menu {
public:
    BruteForce bf = BruteForce();
    DynamicTSP dp = DynamicTSP();
    SimulatedAnnealing sa = SimulatedAnnealing();
    TabuSearch ts = TabuSearch();
    void displayMenu();
    void displayBFMenu();
    void displayDPMenu();
    void displayHeuristicsMenu();
};

