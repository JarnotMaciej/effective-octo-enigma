//
// Created by menox on 28.04.2023.
//

#ifndef PROJECT_NAME_STRUCTURES_SCORE_H_
#define PROJECT_NAME_STRUCTURES_SCORE_H_

// C++
#include <string>
#include <filesystem>

/**
 * @brief Score class
 */
class score {
private:
    std::string tamagotchiName; // tamagotchi name
    int scoreNumber; // score number
    int daysAlive; // days alive

public:
    /**
     * @brief Constructor
     * @param tamagotchiName tamagotchi name
     * @param scoreNumber score number
     * @param daysAlive days alive
     * @return score object
     */
    score(std::string tamagotchiName, int scoreNumber, int daysAlive) : tamagotchiName(std::move(tamagotchiName)),
                                                                        scoreNumber(scoreNumber),
                                                                        daysAlive(daysAlive) {};

    // Getters
    /**
     * @brief Get tamagotchi name
     * @return tamagotchi name
     */
    std::string getTamagotchiName() const;

    /**
     * @brief Get score number
     * @return score number
     */
    int getScoreNumber() const;

    /**
     * @brief Get days alive
     * @return days alive
     */
    int getDaysAlive() const;
};

#endif //PROJECT_NAME_STRUCTURES_SCORE_H_
