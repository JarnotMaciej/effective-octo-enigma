#include "topBar.h"

topBar::topBar() {
    tamagotchiName.setString("Tamagotchi");
    tamagotchiName.setFillColor(sf::Color::White);

    coins.setString("Coins: 0");
    coins.setFillColor(sf::Color{229, 200, 144});

    daysAlive.setString("Days alive: 0");
    daysAlive.setFillColor(sf::Color::White);

    tamagotchiName.setCharacterSize(28);
    coins.setCharacterSize(28);
    daysAlive.setCharacterSize(28);

    tamagotchiName.setFont(assetManager::getInstance().getFont("silkscreen"));
    coins.setFont(assetManager::getInstance().getFont("silkscreen"));
    daysAlive.setFont(assetManager::getInstance().getFont("silkscreen"));
}

void topBar::setPosition(sf::Window &window) {
    tamagotchiName.setPosition(20, 10);
    daysAlive.setPosition(window.getSize().x - daysAlive.getLocalBounds().width - 20, 10);
    coins.setPosition((window.getSize().x / 2) - (coins.getLocalBounds().width / 2), 10);
}

void topBar::draw(sf::RenderWindow &window) {
    window.draw(tamagotchiName);
    window.draw(coins);
    window.draw(daysAlive);
}

void topBar::setTamagotchiName(const std::string &name) {
    this->tamagotchiName.setString(name);
}

void topBar::setCoins(int coins, sf::RenderWindow &window) {
    this->coins.setString("Coins: " + std::to_string(coins));
    this->coins.setPosition((window.getSize().x / 2) - (this->coins.getLocalBounds().width / 2), 10);
}

void topBar::setDaysAlive(int bornTime, sf::RenderWindow &window) {
    int age = tamagotchiMechanics::realDaysToGameDays(bornTime);
    this->daysAlive.setString("Days alive: " + std::to_string(age));
    this->daysAlive.setPosition(window.getSize().x - this->daysAlive.getLocalBounds().width - 20, 10);
}

float topBar::getHeight() {
    return tamagotchiName.getLocalBounds().height;
}

void topBar::update(tamagotchi &tamagotchi, sf::RenderWindow &window) {
    setTamagotchiName(tamagotchi.getName());
    setCoins(tamagotchi.getMoney(), window);
    setDaysAlive(tamagotchi.getBornTime(), window);
    setPosition(window);
}
