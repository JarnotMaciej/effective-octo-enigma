#include "foodBar.h"

foodBar::foodBar(const tamagotchi &pet) {
    // set text
    equipmentMove.setString("Use A and D to move");
    equipmentMove.setFont(assetManager::getInstance().getFont("silkscreen"));
    equipmentMove.setCharacterSize(22);
    equipmentMove.setFillColor(sf::Color::White);

    sellText.setString("Press S to sell");
    sellText.setFont(assetManager::getInstance().getFont("silkscreen"));
    sellText.setCharacterSize(22);
    sellText.setFillColor(sf::Color::White);

    buyText.setString("Press B to buy");
    buyText.setFont(assetManager::getInstance().getFont("silkscreen"));
    buyText.setCharacterSize(22);
    buyText.setFillColor(sf::Color::White);

    eatText.setFont(assetManager::getInstance().getFont("silkscreen"));
    eatText.setString("Press Space to eat");
    eatText.setCharacterSize(22);
    eatText.setFillColor(sf::Color::White);

    // set positions of texts
    equipmentMove.setPosition(10, 10);
    sellText.setPosition(10, 40);
    buyText.setPosition(10, 70);
    eatText.setPosition(10, 100);

    // create buttons
    std::vector<std::string> foodNames;
    for (auto &foodPair: pet.getFoods()) {
        std::string foodName = foodPair.first.getName();
        buttons[foodName] = foodButton(foodName);
        foodNames.push_back(foodName);
    }

    // set active button
    if (!buttons.empty()) {
        activeButton = 0;
        buttons[foodNames[activeButton]].setActive(true);
    } else {
        activeButton = -1;
    }

    // add food stats
    foodStats.emplace_back("Food statistics:", assetManager::getInstance().getFont("silkscreen"), 22);
    foodStats.emplace_back("Price: " + std::to_string(pet.findFood(foodNames[activeButton]).getPrice()),
                           assetManager::getInstance().getFont("silkscreen"), 22);
    foodStats.emplace_back("Health: " + std::to_string(pet.findFood(foodNames[activeButton]).getHealth()),
                           assetManager::getInstance().getFont("silkscreen"), 22);
    foodStats.emplace_back("Hunger: " + std::to_string(pet.findFood(foodNames[activeButton]).getHunger()),
                           assetManager::getInstance().getFont("silkscreen"), 22);
    foodStats.emplace_back("Happiness: " + std::to_string(pet.findFood(foodNames[activeButton]).getHappiness()),
                             assetManager::getInstance().getFont("silkscreen"), 22);
    foodStats.emplace_back("Hygiene: " + std::to_string(pet.findFood(foodNames[activeButton]).getHygiene()),
                           assetManager::getInstance().getFont("silkscreen"), 22);
    foodStats.emplace_back("Energy: " + std::to_string(pet.findFood(foodNames[activeButton]).getEnergy()),
                           assetManager::getInstance().getFont("silkscreen"), 22);

    // set sound
    foodBarBuffer = assetManager::getInstance().getSound("crunch1", "ogg");
}

void foodBar::draw(sf::RenderWindow &window) {
    // draw texts
    window.draw(equipmentMove);
    window.draw(sellText);
    window.draw(buyText);
    window.draw(eatText);

    // draw buttons
    for (auto &buttonPair: buttons) {
        buttonPair.second.draw(window);
    }

    // draw food stats
    for (auto &foodStat: foodStats) {
        window.draw(foodStat);
    }
}

void foodBar::setPositions(sf::RenderWindow &window) {
    int buttonWidth = buttons[getActiveButtonName()].getSprite().getGlobalBounds().width;
    int buttonHeight = buttons[getActiveButtonName()].getSprite().getGlobalBounds().height;
    int buttonSpacing = (window.getSize().x - buttons.size() * buttonWidth) / (buttons.size() + 1);

    int i = 0;
    for (auto &buttonPair: buttons) {
        buttonPair.second.setPosition(buttonSpacing + i * (buttonSpacing + buttonWidth),
                                      window.getSize().y - buttonHeight / 2 - 220);
        i++;
    }

    // set positions of texts -> above buttons, left aligned to the leftmost button
    eatText.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                        buttons[getActiveButtonName()].getSprite().getPosition().y - eatText.getGlobalBounds().height -
                        60);
    buyText.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                        eatText.getPosition().y - buyText.getGlobalBounds().height - 10);
    sellText.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                         buyText.getPosition().y - sellText.getGlobalBounds().height - 10);
    equipmentMove.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                              sellText.getPosition().y - equipmentMove.getGlobalBounds().height - 10);

    // set positions of food stats -> right aligned to the rightmost button
    int foodStatsSpacing = 10;
    // based on map size, window, and button size calculate rightmost stats position
    int foodStatsPositionX = window.getSize().x - buttonSpacing - buttons.size() * buttonWidth - foodStats[0].getGlobalBounds().width - foodStatsSpacing;
    int foodStatsPositionY = buttons[getActiveButtonName()].getSprite().getPosition().y - foodStats[0].getGlobalBounds().height - 60;

    // position are set backwards, starting from the last element
    for (int i = foodStats.size() - 1; i >= 0; i--) {
        foodStats[i].setPosition(foodStatsPositionX, foodStatsPositionY);
        foodStatsPositionY -= foodStats[i].getGlobalBounds().height + foodStatsSpacing;
    }
}

