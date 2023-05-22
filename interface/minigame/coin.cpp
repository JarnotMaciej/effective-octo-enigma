#include "coin.h"

coin::coin(sf::RenderWindow &window)
{
    coinTexture = assetManager::getInstance().getTexture("coin");
    coinSprite.setTexture(coinTexture);
    // coinSprite.setScale(0.1, 0.1);
}

void coin::draw(sf::RenderWindow &window)
{
    this->coinSprite.setTexture(coinTexture);
    window.draw(coinSprite);
}
