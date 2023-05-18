//
// Created by menox on 18.05.2023.
//

#include "game.h"


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
}

