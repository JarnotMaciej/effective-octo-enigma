//
// Created by menox on 22.06.2023.
//

#include "credits.h"

credits::credits(std::vector<sf::Text> &_texts) {
    texts = _texts;
    backButton = keycapButton("Go back", "ESC");
}

void credits::draw(sf::RenderWindow &window) {
    for (auto &text : texts) {
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
    // move texts up using clock
    if (clock.getElapsedTime().asSeconds() > 0.03) {
        // if the text is above the screen, remove it
        for (int i = 0; i < texts.size(); i++) {
            if (texts[i].getPosition().y + texts[i].getGlobalBounds().height * 2 < 0) {
                texts.erase(texts.begin() + i);
            }
        }

        // move texts up without last text
        for (int i = 0; i < texts.size() - 1; i++) {
            texts[i].move(0, -1);
        }

        // move last text up, if it is on the center, keep it there
        if (texts[texts.size() - 1].getPosition().y > window.getSize().y / 2) {
            texts[texts.size() - 1].move(0, -1);
        }
        clock.restart();
    }

}

void credits::setPositions(sf::RenderWindow &window) {
    // set position of texts, center them horizontally, and set them below each other
//    std::vector<std::thread> posThreads;
    float x = (window.getSize().x - texts[0].getGlobalBounds().width) / 2;
    float y = window.getSize().y;

    // set position lambda
    auto setPosition = [&](sf::Text &text) {
        x = (window.getSize().x - text.getGlobalBounds().width) / 2;
        text.setPosition(x, y);
        y += text.getGlobalBounds().height * 2 + 10;
    };

    for (auto &text : texts) {
        x = (window.getSize().x - text.getGlobalBounds().width) / 2;
        text.setPosition(x, y);
        y += text.getGlobalBounds().height * 2 + 10;
//        posThreads.emplace_back(setPosition, std::ref(text));
    }

    // set position of keycap -> centered horizontally, and on the bottom of the screen
    backButton.setPosition((window.getSize().x - backButton.getSprite().getGlobalBounds().width) / 2,
                            window.getSize().y - backButton.getSprite().getGlobalBounds().height / 2 - 100);

//    for (auto &thread : posThreads) {
//        thread.join();
//    }
}
