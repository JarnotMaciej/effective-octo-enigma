//
// Created by menox on 09.05.2023.
//

#ifndef TAMAGOTCHI_BOTTOMBUTTON_H
#define TAMAGOTCHI_BOTTOMBUTTON_H

// C++
#include <iostream>
#include <string>

// SFML
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

// headers
#include "../assetManager.h"

/**
 * @brief Bottom button class
 */
class bottomButton {
private:
    sf::Texture buttonTexture; // texture of the button
    sf::Sprite sprite; // sprite of the button
    sf::Text buttonName; // name of the button

public:
    /**
     * @brief Constructor of the bottom button
     * @param name name of the button
     * @param texture texture of the button
     */
    bottomButton(const std::string &name, const std::string &texture);

    /**
     * @brief Draws the button
     * @param window window to draw the button
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Sets the position of the button
     * @param x x coordinate
     * @param y y coordinate
     */
    void setPosition(float x, float y);

    /**
     * @brief Returns the sprite of the button
     * @return sprite of the button
     */
    sf::Sprite getSprite() { return sprite; }
};


#endif //TAMAGOTCHI_BOTTOMBUTTON_H
