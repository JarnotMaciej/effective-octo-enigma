//
// Created by menox on 12.05.2023.
//

#include "tamagotchiScreen.h"

void tamagotchiScreen::setPositions(sf::RenderWindow &window) {
    this->ts_topbar.setPosition(window);
    this->ts_indicatorbar.setPositions(window);
    this->ts_bottombar.setPositions(window);
    this->ts_foodbar.setPositions(window);

    // set center position in window
    this->tamagotchiSprite.setPosition(window.getSize().x / 2 - this->tamagotchiSprite.getGlobalBounds().width / 2,
                                       window.getSize().y / 2 - this->tamagotchiSprite.getGlobalBounds().height / 2 -
                                       50);


    // set position of zzz text
    this->zzzText.setPosition(window.getSize().x / 2 - this->zzzText.getGlobalBounds().width / 2,
                              (window.getSize().y / 2 - zzzText.getGlobalBounds().height / 2) - 300);
}

//void tamagotchiScreen::draw(sf::RenderWindow &window) {
//    this->ts_topbar.draw(window);
//    this->ts_indicatorbar.draw(window);
//    this->ts_bottombar.draw(window);
//    if (eatBarEnabled) {
//        this->ts_foodbar.draw(window);
//    }
//
//    tamagotchiSprite.setTexture(this->tamagotchiTexture);
//    if (this->pet_pointer->getIsSleeping()) {
//        window.draw(this->zzzText);
//    }
//    window.draw(this->tamagotchiSprite);
//}

void tamagotchiScreen::draw(sf::RenderWindow &window) {
    this->ts_topbar.draw(window);
    this->ts_indicatorbar.draw(window);
    this->ts_bottombar.draw(window);

    if (eatBarEnabled && !pet_pointer->getIsSleeping()) {
        this->ts_foodbar.draw(window);
    }

    tamagotchiSprite.setTexture(this->tamagotchiTexture);
    if (this->pet_pointer->getIsSleeping()) {
        window.draw(this->zzzText);
    }
    window.draw(this->tamagotchiSprite);
}


void tamagotchiScreen::update(sf::RenderWindow &window, tamagotchi &pet) {
    tamagotchiMechanics::sleepMechanics(pet);
    this->ts_indicatorbar.update(pet);
    this->ts_topbar.update(pet, window);

    // if pet is sleeping, display zzz text
    if (pet.getIsSleeping()) {
        // clock for zzz animation -> every 0.5 seconds from 0 to 3 dots
        if (this->zzzClock.getElapsedTime().asSeconds() > 0.5) {
            if (this->zzzText.getString() == "ZZZ...") {
                this->zzzText.setString("ZZZ..");
            } else if (this->zzzText.getString() == "ZZZ..") {
                this->zzzText.setString("ZZZ.");
            } else if (this->zzzText.getString() == "ZZZ.") {
                this->zzzText.setString("ZZZ");
            } else if (this->zzzText.getString() == "ZZZ") {
                this->zzzText.setString("ZZZ...");
            }
            this->zzzClock.restart();
        }
    }

}

void tamagotchiScreen::handleInput(sf::RenderWindow &window, ScreenName &_screenName) {
    sf::Event event;

    // Check if the pet is sleeping
    bool isSleeping = pet_pointer->getIsSleeping();

    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        changeScreen(_screenName, ScreenName::MENU);
                        break;
                    case sf::Keyboard::Q:
                        // switch between eatbarEnabled true or false
                        if(!this->pet_pointer->getIsSleeping()) {
                            eatBarEnabled = !eatBarEnabled;
                        }
                        break;
                    case sf::Keyboard::W:
                        if (!isSleeping) {
                            changeScreen(_screenName, ScreenName::MINIGAME);
                        }
                        break;
                    case sf::Keyboard::E:
                        if (!isSleeping) {
                            washPet(window);
                        }
                        break;
                    case sf::Keyboard::R:
                        sleepPet(window);
                        break;
                    case sf::Keyboard::A:
                        if (!isSleeping && eatBarEnabled) {
                            this->ts_foodbar.activatePreviousButton();
                        }
                        break;
                    case sf::Keyboard::D:
                        if (!isSleeping && eatBarEnabled) {
                            this->ts_foodbar.activateNextButton();
                        }
                        break;
                    case sf::Keyboard::Space:
                        if (!isSleeping && eatBarEnabled) {
                            this->ts_foodbar.eatFood();
                        }
                        break;
                    case sf::Keyboard::S:
                        if (!isSleeping && eatBarEnabled) {
                            this->ts_foodbar.sellFood();
                        }
                        break;
                    case sf::Keyboard::B:
                        if (!isSleeping && eatBarEnabled) {
                            this->ts_foodbar.buyFood();
                        }
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}


tamagotchiScreen::tamagotchiScreen(const std::string &textureName, tamagotchi &pet, std::map<std::string, food> &_allOfTheFoods) {
    this->pet_pointer = static_cast<const std::shared_ptr<tamagotchi>>(&pet);
    this->allOfTheFoods = static_cast<const std::shared_ptr<std::map<std::string, food>>>(&_allOfTheFoods);
    tamagotchiTexture = assetManager::getInstance().getTexture(textureName);
    tamagotchiSprite.setTexture(tamagotchiTexture);

    // food bar

    this->ts_foodbar = foodBar(*this->allOfTheFoods);

    // set zzz text
    zzzText.setString("ZZZ...");
    zzzText.setFont(assetManager::getInstance().getFont("silkscreen"));
    zzzText.setCharacterSize(48);
    zzzText.setFillColor(sf::Color::White);
    zzzText.setPosition(0, 0);

    // set eat bar to false
    eatBarEnabled = false;
}

void tamagotchiScreen::washPet(sf::RenderWindow &window) {
    this->pet_pointer->setHygiene(100);
    this->ts_indicatorbar.update(*pet_pointer);
    // display text that pet is clean
    sf::Text text;
    text.setFont(assetManager::getInstance().getFont("silkscreen"));
    text.setString("Pet is clean!");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2,
                     (window.getSize().y / 2 - text.getGlobalBounds().height / 2) - 300);
    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 2) {
        window.draw(text);
        window.display();
    }
}

void tamagotchiScreen::sleepPet(sf::RenderWindow &window) {
    bool isSleeping = pet_pointer->getIsSleeping();
    if (isSleeping) {
        pet_pointer->setIsSleeping(false);
    } else {
        eatBarEnabled = false;
        pet_pointer->setSleepStart(getTime());
        pet_pointer->setIsSleeping(true);
    }
}

