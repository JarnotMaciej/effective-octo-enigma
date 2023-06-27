#include "scoreboard.h"

scoreboard::scoreboard() {
    mode = displayMode::DEFAULT;

    title.setString("Scoreboard");
    title.setFont(assetManager::getInstance().getFont("silkscreen"));
    title.setCharacterSize(96);
    title.setFillColor(sf::Color::White);
    title.setPosition(0, 0);

    this->scores = tamagotchiMechanics::getScores();

    for (score s: scores) {
        sf::Text text;
        text.setString(s.getTamagotchiName() + " " + std::to_string(s.getScoreNumber()));
        text.setFont(assetManager::getInstance().getFont("silkscreen"));
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        text.setPosition(0, 0);
        textScores.push_back(text);
    }

    buttons.emplace_back("Sort by score", "Q");
    buttons.emplace_back("Go back", "ESC");
    buttons.emplace_back("Sort by name", "W");

}

void scoreboard::draw(sf::RenderWindow &window) {
    window.draw(title);

    auto top5scores = std::views::take(textScores, 5);

    for (sf::Text text: top5scores) {
        window.draw(text);
    }
    for (auto button: buttons) {
        button.draw(window);
    }
}

void scoreboard::setPositions(sf::RenderWindow &window) {
    float x = (window.getSize().x - title.getGlobalBounds().width) / 2;
    float y = (0.3 * window.getSize().y - title.getGlobalBounds().height) / 2;
    title.setPosition(x, y);

    float height = textScores.front().getGlobalBounds().height;
    float margin = height + 20;
    float startY = 0.3 * window.getSize().y + margin;

    for (sf::Text &text: textScores) {

        x = (window.getSize().x - text.getGlobalBounds().width) / 2;
        text.setPosition(x, startY);
        startY += height + margin;
    }

    int buttonWidth = buttons[0].getSprite().getGlobalBounds().width;
    int buttonHeight = buttons[0].getSprite().getGlobalBounds().height;
    int buttonSpacing = (window.getSize().x - buttons.size() * buttonWidth) / (buttons.size() + 1);

    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].setPosition(buttonSpacing + i * (buttonSpacing + buttonWidth),
                               window.getSize().y - buttonHeight / 2 - 100);
    }
}

void scoreboard::handleInput(sf::RenderWindow &window, ScreenName &_screenName) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Escape) {
                    changeScreen(_screenName, ScreenName::MENU);
                }
                if (event.key.code == sf::Keyboard::Q) {
                    displayMode currentMode = getMode();
                    switch (currentMode) {
                        case displayMode::HIGHEST_SCORE:
                            ("LOWEST_SCORE");
                            setMode(displayMode::LOWEST_SCORE);
                            std::ranges::sort(scores, [](const score &a, const score &b) {
                                return a.getScoreNumber() < b.getScoreNumber();
                            });

                            break;
                        case displayMode::LOWEST_SCORE:
                            ("HIGHEST_SCORE");
                            setMode(displayMode::HIGHEST_SCORE);
                            std::ranges::sort(scores, [](const score &a, const score &b) {
                                return a.getScoreNumber() > b.getScoreNumber();
                            });

                            break;
                        default:
                            ("HIGHEST_SCORE");
                            setMode(displayMode::HIGHEST_SCORE);
                            std::ranges::sort(scores, [](const score &a, const score &b) {
                                return a.getScoreNumber() > b.getScoreNumber();
                            });

                            break;
                    }
                    scoresToText(window);
                }
                if (event.key.code == sf::Keyboard::W) {
                    displayMode currentMode = getMode();
                    switch (currentMode) {
                        case displayMode::ALPHABETICAL_NAME: {
                            ("REVERSE_ALPHABETICAL_NAME");
                            setMode(displayMode::REVERSE_ALPHABETICAL_NAME);
                            std::ranges::sort(scores, [](const score &a, const score &b) {
                                std::string nameA = a.getTamagotchiName();
                                std::string nameB = b.getTamagotchiName();

                                std::transform(nameA.begin(), nameA.end(), nameA.begin(), [](char c) {
                                    return std::tolower(c);
                                });
                                std::transform(nameB.begin(), nameB.end(), nameB.begin(), [](char c) {
                                    return std::tolower(c);
                                });

                                return nameA > nameB;
                            });
                        }
                            break;
                        case displayMode::REVERSE_ALPHABETICAL_NAME: {
                            setMode(displayMode::ALPHABETICAL_NAME);
                            std::ranges::sort(scores, [](const score &a, const score &b) {
                                std::string nameA = a.getTamagotchiName();
                                std::string nameB = b.getTamagotchiName();

                                std::transform(nameA.begin(), nameA.end(), nameA.begin(), [](char c) {
                                    return std::tolower(c);
                                });
                                std::transform(nameB.begin(), nameB.end(), nameB.begin(), [](char c) {
                                    return std::tolower(c);
                                });

                                return nameA < nameB;
                            });
                        }
                            break;
                        default: {
                            setMode(displayMode::REVERSE_ALPHABETICAL_NAME);
                            std::ranges::sort(scores, [](const score &a, const score &b) {
                                std::string nameA = a.getTamagotchiName();
                                std::string nameB = b.getTamagotchiName();

                                std::transform(nameA.begin(), nameA.end(), nameA.begin(), [](char c) {
                                    return std::tolower(c);
                                });
                                std::transform(nameB.begin(), nameB.end(), nameB.begin(), [](char c) {
                                    return std::tolower(c);
                                });

                                return nameA > nameB;
                            });
                        }
                            break;
                    }
                    scoresToText(window);
                }
                break;
            default:
                break;
        }
    }
}

void scoreboard::setMode(scoreboard::displayMode newMode) {
    mode = newMode;
}

scoreboard::displayMode scoreboard::getMode() {
    return mode;
}

void scoreboard::scoresToText(sf::RenderWindow &window) {
    for (int i = 0; i < scores.size(); i++) {
        textScores[i].setString(scores[i].getTamagotchiName() + " " + std::to_string(scores[i].getScoreNumber()));
    }
    setPositions(window);
}

void scoreboard::update(sf::RenderWindow &window, tamagotchi &pet) {
}

