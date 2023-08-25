#include "cat.h"

void cat::meow() {
    int random = rand() % 3;
    switch (random) {
        case 0:
            std::cout << "Meow!" << std::endl;
            break;
        case 1:
            std::cout << "Miau!" << std::endl;
            break;
        case 2:
            std::cout << "Mrrr!" << std::endl;
            break;
        default:
            std::cout << "Meow!" << std::endl;
            break;
    }
}


