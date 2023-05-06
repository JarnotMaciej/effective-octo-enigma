//
// Created by menox on 20.04.2023.
//

#include "indicator.h"

indicator::indicator(const std::string &name, const sf::Color &color, int value) {
    debug("indicator::indicator");
    indicatorName.setString(name);
    indicatorName.setFillColor(sf::Color::White);
    indicatorName.setCharacterSize(20);
    indicatorName.setFont(assetManager::getInstance().getFont("silkscreen"));
    setPosition(0, 0);

    indicatorValue = value;
    indicatorColor = color;

    positionX = 0;
    positionY = 0;
}

void indicator::setPosition(int x, int y) {
    debug("indicator::setPosition");
    positionX = x;
    positionY = y;
}

void indicator::draw(sf::RenderWindow &window) {
    // todo -> fix the method
    debug("indicator::draw");
    // draw rectangles
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(indicatorValue, 20));
    rectangle.setFillColor(indicatorColor);
    rectangle.setPosition(positionX, positionY);
    debug("indicator::draw -> rectangle set");

    sf::RectangleShape backgroundRectangle;
    backgroundRectangle.setSize(sf::Vector2f(100, 20));
    backgroundRectangle.setFillColor(sf::Color::Black);
    backgroundRectangle.setOutlineColor(sf::Color::White);
    backgroundRectangle.setOutlineThickness(2);
    backgroundRectangle.setPosition(positionX, positionY);
    debug("indicator::draw -> backgroundRectangle set");

    window.draw(backgroundRectangle);
    debug("indicator::draw -> backgroundRectangle drawn");
    window.draw(rectangle);
    debug("indicator::draw -> rectangle drawn");

    // draw text -> center it vertically and display them under rectangles
//    indicatorName.setPosition(positionX + 50 - indicatorName.getGlobalBounds().width / 2, positionY + 20);
//    window.draw(indicatorName);
//    debug("indicator::draw -> indicatorName drawn");


}

void indicator::update(int value) {
    debug("indicator::update");
    indicatorValue = value;
}
