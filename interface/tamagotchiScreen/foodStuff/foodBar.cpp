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
}

void foodBar::setPositions(sf::RenderWindow &window) {
    int buttonWidth = buttons[getActiveButtonName()].getSprite().getGlobalBounds().width;
    int buttonHeight = buttons[getActiveButtonName()].getSprite().getGlobalBounds().height;
    int buttonSpacing = (window.getSize().x - buttons.size() * buttonWidth) / (buttons.size() + 1);

//    for (int i = 0; i < buttons.size(); i++) {
//        buttons[i].setPosition(buttonSpacing + i * (buttonSpacing + buttonWidth),
//                               window.getSize().y - buttonHeight / 2 - 220);
//    }
//
//    // set positions of texts -> above buttons, left aligned to the leftmost button
//    eatText.setPosition(buttons[0].getSprite().getPosition().x,
//                        buttons[0].getSprite().getPosition().y - eatText.getGlobalBounds().height - 60);
//    buyText.setPosition(buttons[0].getSprite().getPosition().x,
//                        eatText.getPosition().y - buyText.getGlobalBounds().height - 10);
//    sellText.setPosition(buttons[0].getSprite().getPosition().x,
//                         buyText.getPosition().y - sellText.getGlobalBounds().height - 10);
//    equipmentMove.setPosition(buttons[0].getSprite().getPosition().x,
//                              sellText.getPosition().y - equipmentMove.getGlobalBounds().height - 10);

    // code after refactoring
    int i = 0;
    for (auto &buttonPair: buttons) {
        buttonPair.second.setPosition(buttonSpacing + i * (buttonSpacing + buttonWidth),
                                      window.getSize().y - buttonHeight / 2 - 220);
        i++;
    }

    // set positions of texts -> above buttons, left aligned to the leftmost button
    eatText.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                        buttons[getActiveButtonName()].getSprite().getPosition().y - eatText.getGlobalBounds().height - 60);
    buyText.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                        eatText.getPosition().y - buyText.getGlobalBounds().height - 10);
    sellText.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                         buyText.getPosition().y - sellText.getGlobalBounds().height - 10);
    equipmentMove.setPosition(buttons[getActiveButtonName()].getSprite().getPosition().x,
                              sellText.getPosition().y - equipmentMove.getGlobalBounds().height - 10);

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
    int random = rand() % 12 + 1;
    std::string soundName = "coin" + std::to_string(random);
    foodBarBuffer = assetManager::getInstance().getSound(soundName, "ogg");
    foodBarSound;
    foodBarSound.setBuffer(foodBarBuffer);
    foodBarSound.play();
    pet.buyFood(getActiveButtonName());
}

void foodBar::sellFood(tamagotchi &pet) {
    int random = rand() % 12 + 1;
    std::string soundName = "coin" + std::to_string(random);
    foodBarBuffer = assetManager::getInstance().getSound(soundName, "ogg");
    foodBarSound;
    foodBarSound.setBuffer(foodBarBuffer);
    foodBarSound.play();
    pet.sellFood(getActiveButtonName());
}

void foodBar::eatFood(tamagotchi &pet) {
    int random = rand() % 7 + 1;
    std::string soundName = "crunch" + std::to_string(random);
    foodBarBuffer = assetManager::getInstance().getSound(soundName, "ogg");
    foodBarSound;
    foodBarSound.setBuffer(foodBarBuffer);
    foodBarSound.play();
    pet.eatFood(getActiveButtonName());
}

void foodBar::update(tamagotchi &pet) {
    for (const auto &foodPair: pet.getFoods()) {
        const std::string &foodName = foodPair.first.getName();
        int newQuantity = foodPair.second;

        if (buttons.find(foodName) != buttons.end()) {
            buttons[foodName].setQuantity(newQuantity);
        }
    }
}
