// Google Test
#include <gtest/gtest.h>

// C++
#include <iostream>
#include <string>

// asset manager
#include "interface/assetManager.h"

// Header files
// structures
#include "structures/tamagotchi.h"
// mechanics
#include "mechanics/tamagotchiMechanics.h"
#include "mechanics/foodMechanics.h"

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

    /*
    // Food config loading
    std::map<std::string, food> foods;
    foods = foodMechanics::loadGlobalFoods();
//    foodMechanics::printFoods(foods);

    std::cout << tamagotchiMechanics::searchForTamagotchi() << std::endl;

     */

    /*
    myCat.meow();
    // add food from global foods
    myCat.addFood(foods["Apple"]);

    myCat.printInfo();

    // saving cat and his food
    tamagotchiMechanics::saveTamagotchi(myCat);
    foodMechanics::saveFoods(myCat);

    //getting time test
//    std::this_thread::sleep_for(std::chrono::seconds(2));
//    tamagotchiMechanics::saveTamagotchi(myTamagotchi);

    // getting scores
    std::vector<score> scores = tamagotchiMechanics::getScores();
    tamagotchiMechanics::printScores(scores);
    */

    game myGame;
    myGame.run();


    // Google Test run
    t.join();
    return RUN_ALL_TESTS();
    // TODO -> checking file structure using regex
}
