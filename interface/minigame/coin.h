#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
#include "flyingElement.h"
#include "../../mechanics/assetManager.h"

#ifndef TAMAGOTCHI_MENU_COIN_H
#define TAMAGOTCHI_MENU_COIN_H

/**
 * @brief Class for button
 */
class coin : public flyingElement {
private:
    sf::Texture coinTexture; // texture of the coin
    sf::Sprite coinSprite; // sprite of the coin
    sf::Clock clock; // clock for animation
    static const int animationTime = 150; // time of animation in ms
    static const int animationFrames = 8; // number of animation frames
    int currentFrame = 0; // current animation frame
    std::vector<sf::Texture> animation; // vector of animation frames
    float speed; // speed of the coin

public:
    /**
     * @brief Default constructor
     */
    coin();

/**
 * @brief Method used for drawing
 * 
 * @param window - window to draw
 */
    void draw(sf::RenderWindow &window) override;

/**
 * @brief Set the Random Position object
 * 
 * @param window - window to set position on
 */
    void setRandomPosition(sf::RenderWindow &window);

/**
 * @brief Method used for moving the coindown
 */
    void update();

/**
 * @brief Get the Sprite object
 * 
 * @return sf::Sprite - sprite of the coin
 */
    sf::Sprite getSprite() { return coinSprite; }
};

#endif //TAMAGOTCHI_MENU_COIN_H
