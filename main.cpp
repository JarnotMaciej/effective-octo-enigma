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
#include "interface/tamagotchiScreen/topBar.h"
#include "interface/tamagotchiScreen/indicatorBar.h"
#include "interface/tamagotchiScreen/bottomBar.h"

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
    std::string catName = "Kotek";
    myCat.setName(catName);
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

    // menu testing
    menu mainMenu;
    mainMenu.setPositions(window);

    //top bar testing
    topBar myTopBar;
    myTopBar.setPosition(window);
    myTopBar.setTamagotchiName("Neko");
    myTopBar.setCoins(100, window);
    myTopBar.setDaysAlive(373, window);

    // indicator bar testing
    indicatorBar myIndicatorBar;
    myIndicatorBar.setPositions(window);

    // bottom bar testing
    bottomBar myBottomBar;
    myBottomBar.setPositions(window);

    // get cat texture, sprite and set position
    sf::Texture catTexture;
    sf::Sprite catSprite;
    catTexture = assetManager::getInstance().getTexture("cat");
    catSprite.setTexture(catTexture);
    // set center position in window
    catSprite.setPosition(window.getSize().x / 2 - catSprite.getGlobalBounds().width / 2,
                          window.getSize().y / 2 - catSprite.getGlobalBounds().height / 2);

    // main loop
	while (window.isOpen())
	{
        mainMenu.handleInput(window);

        // clear window
        window.clear();

        // update
        myIndicatorBar.update(myCat);

        // draw menu
//        mainMenu.draw(window);
//
        myTopBar.draw(window);
        myIndicatorBar.draw(window);
        myBottomBar.draw(window);
        window.draw(catSprite);

        // display window
        window.display();
	}


    // Google Test run
    t.join();
    return RUN_ALL_TESTS();
    // TODO -> checking file structure using regex
}
