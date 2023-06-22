//
// Created by menox on 18.05.2023.
//

#include "game.h"

using namespace sf;

void game::run() {
	RenderWindow window(VideoMode(1536, 1024), "Tamagotchi", sf::Style::None);
    window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
    setIcon(window);
    setCursor(window);

    // loading myOwnPet
    std::string myOwnPetName = tamagotchiMechanics::searchForTamagotchi();
    tamagotchi myOwnPet = tamagotchiMechanics::checkIfTamagotchiExistsThenReturn(myOwnPetName);

    // loading foods
    auto foods = foodMechanics::loadGlobalFoods();


    // minigame connection
    std::shared_ptr<minigameConnector> magicConnector = std::make_shared<minigameConnector>();
    auto creditsTexts = tamagotchiMechanics::createCreditsTexts(tamagotchiMechanics::readCreditsFile());


    // testing
    menu mainMenu;
    tamagotchiScreen myTamagotchiScreen("cat", myOwnPet, foods);
    scoreboard myScoreBoard;
    minigame myMinigame("cat", magicConnector);
    gameOver myGameOver(magicConnector);
    exitScreen myExitScreen;
    credits myCredits(creditsTexts);


    // adding screens to map
    screens[ScreenName::MENU] = std::make_unique<menu>(mainMenu);
    screens[ScreenName::TAMAGOTCHI_SCREEN] = std::make_unique<tamagotchiScreen>(myTamagotchiScreen);
    screens[ScreenName::SCOREBOARD] = std::make_unique<scoreboard>(myScoreBoard);
    screens[ScreenName::MINIGAME] = std::make_unique<minigame>(myMinigame);
    screens[ScreenName::GAME_OVER] = std::make_unique<gameOver>(myGameOver);
    screens[ScreenName::EXIT_SCREEN] = std::make_unique<exitScreen>(myExitScreen);
    screens[ScreenName::CREDITS] = std::make_unique<credits>(myCredits);


    // setPositions everywhere
    for (auto &screen : screens) {
        screen.second->setPositions(window);
    }

    while (window.isOpen())
	{
        screenProcessing(window, myOwnPet);
    }
}

void game::screenProcessing(RenderWindow &window, tamagotchi &pet) {
    screens[currentScreenName]->handleInput(window, currentScreenName);
    window.clear();
    screens[currentScreenName]->update(window, pet);
    screens[currentScreenName]->draw(window);

    window.display();
}

