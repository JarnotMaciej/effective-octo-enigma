#include "coin.h"

coin::coin()
{
    coinTexture = assetManager::getInstance().getTexture("coin");
    coinSprite.setTexture(coinTexture);
    coinSprite.setScale(2, 2);
}

void coin::draw(sf::RenderWindow &window)
{
    this->coinSprite.setTexture(coinTexture);
    window.draw(coinSprite);
}

void coin::setRandomPosition(sf::RenderWindow &window)
{
    int x = rand() % window.getSize().x;
    int y = rand() % 50;
    coinSprite.setPosition(x, y);
}

void coin::update()
{
    coinSprite.move(0, 4);
}
