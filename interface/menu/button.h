#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <thread>
#include "../../mechanics/assetManager.h"
#include "../../functions.h"

#ifndef TAMAGOTCHI_MENU_BUTTON_H
#define TAMAGOTCHI_MENU_BUTTON_H

/**
 * @brief Class for button
 */
class button {
private:
    sf::Texture buttonTexture; // texture for button
    sf::Sprite buttonSprite; // sprite for button
    sf::Text buttonText; // text on button
    sf::Font font; // font for text
    sf::Color textColor; // color of text

public:

    /**
     * @brief Constructor for button
     * @param text - text on button
     * @param font - font for text
     * @param texture - texture for button
     */
    explicit button(const sf::String &text);

    /**
     * @brief Method used for drawing button
     * @param window - window to draw button on
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Method used for getting x position of button
     * @return x position of button
     */
    float getPositionX();

    /**
     * @brief Method used for getting y position of button
     * @return y position of button
     */
    float getPositionY();

    /**
     * @brief Method used for getting width of button
     * @return width of button
     */
    float getWidth();

    /**
     * @brief Method used for getting height of button
     * @return height of button
     */
    float getHeight();

    /**
     * @brief Method used for setting position of button
     * @param x - x position of button
     * @param y - y position of button
     */
    void setPosition(float x, float y);

    /**
     * @brief Method used for centering text on button
     */
    void centerText();

    /**
     * @brief Method used for checking if mouse is over button
     * @param window - window to check mouse position on
     * @return true if mouse is over button, false otherwise
     */
    bool isMouseOver(sf::RenderWindow &window);

};

#endif //TAMAGOTCHI_MENU_BUTTON_H
