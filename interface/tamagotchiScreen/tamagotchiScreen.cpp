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

tamagotchiScreen::tamagotchiScreen(const std::string& textureName) {
    tamagotchiTexture = assetManager::getInstance().getTexture(textureName);
    tamagotchiSprite.setTexture(tamagotchiTexture);
}
