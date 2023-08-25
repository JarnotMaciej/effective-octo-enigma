#include "minigame.h"

minigame::minigame(std::string textureName, const std::shared_ptr<minigameConnector> &_magicConnector) {
    magicConnector = _magicConnector;

    time = 30;
    coins = 0;
    maxCoins = 12;
    isRunning = true;

    timeText.setString("0:30");
    timeText.setFillColor(sf::Color::White);
    timeText.setCharacterSize(64);
    timeText.setFont(assetManager::getInstance().getFont("silkscreen"));

    coinsText.setString("000");
    coinsText.setFillColor(sf::Color::White);
    coinsText.setCharacterSize(64);
    coinsText.setFont(assetManager::getInstance().getFont("silkscreen"));

    texture = assetManager::getInstance().getTexture(textureName);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    sprite.setScale(0.4, 0.4);

    isMovingLeft = false;
    isMovingRight = false;
    coinSoundBuffer = assetManager::getInstance().getSound("coin1", "ogg");
}

void minigame::draw(sf::RenderWindow &window) {
    for (auto &coin: coinsVector) {
        coin.draw(window);
    }
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

        minigameSound.setBuffer(assetManager::getInstance().getSound("gameover", "wav"));
        minigameSound.play();
        changeScreen(_screenName, ScreenName::GAME_OVER);
    }
}

void minigame::setPositions(sf::RenderWindow &window) {
    int margin = 32;

    timeText.setPosition(margin, margin);
    coinsText.setPosition(window.getSize().x - coinsText.getGlobalBounds().width - margin, margin);
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

        pet.setMoney(pet.getMoney() + coins);

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

        sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width) / 2,
                           window.getSize().y - sprite.getGlobalBounds().height);
        isMovingLeft = false;
        isMovingRight = false;

        coinsVector.clear();
    }

    if (isRunning) {
        std::thread threadForMoving([&]() {
            if (isMovingLeft && sprite.getPosition().x >= petSpeed) {
                sprite.move(-petSpeed, 0);
            } else if (isMovingRight &&
                       sprite.getPosition().x <= window.getSize().x - sprite.getGlobalBounds().width - petSpeed) {
                sprite.move(petSpeed, 0);
            }
        });

        if (minigameClock.getElapsedTime().asSeconds() >= 1 && time > 0) {
            time--;
            minigameClock.restart();
        }

        if (coinsVector.size() < maxCoins && coinClock.getElapsedTime().asMilliseconds() >= COIN_SPAWN_INTERVAL_MS) {
            coin newCoin;
            newCoin.setRandomPosition(window);
            coinsVector.push_back(newCoin);
            coinClock.restart();
        }

        auto spriteBounds = sprite.getGlobalBounds();
        coinsVector.erase(std::remove_if(coinsVector.begin(), coinsVector.end(), [&](coin &c) {
            c.update();
            if (c.getSprite().getGlobalBounds().intersects(spriteBounds)) {
                setCoinSoundBuffer();
                minigameSound.setBuffer(coinSoundBuffer);
                minigameSound.setVolume(50.f);
                minigameSound.play();

                coins++;
                return true;
            }
            return c.getSprite().getPosition().y > window.getSize().y;
        }), coinsVector.end());

        timeText.setString("0:" + std::to_string(time / 10) + std::to_string(time % 10));

        coinsText.setString(std::to_string(coins));
        coinsText.setString(std::string(3 - coinsText.getString().getSize(), '0') + coinsText.getString());

        threadForMoving.join();
    }
}

void minigame::setCoinSoundBuffer() {
    int random = rand() % 12 + 1;
    std::string soundName = "coin" + std::to_string(random);
    coinSoundBuffer = assetManager::getInstance().getSound(soundName, "ogg");
}
