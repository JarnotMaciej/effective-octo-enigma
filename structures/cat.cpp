//
// Created by menox on 03.05.2023.
//

#include "cat.h"

void cat::meow() {
    // random meow
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


