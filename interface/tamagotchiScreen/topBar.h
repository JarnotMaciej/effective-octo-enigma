//
// Created by menox on 09.05.2023.
//

#ifndef PROJECT_NAME_TOP_BAR_H
#define PROJECT_NAME_TOP_BAR_H

// SFML
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"

// C++
#include "../assetManager.h"
#include "../../functions.h"

/**
 * @brief Class for top bar -> tamagotchi name, coins, days alive
 */
class topBar {
private:
    sf::Text tamagotchiName;
    sf::Text coins;
    sf::Text daysAlive;

public:
    /**
     * @brief Default constructor for top bar
     */
    topBar();

    /**
     * @brief Method used for drawing top bar
     * @param window - window to draw top bar on
     */
    void setPosition(sf::Window &window);

    /**
     * @brief Method used for drawing top bar
     * @param window - window to draw top bar on
     */
    void draw(sf::RenderWindow &window);

    // setters
    /**
     * @brief Method used for setting tamagotchi name
     * @param name - new tamagotchi name
     */
    void setTamagotchiName(const std::string &name);

    /**
     * @brief Method used for setting coins
     * @param coins - new coins
     */
    void setCoins(int coins);

    /**
     * @brief Method used for setting days alive
     * @param daysAlive - new days alive
     */
    void setDaysAlive(int daysAlive);
};


#endif //PROJECT_NAME_TOP_BAR_H
