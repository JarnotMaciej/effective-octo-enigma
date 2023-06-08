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
#include "../../../structures/tamagotchi.h"

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
     * @param _myFood - map of food
     */
    explicit foodBar(std::map<std::string, food> _myFood);

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
     * @brief Updates food bar
     * @param pet_pointer - pointer to pet
     */
    void update(std::shared_ptr<tamagotchi> pet_pointer);

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
