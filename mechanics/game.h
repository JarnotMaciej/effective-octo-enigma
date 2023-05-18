//
// Created by menox on 18.05.2023.
//

#ifndef TAMAGOTCHI_GAME_H
#define TAMAGOTCHI_GAME_H

// C++
#include <string>
#include <map>

// header files
#include "../interface/screen.h"
#include "../interface/menu/menu.h"
#include "../interface/tamagotchiScreen/tamagotchiScreen.h"
#include "../interface/scoreboard/scoreboard.h"
#include "../structures/cat.h"

/**
 * @brief Class for game
 */
class game {
private:
    std::map<std::string, std::unique_ptr<screen>> screens; // map of screens
    std::unique_ptr<screen> currentScreen; // current screen

public:
    /*
     * @brief Constructor
     */
    game() = default;

    /*
     * @brief Function for running game
     */
    void run();

    /**
     * @brief Function for setting current screen
     * @param screenName - name of screen
     */
//    void setCurrentScreen(std::string screenName);

};


#endif //TAMAGOTCHI_GAME_H
