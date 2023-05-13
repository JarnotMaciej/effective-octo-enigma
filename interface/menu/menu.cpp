//
// Created by menox on 06.05.2023.
//

#include "menu.h"


menu::menu() {
    // creating logo
    logo.setString("Tamagotchi");
    logo.setFont(assetManager::getInstance().getFont("silkscreen"));
	logo.setCharacterSize(128);
    logo.setFillColor(sf::Color::White);

    // creating buttons
    buttons.emplace_back("Start");
    buttons.emplace_back("Scoreboard");
    buttons.emplace_back("Credits");
    buttons.emplace_back("Exit");
}

void menu::setPositions(sf::RenderWindow &window) {
    float x = (window.getSize().x - buttons.front().getWidth()) / 2;
    float height = buttons.front().getHeight();
    float margin = (0.7 * window.getSize().y - buttons.size() * buttons.front().getHeight()) / (4 * buttons.size() - 2);
    if (margin < 0) {
        margin *= -1;
    }

    float startY = 0.3 * window.getSize().y + 2 * margin;

    for (button& button : buttons) {
        button.setPosition(x, startY + 2*margin);
        startY += height + margin;
    }

    // Set the position of the logo
    // center the logo horizontally
    x = (window.getSize().x - logo.getGlobalBounds().width) / 2;
    // center the logo vertically in the remaining space
    float y = (0.3 * window.getSize().y - logo.getGlobalBounds().height) / 2;
    logo.setPosition(x, y);
}

void menu::draw(sf::RenderWindow &window) {
    window.draw(logo);

    for (auto button : buttons) {
        button.draw(window);
    }
}

void menu::handleInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    for (auto &button : buttons) {
                        if (button.isMouseOver(window)) {
                            button.onClick();
                        }
                    }
                }
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
