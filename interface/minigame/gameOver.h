//
// Created by menox on 03.06.2023.
//

#ifndef TAMAGOTCHI_GAMEOVER_H
#define TAMAGOTCHI_GAMEOVER_H

// header files
#include "../screen.h"
#include "../assetManager.h"

/**
 * @brief Game over screen class
 */
class gameOver : public screen {
private:
    sf::Text message; // message
    sf::Text coinsWon; // coins won
    sf::Text pressEscToContinue; // text of coins won
    int coinsValue; // coins won
    sf::Clock gameOverClock; // clock for game over screen
    int gameOverTimeout = 5; // timeout for game over screen
    bool isRunning; // is game over screen running

public:
    /**
     * @brief Constructor
     */
    gameOver();

    /**
     * @brief Draws game over screen
     * @param window window to draw on
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Updates game over screen
     * @param window window to update on
     * @param pet tamagotchi to update
     */
    void update(sf::RenderWindow &window, tamagotchi &pet) override;

    /**
     * @brief Sets positions of elements
     * @param window window to set positions on
     */
    void setPositions(sf::RenderWindow &window) override;

    /**
     * @brief Handles input
     * @param window window to handle input on
     * @param pet tamagotchi to handle input on
     */
    void handleInput(sf::RenderWindow &window, ScreenName &_screenName) override;

    /**
     * @brief Sets messageToSet
     * @param messageToSet messageToSet to set
     */
    void setMessage(std::string& messageToSet);

    /**
     * @brief Sets coins won
     * @param coinsToSet coins won to set
     */
//    void setCoinsWon(int coinsToSet);

    std::shared_ptr<int> getCoinsPtr();

    void updateCoinsText();
};


#endif //TAMAGOTCHI_GAMEOVER_H
