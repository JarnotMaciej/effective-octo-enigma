//
// Created by menox on 01.04.2023.
//

#include "button.h"

void button::draw(sf::RenderWindow& window)
{
	window.draw(buttonSprite);
	centerText();
	window.draw(buttonText);
}

float button::getPositionX()
{
	return buttonSprite.getPosition().x;
}

float button::getPositionY()
{
	return buttonSprite.getPosition().y;
}

float button::getWidth()
{
	return buttonSprite.getGlobalBounds().width;
}

float button::getHeight()
{
	return buttonSprite.getGlobalBounds().height;
}

bool button::isMouseOver(sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	return buttonSprite.getGlobalBounds().contains(mousePosF);
}

void button::onClick()
{
	std::cout << "Clicked" << std::endl;
}

button::button(const sf::String& text)
{
	debug("Creating button");
	// loading textures
	buttonTexture = assetManager::getInstance().getTexture("48x16white");
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(0, 0);
	buttonSprite.setScale(8, 8);

	// loading font
	font = assetManager::getInstance().getFont("silkscreen");

	textColor = sf::Color(70, 75, 95, 255);
	buttonText.setFont(font);
	buttonText.setString(text);
	buttonText.setCharacterSize(40);
	buttonText.setFillColor(textColor);

}

void button::setPosition(float x, float y)
{
	buttonSprite.setPosition(x, y);
	centerText();
}

void button::centerText()
{
	sf::FloatRect textRect = buttonText.getLocalBounds();
	buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	buttonText.setPosition(getPositionX() + buttonSprite.getGlobalBounds().width / 2,
		getPositionY() + buttonSprite.getGlobalBounds().height / 2);
}

void button::handleInput(sf::RenderWindow &window) {
    if (isMouseOver(window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            onClick();
        }
    }
}
