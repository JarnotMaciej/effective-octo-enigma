//
// Created by menox on 09.05.2023.
//

#include "topBar.h"


topBar::topBar() {
    debug("topBar::topBar");
    tamagotchiName.setString("Tamagotchi");
    tamagotchiName.setFillColor(sf::Color::White);

    coins.setString("Coins: 0");
    coins.setFillColor(sf::Color::White);

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
    // on the right side
    tamagotchiName.setPosition(20, 10);
    //on the left side
    daysAlive.setPosition(window.getSize().x - daysAlive.getLocalBounds().width - 20, 10);
    // coins centered to the window
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
    //update the position of the coins text
    this->coins.setPosition((window.getSize().x / 2) - (this->coins.getLocalBounds().width / 2), 10);
}

void topBar::setDaysAlive(int daysAlive, sf::RenderWindow &window) {
    this->daysAlive.setString("Days alive: " + std::to_string(daysAlive));
    //update the position of the days alive text
    this->daysAlive.setPosition(window.getSize().x - this->daysAlive.getLocalBounds().width - 20, 10);
}

float topBar::getHeight() {
    return tamagotchiName.getLocalBounds().height;
}
