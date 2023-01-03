#include "Menu.h"

using namespace std;

int main() {
    srand(time(nullptr));
    Menu menu = Menu();
    menu.displayMenu();
    return 0;
}
