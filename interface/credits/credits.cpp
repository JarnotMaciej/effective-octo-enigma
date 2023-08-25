#include "credits.h"

credits::credits(std::vector<sf::Text> &_texts) {
    texts = _texts;
    backButton = keycapButton("Go back", "ESC");
}

void credits::draw(sf::RenderWindow &window) {
    for (auto &text: texts) {
        window.draw(text);
    }
    backButton.draw(window);
}

void credits::handleInput(sf::RenderWindow &window, ScreenName &_screenName) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _screenName = ScreenName::EXIT_SCREEN;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            _screenName = ScreenName::MENU;
        }
    }
}

void credits::update(sf::RenderWindow &window, tamagotchi &pet) {
    if (clock.getElapsedTime().asSeconds() > 0.03) {
        for (int i = 0; i < texts.size(); i++) {
            if (texts[i].getPosition().y + texts[i].getGlobalBounds().height * 2 < 0) {
                texts.erase(texts.begin() + i);
            }
        }

        for (int i = 0; i < texts.size() - 1; i++) {
            texts[i].move(0, -1);
        }

        if (texts[texts.size() - 1].getPosition().y > window.getSize().y / 2) {
            texts[texts.size() - 1].move(0, -1);
        }
        clock.restart();
    }
}

void credits::setPositions(sf::RenderWindow &window) {
    float x = (window.getSize().x - texts[0].getGlobalBounds().width) / 2;
    float y = window.getSize().y;

    auto setPosition = [&](sf::Text &text) {
        x = (window.getSize().x - text.getGlobalBounds().width) / 2;
        text.setPosition(x, y);
        y += text.getGlobalBounds().height * 2 + 10;
    };
    for (auto &text: texts) {
        x = (window.getSize().x - text.getGlobalBounds().width) / 2;
        text.setPosition(x, y);
        y += text.getGlobalBounds().height * 2 + 10;
    }

    backButton.setPosition((window.getSize().x - backButton.getSprite().getGlobalBounds().width) / 2,
                           window.getSize().y - backButton.getSprite().getGlobalBounds().height / 2 - 100);
}
