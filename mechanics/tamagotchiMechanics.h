//
// Created by menox on 27.04.2023.
//

// headers
#include "../functions.h"
#include "../structures/tamagotchi.h"

#ifndef PROJECT_NAME_MECHANICS_TAMAGOTCHIMECHANICS_H_
#define PROJECT_NAME_MECHANICS_TAMAGOTCHIMECHANICS_H_

namespace tamagotchiMechanics
{
	void saveTamagotchi(tamagotchi &pet); // Save tamagotchi to file
//	tamagotchi loadTamagotchi(const std::string &name); // TODO -> Load tamagotchi from file
	int transformSecondsToDays(long long int bornTime); // Transform seconds to days, used for age calculation
	void killTamagotchi(tamagotchi &pet); // Transforms tamagotchi to dead tamagotchi (function calculates score)
}

#endif //PROJECT_NAME_MECHANICS_TAMAGOTCHIMECHANICS_H_
