//
// Created by menox on 06.06.2023.
//

#include "foodBar.h"

foodBar::foodBar(std::vector<food> _myFood) {
    // load font

    // set text
    equipmentMove.setString("Use A and D to move");
    equipmentMove.setFont(assetManager::getInstance().getFont("silkscreen"));
    equipmentMove.setCharacterSize(22);
    equipmentMove.setFillColor(sf::Color::White);

    sellText.setString("Press S to sell");
    sellText.setFont(assetManager::getInstance().getFont("silkscreen"));
    sellText.setCharacterSize(22);
    sellText.setFillColor(sf::Color::White);

    buyText.setString("Press B to buy");
    buyText.setFont(assetManager::getInstance().getFont("silkscreen"));
    buyText.setCharacterSize(22);
    buyText.setFillColor(sf::Color::White);

    eatText.setFont(assetManager::getInstance().getFont("silkscreen"));
    eatText.setString("Press Space to eat");
    eatText.setCharacterSize(22);
    eatText.setFillColor(sf::Color::White);

    // set positions of texts
    equipmentMove.setPosition(10, 10);
    sellText.setPosition(10, 40);
    buyText.setPosition(10, 70);
    eatText.setPosition(10, 100);

    // create buttons
    for (auto & i : _myFood) {
        buttons.emplace_back(i.getName());
    }
}

void foodBar::draw(sf::RenderWindow &window) {
    // draw texts
    window.draw(equipmentMove);
    window.draw(sellText);
    window.draw(buyText);
    window.draw(eatText);

    // draw buttons
    for (auto & i : buttons) {
        i.draw(window);
    }
}

void foodBar::setPositions(sf::RenderWindow &window) {
    int buttonWidth = buttons[0].getSprite().getGlobalBounds().width;
    int buttonHeight = buttons[0].getSprite().getGlobalBounds().height;
    int buttonSpacing = (window.getSize().x - buttons.size() * buttonWidth) / (buttons.size() + 1);

    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].setPosition(buttonSpacing + i * (buttonSpacing + buttonWidth),
                               window.getSize().y - buttonHeight / 2 - 220);
    }

    // set positions of texts -> above buttons, left aligned to the leftmost button
    eatText.setPosition(buttons[0].getSprite().getPosition().x, buttons[0].getSprite().getPosition().y - eatText.getGlobalBounds().height - 60);
    buyText.setPosition(buttons[0].getSprite().getPosition().x, eatText.getPosition().y - buyText.getGlobalBounds().height - 10);
    sellText.setPosition(buttons[0].getSprite().getPosition().x, buyText.getPosition().y - sellText.getGlobalBounds().height - 10);
    equipmentMove.setPosition(buttons[0].getSprite().getPosition().x, sellText.getPosition().y - equipmentMove.getGlobalBounds().height - 10);


}

