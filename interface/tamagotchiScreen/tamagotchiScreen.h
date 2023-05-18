//
// Created by menox on 12.05.2023.
//

#ifndef TAMAGOTCHI_TAMAGOTCHISCREEN_H
#define TAMAGOTCHI_TAMAGOTCHISCREEN_H


#include "../screen.h"
#include "topBar.h"
#include "indicatorBar.h"
#include "bottomBar.h"

/**
 * @brief Tamagotchi screen class
 */
class tamagotchiScreen : public screen {
private:
    topBar ts_topbar; // top bar
    indicatorBar ts_indicatorbar; // indicator bar
    bottomBar ts_bottombar; // bottom bar
    sf::Texture tamagotchiTexture; // texture of tamagotchi
    sf::Sprite tamagotchiSprite; // sprite of tamagotchi

public:
    /**
     * @brief Constructor of tamagotchi screen
     */
    tamagotchiScreen() = default;

    /**
     * @brief Draws tamagotchi screen
     * @param window window to draw on
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Updates tamagotchi screen
     * @param pet tamagotchi to update
     * @param window window to update on
     */
    void update(tamagotchi &pet, sf::RenderWindow &window);

    /**
     * @brief Sets positions of elements
     * @param window window to set positions on
     */
    void setPositions(sf::RenderWindow &window) override;

    /**
     * @brief Handles input
     * @param window window to handle input on
     */
    void handleInput(sf::RenderWindow &window) override;

    /**
     * @brief Sets texture of tamagotchi
     * @param name name of texture
     */
    void setTamagotchiTexture(const std::string &name);

};

#endif //TAMAGOTCHI_TAMAGOTCHISCREEN_H
