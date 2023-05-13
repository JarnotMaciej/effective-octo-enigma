//
// Created by menox on 09.05.2023.
//

#ifndef TAMAGOTCHI_BOTTOMBAR_H
#define TAMAGOTCHI_BOTTOMBAR_H

// header files
#include "bottomButton.h"
#include "../assetManager.h"

/**
 * @brief Class for bottom bar
 */
class bottomBar {
private:
    std::vector<bottomButton> buttons; // vector of buttons

public:
/**
     * @brief Constructor of bottom bar
     */
    bottomBar();

    /**
     * @brief Draws bottom bar
     * @param window - window to draw on
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Sets positions of buttons
     * @param window - window to set positions on
     */
    void setPositions(sf::RenderWindow &window);
};


#endif //TAMAGOTCHI_BOTTOMBAR_H
