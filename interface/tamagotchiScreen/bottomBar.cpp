//
// Created by menox on 09.05.2023.
//

#include "bottomBar.h"

bottomBar::bottomBar() {
    buttons.emplace_back("Eat", "Q");
    buttons.emplace_back("Play", "W");
    buttons.emplace_back("Wash", "E");
    buttons.emplace_back("Sleep", "R");
    buttons.emplace_back("Quit", "Esc");
}

void bottomBar::draw(sf::RenderWindow &window) {
    for (auto &button : buttons) {
        button.draw(window);
    }
}

void bottomBar::setPositions(sf::RenderWindow &window) {
    // distribute buttons evenly on the bottom of the screen
    std::vector<std::thread> posThreads;

    int buttonWidth = buttons[0].getSprite().getGlobalBounds().width;
    int buttonHeight = buttons[0].getSprite().getGlobalBounds().height;
    int buttonSpacing = (window.getSize().x - buttons.size() * buttonWidth) / (buttons.size() + 1);

    int i = 0;
    for (auto& button : buttons) {
        posThreads.emplace_back([&]() {
            button.setPosition(buttonSpacing + i * (buttonSpacing + buttonWidth),
                               window.getSize().y - buttonHeight / 2 - 100);
        });
        i++;
    }

    for (auto& thread : posThreads) {
        thread.join();
    }
}
