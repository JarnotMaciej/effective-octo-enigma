//
// Created by menox on 06.05.2023.
//

// C++
#include <iostream>
#include <string>
#include <vector>
#include <thread>

// header files
#include "../screen.h"
#include "../../mechanics/assetManager.h"
#include "coin.h"
#include "gameOver.h"
#include "minigameConnector.h"

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
    sf::Clock coinClock; // clock aaaadfor spawning coins
    bool isRunning; // is minigame running
    sf::Sound minigameSound; // sound of the coin
    sf::SoundBuffer coinSoundBuffer; // buffer of the coin sound
    std::shared_ptr<minigameConnector> magicConnector; // connector to minigame
    const float petSpeed = 12.f; // speed of the pet
    bool isMovingLeft;
    bool isMovingRight;


public:

/**
 * @brief Construct a new minigame object
 * @param textureName  - name of texture to be loaded
 * @param _magicConnector - connector to minigame
 */
    minigame(std::string textureName, const std::shared_ptr<minigameConnector> &_magicConnector);

    /**
     * @brief Method used for handling input
     * @param window - window to handle input on
     * @param _screenName - name of the screen -> to change screen
     */
    void handleInput(sf::RenderWindow &window, ScreenName &_screenName) override;

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
     * @param window - window to update minigame on
     * @param pet - tamagotchi object
     */
    void update(sf::RenderWindow &window, tamagotchi &pet) override;

    /**
     * @brief Method used for setting coin sound buffer
     */
    void setCoinSoundBuffer();
};


#endif //PROJECT_NAME_MINIGAME_H
