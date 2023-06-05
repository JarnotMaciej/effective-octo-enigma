//
// Created by menox on 06.05.2023.
//

#include "minigame.h"

#include <utility>

minigame::minigame(std::string textureName, const std::shared_ptr<minigameConnector> &_magicConnector)
{
    // set connector
    magicConnector = _magicConnector;

    // setting time and coins
    time = 30;
    coins = 0;
    maxCoins = 12;
    isRunning = true;

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

    coinSoundBuffer = assetManager::getInstance().getSound("coin1", "ogg");
}

void minigame::draw(sf::RenderWindow &window)
{
    // drawing coins
    for (auto &coin : coinsVector)
    {
        coin.draw(window);
    }

    // other stuff
    this->sprite.setTexture(texture);
    window.draw(sprite);
    window.draw(timeText);
    window.draw(coinsText);
}

void minigame::handleInput(sf::RenderWindow &window, ScreenName &_screenName)
{
    sf::Event event;

    if (isRunning)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A)
                {
                    if (sprite.getPosition().x >= petSpeed)
                    {
                        sprite.move(-petSpeed, 0);
                    }
                    else
                    {
                        sprite.setPosition(0, sprite.getPosition().y);
                    }
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    if (sprite.getPosition().x <= window.getSize().x - sprite.getGlobalBounds().width - petSpeed)
                    {
                        sprite.move(petSpeed, 0);
                    }
                    else
                    {
                        sprite.setPosition(window.getSize().x - sprite.getGlobalBounds().width,
                                           sprite.getPosition().y);
                    }
                }
            }
            else if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }
    else
    {
        isRunning = true;
        // play sound
        minigameSound.setBuffer(assetManager::getInstance().getSound("gameover", "wav"));
        minigameSound.play();
        changeScreen(_screenName, ScreenName::GAME_OVER);
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
    sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width) / 2,
                       window.getSize().y - sprite.getGlobalBounds().height);
}

void minigame::update(sf::RenderWindow &window, tamagotchi &pet)
{
    if (time == 0)
    {
        isRunning = false;

        // TODO -> connector here
        magicConnector->setCoinsValue(coins);

        // Add coins to pet
        pet.setMoney(pet.getMoney() + coins);

        coins = 0;
        time = 30;

        // Erase all coins
        coinsVector.clear();
    }

    if (isRunning)
    {
        // updating time according to clock from SFML
        if (minigameClock.getElapsedTime().asSeconds() >= 1 && time > 0)
        {
            time--;
            minigameClock.restart();
        }

        // spawning coins if there are less than maxCoins and the coin clock is greater than 400ms
        if (coinsVector.size() < maxCoins && coinClock.getElapsedTime().asMilliseconds() >= 400)
        {
            coin newCoin;
            newCoin.setRandomPosition(window);
            coinsVector.push_back(newCoin);
            coinClock.restart();
        }

        // updating coins
        for (auto &coin : coinsVector)
        {
            coin.update();
        }

        // checking if player has collected a coin
        for (int i = 0; i < coinsVector.size(); i++)
        {
            if (coinsVector[i].getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))
            {
                coinsVector.erase(coinsVector.begin() + i);
                // Play the coin sound
                setCoinSoundBuffer();
                minigameSound.setBuffer(coinSoundBuffer);
                minigameSound.setVolume(50.f);
                minigameSound.play();

                coins++;
            }
        }

        // deleting coins that are out of screen
        for (int i = 0; i < coinsVector.size(); i++)
        {
            if (coinsVector[i].getSprite().getPosition().y > window.getSize().y)
            {
                coinsVector.erase(coinsVector.begin() + i);
            }
        }

        //------------------------
        // displaying time in format 0:00
        if (time >= 10)
        {
            timeText.setString("0:" + std::to_string(time));
        }
        else
        {
            timeText.setString("0:0" + std::to_string(time));
        }

        // updating coins text in 000 format
        if (coins < 10)
        {
            coinsText.setString("00" + std::to_string(coins));
        }
        else if (coins < 100)
        {
            coinsText.setString("0" + std::to_string(coins));
        }
        else
        {
            coinsText.setString(std::to_string(coins));
        }
    }
}

void minigame::setCoinSoundBuffer()
{
    // generating random number from 1 to 12
    int random = rand() % 12 + 1;
    std::string soundName = "coin" + std::to_string(random);
    coinSoundBuffer = assetManager::getInstance().getSound(soundName, "ogg");
}
