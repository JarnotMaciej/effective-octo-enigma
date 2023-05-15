//
// Created by menox on 13.05.2023.
//

// C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <cctype> // Added for case-insensitive comparison


// header files
#include "../screen.h"
#include "../assetManager.h"
#include "../../structures/score.h"
#include "../../mechanics/tamagotchiMechanics.h"
#include "../keycapButton.h"

#ifndef TAMAGOTCHI_SCOREBOARD_H
#define TAMAGOTCHI_SCOREBOARD_H


/*
 * @brief Class for scoreboard
 */
class scoreboard : public screen {
private:
    sf::Text title; // title of the screen
    std::vector<score> scores; // vector of scores
    std::vector<sf::Text> textScores; // vector of scores
    std::vector<keycapButton> buttons; // vector of buttons

    /*
     * @brief Enum class for setting display mode
     */
    enum class displayMode {
        DEFAULT,
        HIGHEST_SCORE,
        LOWEST_SCORE,
        ALPHABETICAL_NAME,
        REVERSE_ALPHABETICAL_NAME
    };

    displayMode mode; // display mode

public:
    /*
     * @brief Constructor
     */
    scoreboard();

    /*
     * @brief Function for drawing screen
     * @param window - window to draw
     */
    void draw(sf::RenderWindow &window) override;

    /*
     * @brief Function for setting position of screen
     * @param window - window to set position
     */
    void setPositions(sf::RenderWindow &window);

    /*
     * @brief Function for handling events
     * @param event - event to handle
     * @param window - window to handle
     */
    void handleInput(sf::RenderWindow &window) override;

    /*
     * @brief Function for setting display newMode
     * @param newMode - newMode to set
     */
    void setMode(displayMode newMode);

    /*
     * @brief Function for getting display mode
     * @return display mode
     */
    displayMode getMode();

    /**
     * @brief Function for transforming scores to text
     * @param window - window to update
     */
    void scoresToText(sf::RenderWindow &window);
};


#endif //TAMAGOTCHI_SCOREBOARD_H
