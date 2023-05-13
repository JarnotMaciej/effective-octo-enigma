//
// Created by menox on 12.05.2023.
//

#include "indicatorBar.h"

indicatorBar::indicatorBar() {
    indicators.emplace_back("health", sf::Color::Red, 100);
    indicators.emplace_back("hunger", sf::Color::Yellow, 100);
    indicators.emplace_back("happiness", sf::Color::Magenta, 100);
    indicators.emplace_back("hygiene", sf::Color::Blue, 100);
    indicators.emplace_back("energy", sf::Color::Green, 100);
}

void indicatorBar::draw(sf::RenderWindow &window) {
    for (auto& indicator : indicators) {
        indicator.draw(window);
    }
}

void indicatorBar::setPositions(sf::RenderWindow &window) {
    // distribute the indicators evenly
    int indicatorWidth = 100;
    int margin = 120;
    int x = (window.getSize().x - (indicatorWidth * indicators.size() + margin * (indicators.size() - 1))) / 2;
    int y = 100;
    for (auto& indicator : indicators) {
        indicator.setPosition(x, y);
        x += indicatorWidth + margin;
    }

}

void indicatorBar::update(tamagotchi &pet) {
    indicators[0].update(pet.getHealth());
    indicators[1].update(pet.getHunger());
    indicators[2].update(pet.getHappiness());
    indicators[3].update(pet.getHygiene());
    indicators[4].update(pet.getEnergy());
}
