//
// Created by menox on 01.04.2023.
//

#include "programLogo.h"

void programLogo::draw(sf::RenderWindow& window)
{
	window.draw(logoText);
}

float programLogo::getPositionX()
{
	return logoText.getPosition().x;
}

float programLogo::getPositionY()
{
	return logoText.getPosition().y;
}

float programLogo::getWidth()
{
	return logoText.getGlobalBounds().width;
}

float programLogo::getHeight()
{
	return logoText.getGlobalBounds().height;
}

programLogo::programLogo()
{
	debug("Creating programLogo");
	font = assetManager::getFont("silkscreen");
	logoText.setFont(font);
	logoText.setString("Tamagotchi");
	logoText.setCharacterSize(40);
	logoText.setFillColor(sf::Color::White);
	logoText.setPosition(0, 0);
}

void programLogo::setPosition(float x, float y)
{
	logoText.setPosition(x, y);
}
