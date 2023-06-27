#ifndef TAMAGOTCHI_GAMEOVER_H
#define TAMAGOTCHI_GAMEOVER_H

#include "../screen.h"
#include "../../mechanics/assetManager.h"
#include "minigameConnector.h"

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
    int gameOverTimeout = 7; // timeout for game over screen (7 seconds)
    bool isRunning; // is game over screen running]
    std::shared_ptr<minigameConnector> magicConnector; // connector to minigame

public:
    /**
     * @brief Constructor
     * @param _magicConnector connector to minigame
     */
    gameOver(const std::shared_ptr<minigameConnector> &_magicConnector);

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
     * @brief Updates coins text
     */
    void updateCoinsText();
};


#endif //TAMAGOTCHI_GAMEOVER_H
