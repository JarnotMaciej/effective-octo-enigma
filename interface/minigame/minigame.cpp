//
// Created by menox on 06.05.2023.
//

#include "minigame.h"

minigame::minigame(std::string textureName)
{
    // setting time and coins
    time = 30;
    coins = 0;
    maxCoins = 12;

    // setting time text
    timeText.setString("0:30");
    timeText.setFillColor(sf::Color::White);
    timeText.setCharacterSize(64);
    timeText.setFont(assetManager::getInstance().getFont("silkscreen"));

    // setting coins text
    coinsText.setString("000");
    coinsText.setFillColor(sf::Color::White);
    coinsText.setCharacterSize(64);
    coinsText.setFont(assetManager::getInstance().getFont("silkscreen"));

    // setting textures and sprites
    texture = assetManager::getInstance().getTexture(textureName);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(0.4, 0.4);
}

void minigame::draw(sf::RenderWindow &window)
{
    this->sprite.setTexture(texture);
    window.draw(sprite);
    window.draw(timeText);
    window.draw(coinsText);
}

void minigame::handleInput(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::A)
            {
                if(sprite.getPosition().x >= 15){
                    sprite.move(-15, 0);
                } else {
                    sprite.setPosition(0, sprite.getPosition().y);
                }
            }
            if (event.key.code == sf::Keyboard::D)
            {
                if(sprite.getPosition().x <= window.getSize().x - sprite.getGlobalBounds().width - 15){
                    sprite.move(15, 0);
                } else {
                    sprite.setPosition(window.getSize().x - sprite.getGlobalBounds().width, sprite.getPosition().y);
                }
            }
            break;
        }
    }
}

void minigame::setPositions(sf::RenderWindow &window)
{
    int margin = 32;
    // setting time text position -> top left corner
    timeText.setPosition(margin, margin);

    // setting coins text position -> top right corner
    coinsText.setPosition(window.getSize().x - coinsText.getGlobalBounds().width - margin, margin);

    // setting sprite position -> bottom center
    sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width) / 2, window.getSize().y - sprite.getGlobalBounds().height);
}
