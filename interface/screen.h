//
// Created by menox on 06.04.2023.
//

#ifndef PROJECT_NAME_SCREEN_H
#define PROJECT_NAME_SCREEN_H

// SFML
#include "SFML/Graphics.hpp"

// C++

// Header files

/**
 * @brief Class for screen
 */
class screen {
public:
    virtual void handleInput(sf::RenderWindow &window) = 0; // input handler
    virtual void draw(sf::RenderWindow &window) = 0; // render window
    virtual void setPositions(sf::RenderWindow &window) = 0; // set positions
};

#endif //PROJECT_NAME_SCREEN_H
