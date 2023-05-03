//
// Created by menox on 30.04.2023.
//

#ifndef PROJECT_NAME_FOODMECHANICS_H
#define PROJECT_NAME_FOODMECHANICS_H

// C++
#include <vector>
#include <filesystem>
#include <fstream>
#include <map>


// headers
#include "../structures/food.h"
#include "../functions.h"
#include "../structures/tamagotchi.h"


/**
 * @brief Food mechanics namespace
 */
namespace foodMechanics {
    /**
     * @brief Method used for searching for food in saves directory
     * @return map of food
     */
    std::map<std::string, food> loadGlobalFoods();

    /**
     * @brief Method used for printing foods
     */
    void printFoods(const std::map<std::string, food>& foods);

    /**
     * @brief Method used for saving foods to file
     * @param tamagotchi Tamagotchi
     */
    void saveFoods(const tamagotchi& pet);
}

#endif //PROJECT_NAME_FOODMECHANICS_H
