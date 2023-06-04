//
// Created by menox on 27.04.2023.
//

#include "tamagotchiMechanics.h"

int tamagotchiMechanics::transformSecondsToDays(long long int bornTime) {
    return (getTime() - bornTime) / 86400;
}

void tamagotchiMechanics::saveTamagotchi(tamagotchi &pet) {
    debug("saving tamagotchi");
    namespace fs = std::filesystem;

    // getting a path
    fs::path path = fs::current_path().parent_path();
    path /= "saves";

    //getting tamagotchi name
    std::string name = pet.getName();

    // creating a file with a name of tamagotchi
    std::ofstream tamagotchiFile;
    path /= name + ".tmg"; // tamagotchi file extension
    tamagotchiFile.open(path);

    // writing data to a file
    tamagotchiFile << name << std::endl;
    tamagotchiFile << static_cast<int>(pet.getTamagotchiType()) << std::endl;
    tamagotchiFile << pet.getBornTime() << std::endl;
    tamagotchiFile << getTime() << std::endl;
    tamagotchiFile << pet.getHealth() << std::endl;
    tamagotchiFile << pet.getHunger() << std::endl;
    tamagotchiFile << pet.getHappiness() << std::endl;
    tamagotchiFile << pet.getHygiene() << std::endl;
    tamagotchiFile << pet.getEnergy() << std::endl;
    tamagotchiFile << pet.getMoney() << std::endl;
}

int tamagotchiMechanics::realDaysToGameDays(long long int bornTime) {
    return (getTime() - bornTime) / 86400 * 4;
}

std::string tamagotchiMechanics::searchForTamagotchi() {
    debug("searching for tamagotchi");
    namespace fs = std::filesystem;

    // getting a path
    fs::path path = fs::current_path().parent_path();
    path /= "saves";
    debug(path.string());

    // checking if there is any folder in a directory
    if (fs::is_empty(path)) {
        debug("there is no tamagotchi in saves directory");
        return "";
    } else {
        std::vector<std::string> tamagotchiNames;
        for (const auto &entry: fs::directory_iterator(path)) {
            debug(entry.path().filename().string());
            tamagotchiNames.push_back(entry.path().filename().string());
            // entering directory and checking if the name of tamagotchi is the same as the name of directory
            fs::path tamagotchiPath = path;
            tamagotchiPath /= entry.path().filename().string();
            if (entry.path().filename().string() == entry.path().filename().string()) {
                debug("tamagotchi found");
                // return file name without extension
                return entry.path().filename().string().substr(0, entry.path().filename().string().length() - 4);
            }
        }
    }
    debug("something went wrong");
    return "";
}

void tamagotchiMechanics::subtractIndicators(tamagotchi &pet, long long int &lastSaved) {
    debug("subtracting indicators");
    long long int timeDifference = getTime() - lastSaved;

    float minutes = timeDifference / 60;

    float hunger = pet.getHunger() - minutes * 0.5;
    debug("hunger: " + std::to_string(hunger));
    if (hunger < 0) {
        hunger = 0;
    }
    pet.setHunger(hunger);

    float happiness = pet.getHappiness() - minutes * 0.2;
    debug("happiness: " + std::to_string(happiness));
    if (happiness < 0) {
        happiness = 0;
    }
    pet.setHappiness(happiness);

    float hygiene = pet.getHygiene() - minutes * 0.3;
    debug("hygiene: " + std::to_string(hygiene));
    if (hygiene < 0) {
        hygiene = 0;
    }
    pet.setHygiene(hygiene);

    float energy = pet.getEnergy() - minutes * 0.4;
    debug("energy: " + std::to_string(energy));
    if (energy < 0) {
        energy = 0;
    }
    pet.setEnergy(energy);

    // if pet was hungry, it's health will be decreased
    if (hunger == 0) {
        float health = pet.getHealth() - minutes * 0.1;
        debug("health: " + std::to_string(health));
        if (health < 0) {
            health = 0;
        }
        pet.setHealth(health);
    }
}

std::vector<score> tamagotchiMechanics::getScores() {
    std::vector<score> scores;

    debug("getting scores");
    namespace fs = std::filesystem;

    fs::path path = fs::current_path().parent_path();
    path /= "scores";

    //Iterating through all files in directory
    for (const auto &entry: fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry)) {
            const std::string filename = entry.path().filename().string();
            debug(filename);
            if (deadTamagotchiValidation(filename)) {
                std::ifstream scoreFile;
                scoreFile.open(entry.path());
                std::string name;
                int score, daysAlive;
                scoreFile >> name;
                scoreFile >> score;
                scoreFile >> daysAlive;
                scoreFile.close();
                class score s(name, score, daysAlive);
                scores.push_back(s);
            }
        }
    }

    debug("leaving getScores() function");
    return scores;
}

void tamagotchiMechanics::printScores(std::vector<score> scores) {
    std::cout << "Scores: " << std::endl;
    for (auto &myScore: scores) {
        std::cout << "Name: " << myScore.getTamagotchiName() << std::endl;
        std::cout << "Score: " << myScore.getScoreNumber() << std::endl;
        std::cout << "Age: " << myScore.getDaysAlive() << std::endl;
        std::cout << "---" << std::endl;
    }
}

void tamagotchiMechanics::sleepMechanics(tamagotchi &pet) {
    if (pet.getEnergy() == 100) {
        pet.setIsSleeping(false);
        pet.setSleepStart(0);
        return;
    }

    if (pet.getSleepStart() != 0) {
        long long int sleepTime = getTime() - pet.getSleepStart();
        // half an hour - energy will be full
        sleepTime /= 18; // 18 seconds -> +1 energy point

        if (sleepTime != 0) {
            pet.setSleepStart(pet.getSleepStart() + sleepTime * 18);
            int energy = pet.getEnergy() + sleepTime;
            if (energy > 100) {
                energy = 100;
            }
            pet.setEnergy(energy);
        }
    }

}

// TODO -> testing tamagotchiMechanics
