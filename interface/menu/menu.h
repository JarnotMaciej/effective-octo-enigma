//
// Created by menox on 06.05.2023.
//

// C++
#include <list>

// header files
#include "../screen.h"
#include "button.h"

#ifndef PROJECT_NAME_MENU_H
#define PROJECT_NAME_MENU_H


class menu : public screen {
private:
    sf::Text logo; // text on logo
    std::list<button> buttons; // list of buttons

public:
    /**
     * @brief Default constructor for menu
     */
    menu();

    /**
     * @brief Method used for handling input
     * @param window - window to handle input on
     */
    void handleInput(sf::RenderWindow &window) override;

    /**
     * @brief Method used for drawing menu
     * @param window - window to draw menu on
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Method used for setting positions of buttons and logo
     * @param window - window to set positions on
     */
    void setPositions(sf::RenderWindow &window);
};


#endif //PROJECT_NAME_MENU_H
