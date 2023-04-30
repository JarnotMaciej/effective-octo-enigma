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

namespace tamagotchiMechanics
{
	bool searchForTamagotchi(); // Search for tamagotchi in saves directory
	void saveTamagotchi(tamagotchi &pet); // Save tamagotchi to file
//	tamagotchi loadTamagotchi(const std::string &name); // TODO -> Load tamagotchi from file
	int transformSecondsToDays(long long int bornTime); // Transform seconds to days, used for age calculation
	int realDaysToGameDays(long long int bornTime); // Transform real days to game days, 1 real day = 4 game days
//	void subtractIndicators(tamagotchi &pet, long long int &lastSaved); // Subtracts tamagotchi indicators (health, hunger, happiness, hygiene, energy) after loading tamagotchi from file
	//	void killTamagotchi(tamagotchi &pet); // Transforms tamagotchi to dead tamagotchi (function calculates score)
//	std::vector<score> getScores(); // Get scores from file
}

#endif //PROJECT_NAME_MECHANICS_TAMAGOTCHIMECHANICS_H_
