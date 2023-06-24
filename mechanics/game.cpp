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
    auto _tamagotchiHunt = []() -> tamagotchi
    {
        return tamagotchiMechanics::checkIfTamagotchiExistsThenReturn(tamagotchiMechanics::searchForTamagotchi());
    };

    // loading foods
    auto _foodHunt = []() -> std::map<food, int>
    {
        return foodMechanics::loadGlobalFoods();
    };;

    // loading credits
    auto _creditsHunt = []() -> std::vector<sf::Text>
    {
        return tamagotchiMechanics::createCreditsTexts(tamagotchiMechanics::readCreditsFile());
    };

    // packaged tasks
    std::packaged_task<tamagotchi()> tamagotchiHunt(_tamagotchiHunt);
    std::packaged_task<std::map<food, int>()> foodHunt(_foodHunt);
    std::packaged_task<std::vector<sf::Text>()> creditsHunt(_creditsHunt);

    // future
    std::future<tamagotchi> tamagotchiFuture = tamagotchiHunt.get_future();
    std::future<std::map<food, int>> foodFuture = foodHunt.get_future();
    std::future<std::vector<sf::Text>> creditsFuture = creditsHunt.get_future();

    // threads
    std::thread tamagotchiThread(std::move(tamagotchiHunt));
    std::thread foodThread(std::move(foodHunt));
    std::thread creditsThread(std::move(creditsHunt));

    // joining threads
    tamagotchiThread.join();
    foodThread.join();
    creditsThread.join();

    // minigame connection + screens
    std::shared_ptr<minigameConnector> magicConnector = std::make_shared<minigameConnector>();
    
    menu mainMenu;
    scoreboard myScoreBoard;
    minigame myMinigame("cat", magicConnector);
    gameOver myGameOver(magicConnector);
    exitScreen myExitScreen;

    // getting values from futures
    tamagotchi myOwnPet = tamagotchiFuture.get();
    std::map<food, int> foods = foodFuture.get();
    std::vector<sf::Text> creditsTexts = creditsFuture.get();

    tamagotchiScreen myTamagotchiScreen("cat", myOwnPet, foods);
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

