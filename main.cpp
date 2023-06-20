// Google Test
#include <gtest/gtest.h>

// C++
#include <iostream>
#include <string>

// asset manager
#include "mechanics/assetManager.h"

// Header files
// structures
#include "structures/tamagotchi.h"
// mechanics
#include "mechanics/tamagotchiMechanics.h"
#include "mechanics/foodMechanics.h"
#include "mechanics/errorHandler.h"

// interface
#include "interface/menu/menu.h"
#include "structures/cat.h"
#include "interface/tamagotchiScreen/tamagotchiScreen.h"
#include "interface/scoreboard/scoreboard.h"
#include "mechanics/game.h"

using namespace sf;

int main() {
    // Google Test initialization in new thread
    std::thread t([] { testing::InitGoogleTest(); });

    game myGame;
    myGame.run();

    // Google Test run
    t.join();
    return RUN_ALL_TESTS();
    // TODO -> checking file structure using regex
}