void foodBar::activateNextButton() {
    buttons[getActiveButtonName()].setActive(false);
    activeButton++;
    if (activeButton >= buttons.size()) {
        activeButton = 0;
    }
    buttons[getActiveButtonName()].setActive(true);
}

void foodBar::activatePreviousButton() {
    buttons[getActiveButtonName()].setActive(false);
    activeButton--;
    if (activeButton < 0) {
        activeButton = buttons.size() - 1;
    }
    buttons[getActiveButtonName()].setActive(true);
}

void foodBar::buyFood(tamagotchi &pet) {
    if (pet.buyFood(getActiveButtonName())) {
        int random = rand() % 12 + 1;
        std::string soundName = "coin" + std::to_string(random);
        foodBarBuffer = assetManager::getInstance().getSound(soundName, "ogg");
        foodBarSound.setBuffer(foodBarBuffer);
        foodBarSound.play();
    }
}

void foodBar::sellFood(tamagotchi &pet) {
    if (pet.sellFood(getActiveButtonName())) {
        int random = rand() % 12 + 1;
        std::string soundName = "coin" + std::to_string(random);
        foodBarBuffer = assetManager::getInstance().getSound(soundName, "ogg");
        foodBarSound.setBuffer(foodBarBuffer);
        foodBarSound.play();
    }
}

void foodBar::eatFood(tamagotchi &pet) {
    if (pet.eatFood(getActiveButtonName())) {
        int random = rand() % 7 + 1;
        std::string soundName = "crunch" + std::to_string(random);
        foodBarBuffer = assetManager::getInstance().getSound(soundName, "ogg");
        foodBarSound.setBuffer(foodBarBuffer);
        foodBarSound.play();
    }
}

void foodBar::update(tamagotchi &pet, sf::RenderWindow &window) {
    for (const auto &foodPair: pet.getFoods()) {
        const std::string &foodName = foodPair.first.getName();
        int newQuantity = foodPair.second;

        if (buttons.find(foodName) != buttons.end()) {
            buttons[foodName].setQuantity(newQuantity);
        }
    }

    // update food stats
    foodStats[1].setString("Price: " + std::to_string(pet.findFood(getActiveButtonName()).getPrice()));
    foodStats[2].setString("Health: " + std::to_string(pet.findFood(getActiveButtonName()).getHealth()));
    foodStats[3].setString("Hunger: " + std::to_string(pet.findFood(getActiveButtonName()).getHunger()));
    foodStats[4].setString("Happiness: " + std::to_string(pet.findFood(getActiveButtonName()).getHappiness()));
    foodStats[5].setString("Hygiene: " + std::to_string(pet.findFood(getActiveButtonName()).getHygiene()));
    foodStats[6].setString("Energy: " + std::to_string(pet.findFood(getActiveButtonName()).getEnergy()));

    // update positions
    setStatsPositions(window);
}

void foodBar::setStatsPositions(sf::RenderWindow &window) {
    // set positions of food stats -> right aligned to the rightmost button
    int foodStatsSpacing = 10;
    // based on map size, window, and button size calculate rightmost stats position
    int foodStatsPositionY = buttons[getActiveButtonName()].getSprite().getPosition().y - foodStats[0].getGlobalBounds().height - 60;

    // position are set backwards, starting from the last element
    for (int i = foodStats.size() - 1; i >= 0; i--) {
        int foodStatsPositionX = window.getSize().x - buttons[getActiveButtonName()].getSprite().getGlobalBounds().width - foodStats[i].getGlobalBounds().width - foodStatsSpacing;
        foodStats[i].setPosition(foodStatsPositionX, foodStatsPositionY);
        foodStatsPositionY -= foodStats[i].getGlobalBounds().height + foodStatsSpacing;
    }
}
