#ifndef TAMAGOTCHI_FOODBUTTON_H
#define TAMAGOTCHI_FOODBUTTON_H

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "../../../mechanics/assetManager.h"

/**
 * @brief Class for food button
 */
class foodButton {
private:
    std::string buttonName; // name of button
    sf::Texture backgroundTexture; // texture of background
    sf::Sprite backgroundSprite; // sprite of background
    sf::Texture foodTexture; // texture of food
    sf::Sprite foodSprite; // sprite of food
    short int quantity; // quantity of food
    sf::Text quantityText; // text of quantity
    bool active; // is button active

public:

    /**
     * @brief Default constructor
     */
    foodButton() = default;

    /**
     * @brief Constructor
     * @param foodName name of food
     */
    explicit foodButton(const std::string &foodName);

    /**
     * @brief Constructor
     * @param foodName name of food
     * @param quantity quantity of food
     */
    foodButton(const std::string &foodName, const int &quantity);

    /**
     * @brief Draws the button
     * @param window window to draw the button
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Sets the position of the button
     * @param x x coordinate
     * @param y y coordinate
     */
    void setPosition(float x, float y);

    /**
     * @brief Gets the quantity of food
     * @return quantity of food
     */
    short getQuantity() const;

    /**
     * @brief Sets the quantity of food, also updates the quantity text
     * @param quantity quantity of food
     */
    void setQuantity(short quantity);

    /**
     * @brief Gets if the button is active
     * @return true if button is active, false otherwise
     */
    bool isActive() const;

    /**
     * @brief Sets if the button is active
     * @param active true if button is active, false otherwise
     */
    void setActive(bool active);

    /**
     * @brief Gets the sprite of the button
     * @return sprite of the button
     */
    sf::Sprite getSprite();

    /**
     * @brief Gets the name of the button
     * @return name of the button
     */
    std::string getName();

};


#endif //TAMAGOTCHI_FOODBUTTON_H
