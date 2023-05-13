//
// Created by menox on 13.05.2023.
//

#include "scoreboard.h"

scoreboard::scoreboard() {
    title.setString("Scoreboard");
    title.setFont(assetManager::getInstance().getFont("silkscreen"));
    title.setCharacterSize(96);
    title.setFillColor(sf::Color::White);
    title.setPosition(0, 0);

    std::vector<score> myScores = tamagotchiMechanics::getScores();

    for (score s : myScores) {
        sf::Text text;
        text.setString(s.getTamagotchiName() + " " + std::to_string(s.getScoreNumber()));
        text.setFont(assetManager::getInstance().getFont("silkscreen"));
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        text.setPosition(0, 0);
        textScores.push_back(text);
    }
}

void scoreboard::draw(sf::RenderWindow &window) {
    window.draw(title);

    int i = 0;
    for (sf::Text text : textScores) {
        window.draw(text);
        i++;
    }
}

void scoreboard::setPositions(sf::RenderWindow &window) {
    // center the logo horizontally
    float x = (window.getSize().x - title.getGlobalBounds().width) / 2;
    // center the logo vertically
    float y = (0.3 * window.getSize().y - title.getGlobalBounds().height) / 2;
    title.setPosition(x, y);

    // list the scores in a column in the remaining space

    // calculate the height of the column
    float height = textScores.front().getGlobalBounds().height;
    // margin between the scores
//    float margin = (0.7 * window.getSize().y - textScores.size() * height) / (textScores.size() + 1);
    float margin = height + 20;

    // calculate the starting y position
    float startY = 0.3 * window.getSize().y + margin;

    for (sf::Text& text : textScores) {
        // center the text horizontally
        x = (window.getSize().x - text.getGlobalBounds().width) / 2;
        text.setPosition(x, startY);
        startY += height + margin;
    }
}

void scoreboard::handleInput(sf::RenderWindow &window) {
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
