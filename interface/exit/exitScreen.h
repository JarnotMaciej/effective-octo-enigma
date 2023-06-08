//
// Created by menox on 08.06.2023.
//

#ifndef TAMAGOTCHI_EXITSCREEN_H
#define TAMAGOTCHI_EXITSCREEN_H

// C++
#include <iostream>
#include <thread>

// SFML
#include "SFML/Graphics/Text.hpp"

// Headers
#include "../screen.h"
#include "../assetManager.h"
#include "../../mechanics/tamagotchiMechanics.h"
#include "../../mechanics/foodMechanics.h"


class exitScreen : public screen {
private:
    sf::Text savingText; // text for saving game
    bool petSaved; // bool for checking if pet is saved
    bool petSaveStarted; // bool for checking if pet saving has started
    bool foodSaved; // bool for checking if food is saved
    bool foodSaveStarted; // bool for checking if food saving has started

public:

    /**
     * @brief Constructor for exit screen
     */
    explicit exitScreen();

    /**
     * @brief Function for handling input
     * @param window - window to handle input on
     * @param _screenName - name of current screen
     */
    void handleInput(sf::RenderWindow &window, ScreenName &_screenName) override;

    /**
     * @brief Function for drawing
     * @param window - window to draw on
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Function for updating
     * @param window - window to update on
     * @param pet - tamagotchi object
     */
    void update(sf::RenderWindow &window, tamagotchi &pet) override;

    /**
     * @brief Function for setting positions
     * @param window - window to set positions on
     */
    void setPositions(sf::RenderWindow &window) override;

};


#endif //TAMAGOTCHI_EXITSCREEN_H
