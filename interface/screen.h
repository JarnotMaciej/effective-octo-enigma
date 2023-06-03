//
// Created by menox on 06.04.2023.
//

#ifndef PROJECT_NAME_SCREEN_H
#define PROJECT_NAME_SCREEN_H

// SFML
#include "SFML/Graphics.hpp"

// C++
#include "../structures/tamagotchi.h"

// Header files


/**
 * @brief Enum class for screen name
 */
enum class ScreenName {
    MENU,
    TAMAGOTCHI_SCREEN,
    SCOREBOARD,
    CREDITS,
    MINIGAME,
    GAME_OVER
};

/**
 * @brief Class for screen
 */
class screen {
public:
    virtual void handleInput(sf::RenderWindow &window, ScreenName &_screenName) = 0; // handle input
    virtual void draw(sf::RenderWindow &window) = 0; // render window
    virtual void setPositions(sf::RenderWindow &window) = 0; // set positions
    virtual void update(sf::RenderWindow &window, tamagotchi &pet) = 0; // update screen

    /**
     * @brief Function for changing screen
     * @param currentScreen - current screen
     * @param screenToSet - screen to set
     */
    static void changeScreen(ScreenName &currentScreen, ScreenName screenToSet); // change screen
};

#endif //PROJECT_NAME_SCREEN_H
