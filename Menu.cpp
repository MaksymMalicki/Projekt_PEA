#include "Menu.h"
#include "DynamicTSP.h"
#include "BruteForce.h"
#include <iostream>
using namespace std;

void Menu::displayMenu() {
    int option = 0;
    while (option > 3 || option < 1) {
        cout << "Wybierz opcje z menu ponizej!" << endl;
        cout << "1. Algorytm przeglądu zupelengo" << endl;
        cout << "2. Algorytmy programowania dynamicznego" << endl;
        cout << "3. Algorytmy symulowanego wyzarzania i tabu search"<<endl;
        cout << "Podaj liczbe 1-3: ";
        cin >> option;
    }
    switch (option) {
        case 1:
            displayBFMenu();
            break;
        case 2:
            displayDPMenu();
            break;
        case 3:
            displayHeuristicsMenu();
            break;
        default:
            break;
    }
}
void Menu::displayBFMenu() {
    int option = 0;
    while (option > 4 || option < 1) {
        cout << "Brute Force:"<<endl;
        cout << "Wybierz opcje z menu ponizej!" << endl;
        cout << "1. Wczytaj graf z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Włącz algorytm" << endl;
        cout << "4. Wykonaj testy" << endl;
        cout << "Podaj liczbe 1-4: ";
        cin >> option;
    }
    string dir;
    int size = 0;
    switch (option) {
        case 1:
            cout << "Podaj sciezke do pliku z danymi:";
            cin >> dir;
            bf.readRoutesFromFile("test-data/"+dir);
            displayBFMenu();
            break;
        case 2:
            cout << "Podaj wielkosc: ";
            cin >> size;
            bf.generateRandomRoutes(size, true);
            displayBFMenu();
            break;
        case 3:
            bf.findBestSolutionUsingExhaustiveSearch(true);
            displayBFMenu();
            break;
        case 4:
            bf.measureTime();
            displayBFMenu();
            break;
        default:
            break;
    }
}

void Menu::displayDPMenu() {
    int option = 0;
    while (option > 4 || option < 1) {
        cout << "Podejście dynamiczne" << endl;
        cout << "Wybierz opcje z menu ponizej!" << endl;
        cout << "1. Wczytaj graf z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Włącz algorytm" << endl;
        cout << "4. Przeprowadz testy" << endl;
        cout << "Podaj liczbe 1-4: ";
        cin >> option;
    }
    string dir;
    int size = 0;
    switch (option) {
        case 1:
            cout << "Podaj sciezke do pliku z danymi:";
            cin >> dir;
            dp.readRoutesFromFile("test-data/" + dir);
            displayDPMenu();
            break;
        case 2:
            cout << "Podaj wielkosc: ";
            cin >> size;
            dp.generateRandomRoutes(size, true);
            displayDPMenu();
            break;
        case 3:
            dp.findBestSolutionUsingDynamicApproach(true);
            displayDPMenu();
            break;
        case 4:
            dp.measureTime();
            displayDPMenu();
            break;
        default:
            break;
    }
}

void Menu::displayHeuristicsMenu() {
    int option = 0;
    while (option > 5 || option < 1) {
        cout << "Symulowane wyzarzanie i Tabu Search" << endl;
        cout << "Wybierz opcje z menu ponizej!" << endl;
        cout << "1. Wczytaj graf z pliku" << endl;
        cout << "2. Podaj kryterium stopu" << endl;
        cout << "3. Wlacz algorytm Tabu Search" << endl;
        cout << "4. Podaj wspolczynnik wychladzania" << endl;
        cout << "5. Wlacz algorytm Symulowanego Wyzarzania" << endl;
        cout << "Podaj liczbe 1-5: ";
        cin >> option;
    }
    string dir;
    int timeLimit = 0;
    double coolingRatio = 0;
    switch (option) {
        case 1:
            cout << "Podaj sciezke do pliku z danymi:";
            cin >> dir;
            sa.readDataFromFile("test-data/" + dir);
            ts.readDataFromFile("test-data/" + dir);
            displayHeuristicsMenu();
            break;
        case 2:
            cout << "Podaj wartosc kryterium stopu (w sekundach) ";
            cin >> timeLimit;
            sa.timeLimit = timeLimit;
            ts.timeLimit = timeLimit;
            displayHeuristicsMenu();
            break;
        case 3:
            ts.solveTSPUsingTabuSearch();
            displayHeuristicsMenu();
            break;
        case 4:
            cout << "Podaj wspolczynnik wychladzania (zalecany 0.9999999)";
            cin >> coolingRatio;
            sa.coolingRatio = coolingRatio;
            displayHeuristicsMenu();
            break;
        case 5:
            sa.solveTSPUsingSimulatedAnnealing();
            displayHeuristicsMenu();
        default:
            break;
    }
}

