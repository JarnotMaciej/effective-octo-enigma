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
#include "interface/tamagotchiScreen/indicator.h"
#include "interface/tamagotchiScreen/topBar.h"
#include "interface/tamagotchiScreen/bottomButton.h"

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
    cat myCat;
    std::string catName = "Kotek";
    myCat.setName(catName);

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
    myTopBar.setCoins(100);
    myTopBar.setDaysAlive(373, window);

    // indicator testing
    indicator health("health", sf::Color::Red, 100);
    indicator hunger("hunger", sf::Color::Yellow, 100);
    indicator happiness("happiness", sf::Color::Magenta, 100);
    indicator hygiene("hygiene", sf::Color::Blue, 100);
    indicator energy("energy", sf::Color::Green, 100);
    health.setPosition(100, 100);
    hunger.setPosition(300, 100);
    happiness.setPosition(500, 100);
    hygiene.setPosition(700, 100);
    energy.setPosition(900, 100);
    int i = 100;

    // bottom buttons testing
    bottomButton feedButton("Eat", "Q");
    bottomButton playButton("Play", "W");
    bottomButton cleanButton("Clean", "E");
    bottomButton sleepButton("Sleep", "R");
    // bottom of the screen
    feedButton.setPosition(100, window.getSize().y - feedButton.getSprite().getGlobalBounds().height/2 - 100);
    playButton.setPosition(300, window.getSize().y - playButton.getSprite().getGlobalBounds().height/2 - 100);
    cleanButton.setPosition(500, window.getSize().y - cleanButton.getSprite().getGlobalBounds().height/2 - 100);
    sleepButton.setPosition(700, window.getSize().y - sleepButton.getSprite().getGlobalBounds().height/2 - 100);

	// main loop
	while (window.isOpen())
	{
        mainMenu.handleInput(window);

        // clear window
        window.clear();

        // update
        health.update(i);
        hunger.update(i);
        happiness.update(i);
        hygiene.update(i);
        energy.update(i);
        i--;
        if (i < 1) i = 100;

        // draw menu
//        mainMenu.draw(window);
        myTopBar.draw(window);
        health.draw(window);
        hunger.draw(window);
        happiness.draw(window);
        hygiene.draw(window);
        energy.draw(window);

        feedButton.draw(window);
        playButton.draw(window);
        cleanButton.draw(window);
        sleepButton.draw(window);

        // display window
        window.display();
	}


    // Google Test run
    t.join();
    return RUN_ALL_TESTS();
    // TODO -> checking file structure using regex
}
