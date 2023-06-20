//
// Created by menox on 06.05.2023.
//

#include "minigame.h"

#include <utility>

minigame::minigame(std::string textureName, const std::shared_ptr<minigameConnector> &_magicConnector) {
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

    isMovingLeft = false;
    isMovingRight = false;

    coinSoundBuffer = assetManager::getInstance().getSound("coin1", "ogg");
}

void minigame::draw(sf::RenderWindow &window) {
    // drawing coins
    for (auto &coin: coinsVector) {
        coin.draw(window);
    }

    // other stuff
//    this->sprite.setTexture(texture);
    window.draw(sprite);
    window.draw(timeText);
    window.draw(coinsText);
}

void minigame::handleInput(sf::RenderWindow &window, ScreenName &_screenName) {
    sf::Event event;

    if (isRunning) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    isMovingLeft = true;
                } else if (event.key.code == sf::Keyboard::D) {
                    isMovingRight = true;
                }
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::A) {
                    isMovingLeft = false;
                } else if (event.key.code == sf::Keyboard::D) {
                    isMovingRight = false;
                }
            } else if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    } else {
        isRunning = true;
        // play sound
        minigameSound.setBuffer(assetManager::getInstance().getSound("gameover", "wav"));
        minigameSound.play();
        changeScreen(_screenName, ScreenName::GAME_OVER);
    }
}

void minigame::setPositions(sf::RenderWindow &window) {
    int margin = 32;
    // setting time text position -> top left corner
    timeText.setPosition(margin, margin);

    // setting coins text position -> top right corner
    coinsText.setPosition(window.getSize().x - coinsText.getGlobalBounds().width - margin, margin);

    // setting sprite position -> bottom center
    sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width) / 2,
                       window.getSize().y - sprite.getGlobalBounds().height);
}

void minigame::update(sf::RenderWindow &window, tamagotchi &pet) {
    static const int MAX_TIME = 30;
    static const int COIN_SPAWN_INTERVAL_MS = 400;

    std::stringstream ss;

    if (time == 0) {
        isRunning = false;

        magicConnector->setCoinsValue(coins);

        // Add coins to pet
        pet.setMoney(pet.getMoney() + coins);

        // Modify indicators
        auto happiness = pet.getHappiness() + 20;
        auto hunger = pet.getHunger() - 10;
        auto hygiene = pet.getHygiene() - 15;
        auto energy = pet.getEnergy() - 10;

        pet.setHappiness(std::min(happiness, 100));
        pet.setHunger(std::max(hunger, 0));
        pet.setHygiene(std::max(hygiene, 0));
        pet.setEnergy(std::max(energy, 0));

        coins = 0;
        time = MAX_TIME;

        // Erase all coins
        coinsVector.clear();
    }

    if (isRunning) {
        std::thread threadForMoving([&]() {
            // Task 2: Move the pet based on continuous input
            if (isMovingLeft && sprite.getPosition().x >= petSpeed) {
                sprite.move(-petSpeed, 0);
            } else if (isMovingRight &&
                       sprite.getPosition().x <= window.getSize().x - sprite.getGlobalBounds().width - petSpeed) {
                sprite.move(petSpeed, 0);
            }
        });

        // updating time according to clock from SFML
        if (minigameClock.getElapsedTime().asSeconds() >= 1 && time > 0) {
            time--;
            minigameClock.restart();
        }

        // spawning coins if there are less than maxCoins and the coin clock is greater than COIN_SPAWN_INTERVAL_MS
        if (coinsVector.size() < maxCoins && coinClock.getElapsedTime().asMilliseconds() >= COIN_SPAWN_INTERVAL_MS) {
            coin newCoin;
            newCoin.setRandomPosition(window);
            coinsVector.push_back(newCoin);
            coinClock.restart();
        }

        // updating coins and checking if player has collected a coin
        auto spriteBounds = sprite.getGlobalBounds();
        coinsVector.erase(std::remove_if(coinsVector.begin(), coinsVector.end(), [&](coin &c) {
            c.update(); // update the coin position
            if (c.getSprite().getGlobalBounds().intersects(spriteBounds)) { // check if the coin intersects with the pet
                // Play the coin sound
                setCoinSoundBuffer();
                minigameSound.setBuffer(coinSoundBuffer);
                minigameSound.setVolume(50.f);
                minigameSound.play();

                coins++;
                return true; // remove the coin from the vector
            }
            return c.getSprite().getPosition().y > window.getSize().y;
        }), coinsVector.end());

        //------------------------
        // displaying time in format 0:00
        timeText.setString("0:" + std::to_string(time / 10) + std::to_string(time % 10));

        // updating coins text in 000 format
        coinsText.setString(std::to_string(coins));
        coinsText.setString(std::string(3 - coinsText.getString().getSize(), '0') + coinsText.getString());

        threadForMoving.join();
    }
}


void minigame::setCoinSoundBuffer() {
    // generating random number from 1 to 12
    int random = rand() % 12 + 1;
    std::string soundName = "coin" + std::to_string(random);
    coinSoundBuffer = assetManager::getInstance().getSound(soundName, "ogg");
}
