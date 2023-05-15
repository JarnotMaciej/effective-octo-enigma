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


    // cat
     */
    cat myCat;
    std::string catName = "Neko";
    myCat.setName(catName);
    myCat.setAge(373);
    myCat.setMoney(121);

    myCat.setEnergy(70);
    myCat.setHappiness(90);
    myCat.setHunger(40);
    myCat.setHygiene(90);
    myCat.setHealth(100);
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

    // ------------------------------
    // SFML part of the program
	// creating instance of asset manager
	assetManager::getInstance();

	// create window
	RenderWindow window(VideoMode(1536, 1024), "Tamagotchi", sf::Style::None);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
    setIcon(window);
    setCursor(window);

    // menu testing
    menu mainMenu;
    mainMenu.setPositions(window);

    // tamagotchi screen testing
    tamagotchiScreen myTamagotchiScreen;
    myTamagotchiScreen.setTamagotchiTexture("cat");
    myTamagotchiScreen.setPositions(window);

    // score board testing
    scoreboard myScoreBoard;
    myScoreBoard.setPositions(window);


    // main loop
	while (window.isOpen())
	{
        myScoreBoard.handleInput(window);

        // clear window
        window.clear();

        // update
        myTamagotchiScreen.update(myCat, window);

        // draw menu
//        mainMenu.draw(window);
//        myTamagotchiScreen.draw(window);
        myScoreBoard.draw(window);

        // display window
        window.display();
	}


    // Google Test run
    t.join();
    return RUN_ALL_TESTS();
    // TODO -> checking file structure using regex
}
