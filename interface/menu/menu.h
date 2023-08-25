#include <list>
#include "../screen.h"
#include "button.h"

#ifndef PROJECT_NAME_MENU_H
#define PROJECT_NAME_MENU_H

/**
 * @brief Class for menu
 */
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
     * @param _screenName - name of the screen -> to change screen
     */
    void handleInput(sf::RenderWindow &window, ScreenName &_screenName) override;

    /**
     * @brief Method used for drawing menu
     * @param window - window to draw menu on
     */
    void draw(sf::RenderWindow &window) override;

    /**
     * @brief Method used for setting positions of buttons and logo
     * @param window - window to set positions on
     */
    void setPositions(sf::RenderWindow &window) override;

    /**
     * @brief Method used for updating menu
     * @param window - window to update menu on
     * @param pet - tamagotchi object
     */
    void update(sf::RenderWindow &window, tamagotchi &pet) override;
};


#endif //PROJECT_NAME_MENU_H
