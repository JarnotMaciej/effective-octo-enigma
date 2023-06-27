#include "foodButton.h"

foodButton::foodButton(const std::string &foodName) {
    buttonName = foodName;
    backgroundTexture = assetManager::getInstance().getTexture("16x16dark");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(6.5, 6.5);

    foodTexture = assetManager::getInstance().getTexture(foodName);
    foodSprite.setTexture(foodTexture);
    foodSprite.setScale(2.3, 2.3);

    quantity = 0;
    quantityText.setString(std::to_string(quantity));
    quantityText.setFont(assetManager::getInstance().getFont("silkscreen"));
    quantityText.setCharacterSize(24);
    quantityText.setFillColor(sf::Color::White);
    quantityText.setPosition(0, 0);
    quantityText.setLetterSpacing(0.);
    active = false;
}

foodButton::foodButton(const std::string &foodName, const int &quantity) {
    buttonName = foodName;
    backgroundTexture = assetManager::getInstance().getTexture("16x16dark");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(6.5, 6.5);

    foodTexture = assetManager::getInstance().getTexture(foodName);
    foodSprite.setTexture(foodTexture);
    foodSprite.setScale(2.3, 2.3);

    this->quantity = quantity;
    quantityText.setString(std::to_string(quantity));
    quantityText.setFont(assetManager::getInstance().getFont("silkscreen"));
    quantityText.setCharacterSize(24);
    quantityText.setFillColor(sf::Color::White);
    quantityText.setPosition(0, 0);
    quantityText.setLetterSpacing(0.);

    active = false;
}


void foodButton::draw(sf::RenderWindow &window) {
    backgroundSprite.setTexture(backgroundTexture);
    window.draw(backgroundSprite);
    foodSprite.setTexture(foodTexture);
    window.draw(foodSprite);
    window.draw(quantityText);
}

void foodButton::setPosition(float x, float y) {
    backgroundSprite.setPosition(x, y);

    foodSprite.setPosition(x + backgroundSprite.getGlobalBounds().width / 2 - foodSprite.getGlobalBounds().width / 2,
                           y + backgroundSprite.getGlobalBounds().height / 2 - foodSprite.getGlobalBounds().height / 2);

    quantityText.setPosition(x + backgroundSprite.getGlobalBounds().width - quantityText.getGlobalBounds().width,
                             y - quantityText.getGlobalBounds().height - 8);
}

short foodButton::getQuantity() const {
    return quantity;
}

void foodButton::setQuantity(short quantity) {
    foodButton::quantity = quantity;
    quantityText.setString(std::to_string(quantity));
}

bool foodButton::isActive() const {
    return active;
}

void foodButton::setActive(bool active) {
    foodButton::active = active;
    if (active) {
        backgroundTexture = assetManager::getInstance().getTexture("16x16darkActive");
    } else {
        backgroundTexture = assetManager::getInstance().getTexture("16x16dark");
    }
}

sf::Sprite foodButton::getSprite() {
    return backgroundSprite;
}

std::string foodButton::getName() {
    return buttonName;
}