#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

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
