//
// Created by menox on 27.04.2023.
//

// C++
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

// headers
#include "../functions.h"
#include "../structures/tamagotchi.h"
#include "../structures/score.h"

#ifndef PROJECT_NAME_MECHANICS_TAMAGOTCHIMECHANICS_H_
#define PROJECT_NAME_MECHANICS_TAMAGOTCHIMECHANICS_H_

/**
 * @brief Tamagotchi mechanics namespace
 */
namespace tamagotchiMechanics {
    // Mechanics
    /**
     * @brief Method used for searching for tamagotchi in saves directory
     * @return true if tamagotchi was found, false if not
     */
    bool searchForTamagotchi();

    /**
     * @brief Method used for saving tamagotchi
     * @param pet - tamagotchi object
     */
    void saveTamagotchi(tamagotchi &pet);

//	tamagotchi loadTamagotchi(const std::string &name); // TODO -> make it real
    /**
     * @brief Method used for transforming seconds to days
     * @param bornTime
     * @return days
     */
    int transformSecondsToDays(long long int bornTime);

    /**
     * @brief Method used for transforming real days to game days
     * @param bornTime
     * @return game days
     */
    int realDaysToGameDays(long long int bornTime); // Transform real days to game days, 1 real day = 4 game days

    /**
     * @brief Method used for subtracting tamagotchi indicators (health, hunger, happiness, hygiene, energy) after loading tamagotchi from file
     * @param pet - tamagotchi object
     * @param lastSaved - last saved time
     */
    void subtractIndicators(tamagotchi &pet,
                            long long int &lastSaved); // Subtracts tamagotchi indicators (health, hunger, happiness, hygiene, energy) after loading tamagotchi from file

    // TODO -> make it real
    //    void killTamagotchi(tamagotchi &pet); // Transforms tamagotchi to dead tamagotchi (function calculates score)

    /**
     * @brief Method used for getting scores from file
     * @return vector of scores
     */
    std::vector<score> getScores(); // Get scores from file

    /**
     * @brief Method used for printing scores
     * @param scores - vector of scores
     */
    void printScores(std::vector<score> scores);
}

#endif //PROJECT_NAME_MECHANICS_TAMAGOTCHIMECHANICS_H_
