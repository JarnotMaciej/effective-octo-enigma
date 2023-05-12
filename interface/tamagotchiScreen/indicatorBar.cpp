//
// Created by menox on 12.05.2023.
//

#include "indicatorBar.h"

indicatorBar::indicatorBar() {
    indicators.emplace_back("health", sf::Color::Red, 100);
    indicators.emplace_back("hungry", sf::Color::Yellow, 100);
    indicators.emplace_back("happiness", sf::Color::Magenta, 100);
    indicators.emplace_back("hygiene", sf::Color::Blue, 100);
    indicators.emplace_back("energy", sf::Color::Green, 100);
}

void indicatorBar::draw(sf::RenderWindow &window) {
    for (auto& indicator : indicators) {
        indicator.draw(window);
    }
}

void indicatorBar::setPositions(sf::RenderWindow) {
    // TODO: implement
}
