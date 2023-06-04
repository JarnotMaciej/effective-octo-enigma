//
// Created by menox on 12.05.2023.
//

#ifndef TAMAGOTCHI_TAMAGOTCHISCREEN_H
#define TAMAGOTCHI_TAMAGOTCHISCREEN_H

// C++
#include <thread>

// header files
#include "../screen.h"
#include "topBar.h"
#include "indicatorBar.h"
#include "bottomBar.h"
#include "../../mechanics/tamagotchiMechanics.h"

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
    std::shared_ptr<tamagotchi> pet_pointer; // pointer to tamagotchi object
    sf::Clock zzzClock; // clock for zzz animation
    sf::Text zzzText; // text for zzz animation

public:

    /**
     * @brief Constructor
     * @param textureName name of texture
     * @param pet tamagotchi object
     */
    tamagotchiScreen(const std::string& textureName, tamagotchi &pet);

    /**
     * @brief Draws tamagotchi screen
     * @param window window to draw on
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Updates tamagotchi screen
     * @param window window to update on
     * @param pet tamagotchi to update
     */
    void update(sf::RenderWindow &window, tamagotchi &pet) override;

    /**
     * @brief Sets positions of elements
     * @param window window to set positions on
     */
    void setPositions(sf::RenderWindow &window) override;

    /**
     * @brief Handles input
     * @param window window to handle input on
     * @param _screenName name of current screen
     */
    void handleInput(sf::RenderWindow &window, ScreenName &_screenName) override;

    /**
     * @brief Represents washing pet
     * @param window - window to draw on
     */
    void washPet(sf::RenderWindow &window);

    /**
     * @brief Represents sleeping pet, works like ON/OFF switch
     * @param window - window to draw on
     */
    void sleepPet(sf::RenderWindow &window);

};

#endif //TAMAGOTCHI_TAMAGOTCHISCREEN_H
