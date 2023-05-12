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

void tamagotchiScreen::update(tamagotchi &pet, sf::RenderWindow &window) {
    this->ts_indicatorbar.update(pet);
    this->ts_topbar.update(pet, window);
}

void tamagotchiScreen::handleInput(sf::RenderWindow &window) {
    // TODO -> implement, this is temporary
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                break;
            default:
                break;
        }
    }
}

void tamagotchiScreen::setTamagotchiTexture(const std::string &name) {
    this->tamagotchiTexture = assetManager::getInstance().getTexture(name);
    this->tamagotchiSprite.setTexture(this->tamagotchiTexture);
}
