#include "button.h"

void button::draw(sf::RenderWindow &window) {
    this->buttonSprite.setTexture(buttonTexture);
    window.draw(buttonSprite);
    centerText();
    window.draw(buttonText);
}

float button::getPositionX() {
    return buttonSprite.getPosition().x;
}

float button::getPositionY() {
    return buttonSprite.getPosition().y;
}

float button::getWidth() {
    return buttonSprite.getGlobalBounds().width;
}

float button::getHeight() {
    return buttonSprite.getGlobalBounds().height;
}

bool button::isMouseOver(sf::RenderWindow &window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    return buttonSprite.getGlobalBounds().contains(mousePosF);
}

button::button(const sf::String &text) {
    buttonTexture = assetManager::getInstance().getTexture("64x16dark");
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setPosition(0, 0);
    buttonSprite.setScale(6.5, 6.5);

    font = assetManager::getInstance().getFont("silkscreen");

    textColor = sf::Color::White;
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(40);
    buttonText.setFillColor(textColor);
}

void button::setPosition(float x, float y) {
    buttonSprite.setPosition(x, y);
    centerText();
}

void button::centerText() {
    sf::FloatRect textRect = buttonText.getLocalBounds();
    buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
                         textRect.top + textRect.height / 2.0f);
    buttonText.setPosition(getPositionX() + buttonSprite.getGlobalBounds().width / 2,
                           getPositionY() + buttonSprite.getGlobalBounds().height / 2);
}
