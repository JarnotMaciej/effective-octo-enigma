//
// Created by menox on 01.04.2023.
//

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// C++
#include <iostream>

// Header files

#ifndef TAMAGOTCHI_MENU_FLYINGELEMENT_H
#define TAMAGOTCHI_MENU_FLYINGELEMENT_H

/**
 * @brief Class for flying element
 */
class flyingElement {
private:

public:
/**
 * @brief Method used for drawing
 * 
 * @param window - window to draw
 */
    virtual void draw(sf::RenderWindow &window) = 0;
};

#endif //TAMAGOTCHI_MENU_FLYINGELEMENT_H
