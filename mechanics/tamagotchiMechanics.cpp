//
// Created by menox on 27.04.2023.
//

#include "tamagotchiMechanics.h"

int tamagotchiMechanics::transformSecondsToDays(long long int bornTime)
{
	return (getTime() - bornTime) / 86400;
}

void tamagotchiMechanics::saveTamagotchi(tamagotchi &pet)
{
	namespace fs = std::filesystem;

	// getting a path
	fs::path path = fs::current_path().parent_path();
	path /= "saves";
	debug(path.string());

	//getting tamagotchi name
	std::string name = pet.getName();

	// creating a directory with a name of tamagotchi
	path /= name;
	fs::create_directory(path);

	// creating a file with a name of tamagotchi
	std::ofstream tamagotchiFile;
	path /= name + ".tmg"; // tamagotchi file extension
	tamagotchiFile.open(path);

	// writing data to a file
	tamagotchiFile << name << std::endl;
	tamagotchiFile << pet.getBornTime() << std::endl;
	tamagotchiFile << getTime() << std::endl;
	tamagotchiFile << pet.getHealth() << std::endl;
	tamagotchiFile << pet.getHunger() << std::endl;
	tamagotchiFile << pet.getHappiness() << std::endl;
	tamagotchiFile << pet.getHygiene() << std::endl;
	tamagotchiFile << pet.getEnergy() << std::endl;
	tamagotchiFile << pet.getMoney() << std::endl;
}
