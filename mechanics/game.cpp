//
// Created by menox on 18.05.2023.
//

#include "game.h"
#include "../interface/minigame/gameOver.h"

using namespace sf;

//game::game() {
//    menu menuScreen;
//    tamagotchiScreen tamagotchiScreen;
//    scoreboard scoreboardScreen;
//
//    screens["menu"] = std::make_unique<menu>(menuScreen);
//    screens["tamagotchiScreen"] = std::make_unique<tamagotchiScreen>(tamagotchiScreen);
//    screens["scoreboard"] = std::make_unique<scoreboard>(scoreboardScreen);
//
//
//    setCurrentScreen("menu");
//}

//void game::setCurrentScreen(std::string screenName) {
//    currentScreen = std::move(screens[screenName]);
//}

void game::run() {
	RenderWindow window(VideoMode(1536, 1024), "Tamagotchi", sf::Style::None);
    window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
    setIcon(window);
    setCursor(window);

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

    // testing
    menu mainMenu;
    tamagotchiScreen myTamagotchiScreen("cat", myCat);
    scoreboard myScoreBoard;
    minigame myMinigame("cat");
    gameOver myGameOver;

    // linking screens
    myMinigame.linkGameOverScreen(myGameOver.getCoinsPtr());

    // adding screens to map
    screens[ScreenName::MENU] = std::make_unique<menu>(mainMenu);
    screens[ScreenName::TAMAGOTCHI_SCREEN] = std::make_unique<tamagotchiScreen>(myTamagotchiScreen);
    screens[ScreenName::SCOREBOARD] = std::make_unique<scoreboard>(myScoreBoard);
    screens[ScreenName::MINIGAME] = std::make_unique<minigame>(myMinigame);
    screens[ScreenName::GAME_OVER] = std::make_unique<gameOver>(myGameOver);


    // setPositions everywhere
    for (auto &screen : screens) {
        screen.second->setPositions(window);
    }

    while (window.isOpen())
	{
//        // myScoreBoard.handleInput(window);
//        myMinigame.handleInput(window, currentScreenName);
//
//        // clear window
//        window.clear();
//
//        // update
//        // myTamagotchiScreen.update(myCat, window);
//        myMinigame.update(window);
//
//        // draw menu
////        mainMenu.draw(window);
//        // myTamagotchiScreen.draw(window);
//        // myScoreBoard.draw(window);
//        myMinigame.draw(window);

        screenProcessing(window, myCat);

        // display window
//        window.display();
	}
}

void game::screenProcessing(RenderWindow &window, tamagotchi &pet) {
    screens[currentScreenName]->handleInput(window, currentScreenName);
    window.clear();
    screens[currentScreenName]->update(window, pet);
    screens[currentScreenName]->draw(window);

    window.display();
}

