//
// Created by menox on 08.04.2023.
//

// C++
#include <iostream>
#include <string>
#include <regex>
#include <chrono>
#include <filesystem>

// SFML
#include "SFML/Graphics/RenderWindow.hpp"

#ifndef PROJECT_NAME_FUNCTIONS_H
#define PROJECT_NAME_FUNCTIONS_H

/**
 * @brief Method used for debugging
 * @param text - text to be displayed
 */
void debug(const std::string &text);

/**
 * @brief Method used for validating name
 * @param name - name to be validated
 */
bool nameValidation(const std::string &name);

/**
 * @brief Method used for validating dead tamagotchi file (.dtf)
 * @param name - filename to be validated
 */
bool deadTamagotchiValidation(const std::string &name);

/**
 * @brief Method used for getting time
 * @return time in seconds
 */
long long int getTime();

/**
 * @brief Function used for setting icon
 * @param window
 */
void setIcon(sf::RenderWindow &window);

/**
 * @brief Function used for setting cursor
 * @param window
 */
void setCursor(sf::RenderWindow &window);

#endif //PROJECT_NAME_FUNCTIONS_H
