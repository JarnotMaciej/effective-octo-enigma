//
// Created by menox on 01.04.2023.
//

// SFML
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

// C++

// Header files
#include "../assetManager.h"
#include "../../functions.h"

#ifndef TAMAGOTCHI_MENU_PROGRAMLOGO_H
#define TAMAGOTCHI_MENU_PROGRAMLOGO_H

/**
 * @brief Class for program logo
 */
class programLogo {
private:
    sf::Text logoText; // text on button
    sf::Font font; // font for text
public:

    /**
     * @brief Default constructor for programLogo
     */
    programLogo();

    /**
     * @brief Method used for drawing programLogo
     * @param window - window to draw programLogo on
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Method used for getting x position of programLogo
     * @return x position of programLogo
     */
    float getPositionX();

    /**
     * @brief Method used for getting y position of programLogo
     * @return y position of programLogo
     */
    float getPositionY();

    /**
     * @brief Method used for getting width of programLogo
     * @return width of programLogo
     */
    float getWidth();

    /**
     * @brief Method used for getting height of programLogo
     * @return height of programLogo
     */
    float getHeight();

    /**
     * @brief Method used for setting position of programLogo
     * @param x - x position of programLogo
     * @param y - y position of programLogo
     */
    void setPosition(float x, float y);

};

#endif //TAMAGOTCHI_MENU_PROGRAMLOGO_H
