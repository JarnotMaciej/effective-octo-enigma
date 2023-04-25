//
// Created by menox on 20.04.2023.
//

#ifndef PROJECT_NAME_INDICATOR_H
#define PROJECT_NAME_INDICATOR_H

// header files
#include "../../functions.h"

// asset manager
#include "../assetManager.h"

// SFML
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"


//**
// * @brief Class for tamagotchi indicators
// */
class indicator {
private:
    sf::Text indicatorName; // indicator name
    sf::Color indicatorColor; // indicator color
    int indicatorValue; // indicator value
    int positionX; // indicator x position
    int positionY; // indicator y position

public:
    //**
    // * @brief Default constructor for indicator
    // * @param name - name of indicator
    // * @param color - color of indicator
    // * @param value - value of indicator
    // */
    indicator(const std::string& name, const sf::Color& color, int value);

    //**
    // * @brief Method used for drawing indicator
    // * @param window - window to draw indicator on
    // */
    void draw(sf::RenderWindow& window);

    //**
    // * @brief Method used for updating indicator value
    // * @param window - window to draw indicator on
    // * @param value - new value of indicator
    // */
    void update(int value);

    //**
    // * @brief Method used for getting x position of indicator
    // * @param x - x position of indicator
    // * @param y - y position of indicator
    // */
    void setPosition(int x, int y);

};


#endif //PROJECT_NAME_INDICATOR_H
