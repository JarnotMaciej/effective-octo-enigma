//
// Created by menox on 27.04.2023.
//

#include "tamagotchiMechanics.h"

int tamagotchiMechanics::transformSecondsToDays(long long int bornTime)
{
	return (getTime() - bornTime) / 86400;
}

void tamagotchiMechanics::saveTamagotchi(tamagotchi& pet)
{
	debug("saving tamagotchi");
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
int tamagotchiMechanics::realDaysToGameDays(long long int bornTime)
{
	return (getTime() - bornTime) / 21600;
}

bool tamagotchiMechanics::searchForTamagotchi()
{
	debug("searching for tamagotchi");
	namespace fs = std::filesystem;

	// getting a path
	fs::path path = fs::current_path().parent_path();
	path /= "saves";
	debug(path.string());

	// checking if there is any folder in a directory
	if (fs::is_empty(path))
	{
		debug("there is no tamagotchi in saves directory");
		return false;
	} else {
		std::vector<std::string> tamagotchiNames;
		for (const auto& entry : fs::directory_iterator(path))
		{
			debug(entry.path().filename().string());
			tamagotchiNames.push_back(entry.path().filename().string());
			// entering directory and checking if the name of tamagotchi is the same as the name of directory
			fs::path tamagotchiPath = path;
			tamagotchiPath /= entry.path().filename().string();
			if (entry.path().filename().string() == entry.path().filename().string())
			{
				debug("tamagotchi found");
				return true;
			} else {
				debug("something went wrong"); // TODO -> better comment
				return false;
			}
		}
	}
}
//std::vector<score> tamagotchiMechanics::getScores()
//{
//	std::vector<score> scores;
//
//	debug("getting scores");
//	namespace fs = std::filesystem;
//
//	fs::path path = fs::current_path().parent_path();
//	path /= "scores";
//
//	// searching for dtf file using regex
//	for(const auto& entry : fs::directory_iterator(path))
//	{
//		//TODO -> not done yet
//	}
//
//	return scores;
//}
// TODO -> if there is more than one tamagotchi in saves directory, return false
