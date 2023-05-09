//
// Created by menox on 09.05.2023.
//

#include "bottomButton.h"

bottomButton::bottomButton(const std::string &name, const std::string &texture) {
    this->buttonName.setString(name);
    this->buttonName.setFillColor(sf::Color::White);
    this->buttonName.setCharacterSize(28);
    this->buttonName.setFont(assetManager::getInstance().getFont("silkscreen"));

    this->buttonTexture = assetManager::getInstance().getTexture(texture);
    this->sprite.setTexture(this->buttonTexture);
    this->sprite.setScale(6, 6);

}

void bottomButton::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(buttonName);
}

void bottomButton::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
    // centering the text under the sprite
    this->buttonName.setPosition(x + (this->sprite.getGlobalBounds().width / 2) - (this->buttonName.getGlobalBounds().width / 2) - 7, y + this->sprite.getGlobalBounds().height);
}


