#include <gtest/gtest.h>
#include "mechanics/assetManager.h"
#include "structures/tamagotchi.h"
#include "mechanics/tamagotchiMechanics.h"
#include "interface/menu/menu.h"
#include "structures/cat.h"
#include "interface/scoreboard/scoreboard.h"
#include "mechanics/game.h"

using namespace sf;

int main() {
    std::thread t([] { testing::InitGoogleTest(); });

    game myGame;
    myGame.run();

    t.join();
    return RUN_ALL_TESTS();
}
