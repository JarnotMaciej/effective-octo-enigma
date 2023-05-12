//
// Created by menox on 20.04.2023.
//

#include "indicator.h"

indicator::indicator(const std::string &name, const sf::Color &color, int value) {
    debug("indicator::indicator");
    indicatorName.setString(name);
    indicatorName.setFillColor(sf::Color::White);
    indicatorName.setCharacterSize(24);
    indicatorName.setFont(assetManager::getInstance().getFont("silkscreen"));
//    setPosition(0, 0);

    indicatorValue = value;
    indicatorColor = color;

    positionX = 0;
    positionY = 0;
}

void indicator::setPosition(int x, int y) {

    positionX = x;
    positionY = y;

    // centering under rectangle
    float textX = positionX + 50 - (indicatorName.getLocalBounds().width / 2);
    float textY = positionY + 25;

    indicatorName.setPosition(textX, textY);
}

void indicator::draw(sf::RenderWindow &window) {
    // draw rectangles
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(indicatorValue, 20));
    rectangle.setFillColor(indicatorColor);
    rectangle.setPosition(positionX, positionY);

    sf::RectangleShape backgroundRectangle;
    backgroundRectangle.setSize(sf::Vector2f(100, 20));
    backgroundRectangle.setFillColor(sf::Color::Black);
    backgroundRectangle.setOutlineColor(sf::Color::White);
    backgroundRectangle.setOutlineThickness(2);
    backgroundRectangle.setPosition(positionX, positionY);

    window.draw(backgroundRectangle);
    window.draw(rectangle);
    window.draw(indicatorName);
}

void indicator::update(int value) {
    indicatorValue = value;
}