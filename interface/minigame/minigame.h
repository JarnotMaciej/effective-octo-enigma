//
// Created by menox on 06.05.2023.
//

// C++
#include <iostream>
#include <string>
#include <vector>

// header files
#include "../screen.h"
#include "../assetManager.h"
#include "coin.h"

#ifndef PROJECT_NAME_MINIGAME_H
#define PROJECT_NAME_MINIGAME_H

/**
 * @brief Class for minigame
 */
class minigame : public screen {
private:
    int time; // time in seconds
    int coins; // coins earned in minigame
    sf::Texture texture; // texture of the player
    sf::Sprite sprite; // sprite of the player
    sf::Text timeText; // text of the time
    sf::Text coinsText; // text of the coins
    short int maxCoins; // max coins to spawns
    std::vector<coin> coinsVector; // vector of coins
    sf::Clock minigameClock; // clock for minigame
    sf::Clock coinClock; // clock for spawning coins

public:

/**
 * @brief Construct a new minigame object
 * 
 * @param _textureName  - name of texture to be loaded
 */
    minigame(std::string textureName);

    /**
     * @brief Method used for handling input
     * @param window - window to handle input on
     */
    void handleInput(sf::RenderWindow &window) override;

    /**
     * @brief Method used for drawing menu
     * @param window - window to draw menu on
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Method used for setting positions of buttons and logo
     * @param window - window to set positions on
     */
    void setPositions(sf::RenderWindow &window) override;

    /**
     * @brief Method used for updating minigame
     */
    void update(sf::RenderWindow &window);
};


#endif //PROJECT_NAME_MINIGAME_H
