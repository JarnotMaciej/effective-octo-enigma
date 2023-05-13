//
// Created by menox on 13.05.2023.
//

#ifndef TAMAGOTCHI_SCOREBOARD_H
#define TAMAGOTCHI_SCOREBOARD_H

// header files
#include "../screen.h"
#include "../assetManager.h"
#include "../../structures/score.h"
#include "../../mechanics/tamagotchiMechanics.h"


/*
 * @brief Class for scoreboard
 */
class scoreboard : public screen {
private:
    sf::Text title; // title of the screen
    std::vector<sf::Text> textScores; // vector of scores

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
};


#endif //TAMAGOTCHI_SCOREBOARD_H
