#include "Menu.h"
#include "Genetic.h"
using namespace std;

int main() {
    srand(time(nullptr));
//    Menu menu = Menu();
//    menu.displayMenu();
    Genetic g = Genetic();
    g.verticesNumber = 11;
    vector<int> path1 = {1,2,3,4,5,6,7,8,9,10,11};
    vector<int> path2 = {9,3,2,4,5,1,6,7,8,10,11};
//    g.inversionMutation(path1);
//    g.scrambleMutation(path1);
    g.orderCrossover(path1, path2);
    return 0;
}
