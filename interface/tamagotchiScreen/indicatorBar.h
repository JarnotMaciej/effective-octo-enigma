#ifndef TAMAGOTCHI_INDICATORBAR_H
#define TAMAGOTCHI_INDICATORBAR_H

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "indicator.h"
#include "../../structures/tamagotchi.h"
#include "../../mechanics/assetManager.h"

/**
 * @brief Class representing indicator bar
 */
class indicatorBar {
private:
    std::vector<indicator> indicators; // vector of indicators
public:
    /**
     * @brief Constructor of indicator bar
     */
    indicatorBar();

    /**
     * @brief Draws indicator bar
     * @param window - window to draw on
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Updates indicator bar
     * @param indicatorName - name of indicator to update
     * @param value - value to update
     */
    void update(tamagotchi &pet);

    /**
     * @brief Sets positions of indicators
     * @param window - window to set positions on
     */
    void setPositions(sf::RenderWindow &window);

};


#endif //TAMAGOTCHI_INDICATORBAR_H
