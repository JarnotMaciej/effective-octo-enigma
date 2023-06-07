//
// Created by menox on 18.05.2023.
//

#ifndef TAMAGOTCHI_GAME_H
#define TAMAGOTCHI_GAME_H

// C++
#include <string>
#include <map>
#include <memory>
#include <unordered_map>
#include <thread>

// header files
#include "../interface/screen.h"
#include "../interface/menu/menu.h"
#include "../interface/tamagotchiScreen/tamagotchiScreen.h"
#include "../interface/scoreboard/scoreboard.h"
#include "../interface/minigame/minigame.h"
#include "../structures/cat.h"
#include "../interface/tamagotchiScreen/foodStuff/foodButton.h"
#include "../interface/minigame/gameOver.h"
#include "../mechanics/foodMechanics.h"


/**
 * @brief Class for game
 */
class game {
private:
    std::unordered_map<ScreenName, std::unique_ptr<screen>> screens; // map of screens
    ScreenName currentScreenName = ScreenName::MENU; // name of current screen

public:
    /**
     * @brief Constructor
     */
    game() = default;

    /**
     * @brief Function for running game
     */
    void run();

    /**
     * @brief Function for screen processing -> handling input, drawing, updating
     * @param window - window to process screen on
     * @param pet - tamagotchi object
     */
    void screenProcessing(sf::RenderWindow &window, tamagotchi &pet);

};


#endif //TAMAGOTCHI_GAME_H
