//
// Created by menox on 12.05.2023.
//

#include "tamagotchiScreen.h"

void tamagotchiScreen::setPositions(sf::RenderWindow &window) {
    this->ts_topbar.setPosition(window);
    this->ts_indicatorbar.setPositions(window);
    this->ts_bottombar.setPositions(window);
    // set center position in window
    this->tamagotchiSprite.setPosition(window.getSize().x / 2 - this->tamagotchiSprite.getGlobalBounds().width / 2,
                                       window.getSize().y / 2 - this->tamagotchiSprite.getGlobalBounds().height / 2);
}

void tamagotchiScreen::draw(sf::RenderWindow &window) {
    this->ts_topbar.draw(window);
    this->ts_indicatorbar.draw(window);
    this->ts_bottombar.draw(window);
    tamagotchiSprite.setTexture(this->tamagotchiTexture);
    window.draw(this->tamagotchiSprite);
}

void tamagotchiScreen::update(sf::RenderWindow &window, tamagotchi &pet) {
    this->ts_indicatorbar.update(pet);
    this->ts_indicatorbar.update(pet);
    this->ts_topbar.update(pet, window);
}

void tamagotchiScreen::handleInput(sf::RenderWindow &window, ScreenName &_screenName) {
    // TODO -> implement, this is temporary
    sf::Event event;
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
                        break;
                    case sf::Keyboard::W:
                        changeScreen(_screenName, ScreenName::MINIGAME);
                        break;
                    case sf::Keyboard::E:
                        washPet(window);
                        break;
                    case sf::Keyboard::R:
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

tamagotchiScreen::tamagotchiScreen(const std::string& textureName, tamagotchi &pet) {
    this->pet_pointer = static_cast<const std::shared_ptr<tamagotchi>>(&pet);
    tamagotchiTexture = assetManager::getInstance().getTexture(textureName);
    tamagotchiSprite.setTexture(tamagotchiTexture);
}

void tamagotchiScreen::washPet(sf::RenderWindow &window) {
    this->pet_pointer->setHygiene(100);
    // display text that pet is clean
    sf::Text text;
    text.setFont(assetManager::getInstance().getFont("silkscreen"));
    text.setString("Pet is clean!");
    text.setCharacterSize(48);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2,
                     (window.getSize().y / 2 - text.getGlobalBounds().height / 2) - 250);
    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 2) {
        window.draw(text);
        window.display();
    }
}
