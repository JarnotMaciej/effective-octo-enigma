//
// Created by menox on 06.06.2023.
//

#ifndef TAMAGOTCHI_FOODBAR_H
#define TAMAGOTCHI_FOODBAR_H


// C++
#include <vector>

// header files
#include "foodButton.h"
#include "../../../structures/food.h"

// asset manager
#include "../../assetManager.h"

/**
 * @brief Class for food bar
 */
class foodBar {
private:
    std::vector<foodButton> buttons; // vector of buttons
    sf::Text equipmentMove; // instruction how to move in equipment
    sf::Text sellText; // instruction how to sell food
    sf::Text buyText; // instruction how to buy food
    sf::Text eatText; // instruction how to eat food
    short int activeButton; // index of active button


public:
    /**
     * @brief Constructor of food bar
     * @param _myFood - vector of food
     */
    explicit foodBar(std::vector<food> _myFood);

    /**
     * @brief Default constructor
     */
    foodBar() = default;

    /**
     * @brief Draws food bar
     * @param window - window to draw on
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Sets positions of buttons
     * @param window - window to set positions on
     */
    void setPositions(sf::RenderWindow &window);

    /**
     * @brief Activates next button
     */
    void activateNextButton();

    /**
     * @brief Activates previous button
     */
    void activatePreviousButton();

    /**
     * @brief Buys food
     */
    void buyFood();

    /**
     * @brief Sells food
     */
    void sellFood();

    /**
     * @brief Eats food
     */
    void eatFood();
};


#endif //TAMAGOTCHI_FOODBAR_H
