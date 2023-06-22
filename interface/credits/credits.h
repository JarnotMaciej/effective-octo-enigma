//
// Created by menox on 22.06.2023.
//
#include "../screen.h"
#include "../keycapButton.h"

#ifndef TAMAGOTCHI_CREDITS_H
#define TAMAGOTCHI_CREDITS_H

/**
 * @brief Credits screen
 */
class credits : public screen {
private:
    std::vector<sf::Text> texts; // vector of texts
    keycapButton backButton; // back button
    sf::Clock clock; // clock

public:
    /**
     * @brief Constructor
     * @param _texts - vector of texts
     */
    explicit credits(std::vector<sf::Text> &_texts);

    /**
     * @brief Method used for drawing screen
     * @param window - SFML window
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Method used for setting positions
     * @param window - SFML window
     */
    void handleInput(sf::RenderWindow &window, ScreenName &_screenName) override;

    /**
     * @brief Method used for updating screen
     * @param window - SFML window
     * @param pet - tamagotchi
     */
    void update(sf::RenderWindow &window, tamagotchi &pet) override;

    /**
     * @brief Method used for setting positions
     * @param window - SFML window
     */
    void setPositions(sf::RenderWindow &window) override;
};


#endif //TAMAGOTCHI_CREDITS_H
