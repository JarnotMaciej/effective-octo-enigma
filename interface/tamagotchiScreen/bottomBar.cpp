//
// Created by menox on 09.05.2023.
//

#include "bottomBar.h"

bottomBar::bottomBar() {
    buttons.emplace_back("Eat", "Q");
    buttons.emplace_back("Play", "W");
    buttons.emplace_back("Clean", "E");
    buttons.emplace_back("Sleep", "R");
}

void bottomBar::draw(sf::RenderWindow &window) {
    for (auto &button : buttons) {
        button.draw(window);
    }
}

void bottomBar::setPositions(sf::RenderWindow &window) {
    // distribute buttons evenly on the bottom of the screen
    int buttonWidth = buttons[0].getSprite().getGlobalBounds().width;
    int buttonHeight = buttons[0].getSprite().getGlobalBounds().height;
    int buttonSpacing = (window.getSize().x - buttons.size() * buttonWidth) / (buttons.size() + 1);

    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].setPosition(buttonSpacing + i * (buttonSpacing + buttonWidth),
                               window.getSize().y - buttonHeight / 2 - 100);
    }
}
