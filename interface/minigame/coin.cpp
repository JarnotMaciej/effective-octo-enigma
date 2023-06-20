#include "coin.h"

coin::coin()
{
    for (int i = 1; i <= animationFrames; i++)
    {
        std::string textureName = "coin_0" + std::to_string(i);
        animation.push_back(assetManager::getInstance().getTexture(textureName));
    }
    coinSprite.setTexture(animation[0]);
    coinSprite.setScale(.8, .8);
}

void coin::draw(sf::RenderWindow &window)
{
    this->coinSprite.setTexture(animation[currentFrame]);
//    this->coinSprite.setScale(.9, .9);
    window.draw(coinSprite);
}

void coin::setRandomPosition(sf::RenderWindow &window)
{
    int randExtent = window.getSize().x - coinSprite.getGlobalBounds().width;
    int x = rand() % randExtent;
    int y = rand() % 30;
    coinSprite.setPosition(x, y);
}

void coin::update()
{
    sf::Time time = clock.getElapsedTime();

    if (time.asMilliseconds() > animationTime)
    {
        currentFrame++;
        clock.restart();
    }

    if (currentFrame == animationFrames)
    {
        currentFrame = 0;
    }
    coinSprite.move(0, 5);
}
