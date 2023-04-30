//
// Created by menox on 28.04.2023.
//

#ifndef PROJECT_NAME_STRUCTURES_SCORE_H_
#define PROJECT_NAME_STRUCTURES_SCORE_H_

// C++
#include <string>
#include <filesystem>

class score
{
 private:
	std::string tamagotchiName; // tamagotchi name
	int scoreNumber; // score number
	int daysAlive; // days alive

	public:
	score(std::string tamagotchiName, int scoreNumber, int daysAlive) : tamagotchiName(std::move(tamagotchiName)), scoreNumber(scoreNumber), daysAlive(daysAlive) {};
    // Getters
    std::string getTamagotchiName() const;
    int getScoreNumber() const;
    int getDaysAlive() const;
};

#endif //PROJECT_NAME_STRUCTURES_SCORE_H_
