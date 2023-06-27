#include "tamagotchiMechanics.h"

int tamagotchiMechanics::transformSecondsToDays(long long int bornTime) {
    return (getTime() - bornTime) / 86400;
}

void tamagotchiMechanics::saveTamagotchi(tamagotchi &pet, bool &isSaved) {
    namespace fs = std::filesystem;

    fs::path path = fs::current_path().parent_path();
    path /= "saves";
    std::string name = pet.getName();
    std::ofstream tamagotchiFile;
    path /= name + ".tmg";

    try {
        tamagotchiFile.open(path);
        if (!tamagotchiFile.is_open()) {
            throw errorHandler(errorCode::FileError);
        }
        tamagotchiFile << static_cast<int>(pet.getTamagotchiType()) << std::endl;
        tamagotchiFile << name << std::endl;

        tamagotchiFile << pet.getHealth() << std::endl;
        tamagotchiFile << pet.getHunger() << std::endl;
        tamagotchiFile << pet.getHappiness() << std::endl;
        tamagotchiFile << pet.getHygiene() << std::endl;
        tamagotchiFile << pet.getEnergy() << std::endl;
        tamagotchiFile << pet.getMoney() << std::endl;
        tamagotchiFile << pet.getIsSleeping() << std::endl;
        tamagotchiFile << pet.getBornTime() << std::endl;
        tamagotchiFile << pet.getSleepStart() << std::endl;
        tamagotchiFile << getTime() << std::endl;

        tamagotchiFile.close();

    } catch (errorHandler &e) {
        isSaved = false;
        return;
    }

    isSaved = true;
}

int tamagotchiMechanics::realDaysToGameDays(long long int bornTime) {
    return (getTime() - bornTime) / 86400 * 4;
}

std::string tamagotchiMechanics::searchForTamagotchi() {
    namespace fs = std::filesystem;

    fs::path path = fs::current_path().parent_path();
    path /= "saves";

    try {
        if (fs::is_empty(path)) {
            throw errorHandler(errorCode::FileError);
        } else {
            std::vector<std::string> tamagotchiNames;
            for (const auto &entry: fs::directory_iterator(path)) {
                tamagotchiNames.push_back(entry.path().filename().string());

                fs::path tamagotchiPath = path;
                tamagotchiPath /= entry.path().filename().string();
                if (entry.path().filename().string() == entry.path().filename().string() && nameValidation(
                        entry.path().filename().string().substr(0, entry.path().filename().string().length() - 4))) {

                    return entry.path().filename().string().substr(0, entry.path().filename().string().length() - 4);
                }
            }
        }
        throw errorHandler(errorCode::FileError);
    } catch (errorHandler &e) {
        return "";
    }
}

std::vector<score> tamagotchiMechanics::getScores() {
    std::vector<score> scores;
    namespace fs = std::filesystem;

    fs::path path = fs::current_path().parent_path();
    path /= "scores";

    for (const auto &entry: fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry)) {
            const std::string filename = entry.path().filename().string();
            if (deadTamagotchiValidation(filename)) {
                std::ifstream scoreFile;
                scoreFile.open(entry.path());

                std::string line;
                while (std::getline(scoreFile, line)) {
                    try {

                        if (!scoreLineValidation(line)) {

                            throw errorHandler(errorCode::ValidationError);
                        }
                        std::istringstream iss(line);
                        std::string name;
                        int score, daysAlive;
                        if (!(iss >> name >> score >> daysAlive)) {

                            throw errorHandler(errorCode::ValidationError);
                        }

                        scores.emplace_back(name, score, daysAlive);
                    } catch (errorHandler &e) {
                        continue;
                    }
                }

                scoreFile.close();
            }
        }
    }
    return scores;
}

void tamagotchiMechanics::sleepMechanics(tamagotchi &pet) {
    if (pet.getEnergy() == 100) {
        pet.setIsSleeping(false);
        pet.setSleepStart(0);
        return;
    }

    if (pet.getSleepStart() != 0) {
        long long int sleepTime = getTime() - pet.getSleepStart();

        sleepTime /= 18;

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

tamagotchi tamagotchiMechanics::loadTamagotchi(const std::string &name) {

    namespace fs = std::filesystem;
    fs::path path = fs::current_path().parent_path();
    path /= "saves";
    path /= name + ".tmg";
    tamagotchi toReturn;

    std::ifstream tamagotchiFile;
    try {
        tamagotchiFile.open(path);

        if (!tamagotchiFile.is_open()) {
            throw errorHandler(errorCode::FileError);
        }

        std::stringstream buffer;
        buffer << tamagotchiFile.rdbuf();
        tamagotchiFile.close();

        std::string fileContent = buffer.str();

        if (!tamagotchiSaveValidation(fileContent)) {
            throw errorHandler(errorCode::ValidationError);
        }

        std::stringstream fileStream(fileContent);

        int petType;
        std::string petName;
        int health, hunger, happiness, hygiene, energy, money;
        bool isSleeping;
        long long int bornTime, sleepStart, lastSaved;

        fileStream >> petType;

        switch (petType) {
            case 0:
                toReturn = cat();
                break;
            default:
                toReturn = cat();
                break;
        }

        fileStream >> petName;
        fileStream >> health;
        fileStream >> hunger;
        fileStream >> happiness;
        fileStream >> hygiene;
        fileStream >> energy;
        fileStream >> money;
        fileStream >> isSleeping;
        fileStream >> bornTime;
        fileStream >> sleepStart;
        fileStream >> lastSaved;


        toReturn.setName(petName);
        toReturn.setHealth(health);
        toReturn.setHunger(hunger);
        toReturn.setHappiness(happiness);
        toReturn.setHygiene(hygiene);
        toReturn.setEnergy(energy);
        toReturn.setMoney(money);
        toReturn.setIsSleeping(isSleeping);
        toReturn.setBornTime(bornTime);
        toReturn.setSleepStart(sleepStart);

        long long int timeDifference = getTime() - lastSaved;

        if (isSleeping) {
            sleepMechanics(toReturn);
        } else {
            toReturn.setSleepStart(0);
            energyDecreaseMechanics(toReturn, timeDifference);
        }

        hungerMechanics(toReturn, timeDifference);
        hygieneMechanics(toReturn, timeDifference);
        happinessMechanics(toReturn, timeDifference);
        healthMechanics(toReturn, timeDifference);

        if (toReturn.getHealth() <= 0) {
            tamagotchiMechanics::killTamagotchi(toReturn);
            return cat();
        }


        std::map<food, int> foodsToAdd = foodMechanics::loadGlobalFoods();
        if (foodsToAdd.empty()) {
            throw errorHandler(errorCode::FileError);
        }

        toReturn.setFoods(foodsToAdd);

        foodMechanics::loadTamagotchiFoods(name, toReturn);
    } catch (errorHandler &e) {
        return cat();
    }

    return toReturn;
}

void tamagotchiMechanics::energyDecreaseMechanics(tamagotchi &tamagotchiToModify, long long int difference) {
    int energy = tamagotchiToModify.getEnergy() - difference / 300;
    if (energy < 0) {
        energy = 0;
    } else if (energy > 100) {
        energy = 100;
    } else {
        tamagotchiToModify.setEnergy(energy);
    }
}

void tamagotchiMechanics::hungerMechanics(tamagotchi &tamagotchiToModify, long long int difference) {
    int hunger = tamagotchiToModify.getHunger() - difference / 600;
    if (hunger < 0) {
        hunger = 0;
    } else if (hunger > 100) {
        hunger = 100;
    } else {
        tamagotchiToModify.setHunger(hunger);
    }
}

void tamagotchiMechanics::hygieneMechanics(tamagotchi &tamagotchiToModify, long long int difference) {
    int hygiene = tamagotchiToModify.getHygiene() - difference / 450;
    if (hygiene < 0) {
        hygiene = 0;
    } else if (hygiene > 100) {
        hygiene = 100;
    } else {
        tamagotchiToModify.setHygiene(hygiene);
    }
}

void tamagotchiMechanics::happinessMechanics(tamagotchi &tamagotchiToModify, long long int difference) {
    int happiness = tamagotchiToModify.getHappiness() - difference / 180;
    if (happiness < 0) {
        happiness = 0;
    } else if (happiness > 100) {
        happiness = 100;
    } else {
        tamagotchiToModify.setHappiness(happiness);
    }
}

void tamagotchiMechanics::healthMechanics(tamagotchi &tamagotchiToModify, long long int difference) {
    int health = tamagotchiToModify.getHealth();
    float multiplier = 1.2;

    bool hungerCondition = false;
    bool hygieneCondition = false;
    bool happinessCondition = false;
    bool energyCondition = false;

    std::future<void> hungerFuture = std::async(std::launch::async, [&]() {
        hungerCondition = tamagotchiToModify.getHunger() <= 10;
    });

    std::future<void> hygieneFuture = std::async(std::launch::async, [&]() {
        hygieneCondition = tamagotchiToModify.getHygiene() <= 10;
    });

    std::future<void> happinessFuture = std::async(std::launch::async, [&]() {
        happinessCondition = tamagotchiToModify.getHappiness() <= 0;
    });

    std::future<void> energyFuture = std::async(std::launch::async, [&]() {
        energyCondition = tamagotchiToModify.getEnergy() <= 0;
    });

    hungerFuture.wait();
    hygieneFuture.wait();
    happinessFuture.wait();
    energyFuture.wait();

    if (hungerCondition) {
        multiplier *= 1.2;
    }
    if (hygieneCondition) {
        multiplier *= 2.2;
    }
    if (happinessCondition) {
        multiplier *= 1.1;
    }
    if (energyCondition) {
        multiplier *= 1.8;
    }

    int intMultiplier = static_cast<int>(multiplier);
    health -= (difference / 450) * intMultiplier;

    health = std::max(0, std::min(health, 100));
    tamagotchiToModify.setHealth(health);
}

tamagotchi tamagotchiMechanics::checkIfTamagotchiExistsThenReturn(std::string basicString) {
    if (!basicString.empty()) {
        return tamagotchiMechanics::loadTamagotchi(basicString);
    }

    tamagotchi toReturn = cat();
    toReturn.setFoods(foodMechanics::loadGlobalFoods());
    toReturn.printInfo();
    return toReturn;
}

void tamagotchiMechanics::killTamagotchi(tamagotchi &pet) {
    std::string name = pet.getName();
    int daysAlive = tamagotchiMechanics::realDaysToGameDays(pet.getBornTime());
    int scoreNumber = tamagotchiMechanics::calculateScore(pet);

    std::filesystem::path tamagotchiPath = std::filesystem::current_path().parent_path() / "saves" / (name + ".tmg");
    std::filesystem::path foodPath = std::filesystem::current_path().parent_path() / "saves" / (name + ".tmgfood");
    std::filesystem::path scorePath = std::filesystem::current_path().parent_path() / "scores" / (name + ".dtf");

    try {

        if (std::filesystem::exists(scorePath)) {
            std::ifstream scoreFile(scorePath);

            if (!scoreFile.is_open()) {
                throw errorHandler(errorCode::FileError);
            }

            std::string scoreName;
            int scoreScore;
            int scoreDaysAlive;

            scoreFile >> scoreName >> scoreScore >> scoreDaysAlive;

            scoreFile.close();

            if (scoreNumber > scoreScore) {
                std::ofstream scoreFile(scorePath);

                if (!scoreFile.is_open()) {
                    throw errorHandler(errorCode::FileError);
                }

                scoreFile << name << " " << scoreNumber << " " << daysAlive;
                scoreFile.close();
            }
        } else {
            std::ofstream scoreFile(scorePath);

            if (!scoreFile.is_open()) {
                throw errorHandler(errorCode::FileError);
            }

            scoreFile << name << " " << scoreNumber << " " << daysAlive;
            scoreFile.close();
        }
    } catch (errorHandler &e) {
        return;
    }

    std::filesystem::remove(tamagotchiPath);
    std::filesystem::remove(foodPath);

    std::cout << "Your tamagotchi " << name << " died after " << daysAlive << " days of life. Your score is "
              << scoreNumber << " points." << std::endl;
}

int tamagotchiMechanics::calculateScore(tamagotchi &pet) {
    std::atomic<int> score(0);
    std::thread healthThread([&]() {
        score += pet.getHealth() * 2;
    });

    std::thread happinessThread([&]() {
        score += pet.getHappiness() * 2;
    });

    std::thread hygieneThread([&]() {
        score += pet.getHygiene() * 2;
    });

    std::thread hungerThread([&]() {
        score += pet.getHunger() * 2;
    });

    std::thread energyThread([&]() {
        score += pet.getEnergy() * 2;
    });

    std::thread daysThread([&]() {
        score += tamagotchiMechanics::realDaysToGameDays(pet.getBornTime()) * 3;
    });

    std::thread moneyThread([&]() {
        score += pet.getMoney() * 3;
    });

    healthThread.join();
    happinessThread.join();
    hygieneThread.join();
    hungerThread.join();
    energyThread.join();
    daysThread.join();
    moneyThread.join();

    return score;
}

std::vector<std::pair<std::string, int>> tamagotchiMechanics::readCreditsFile() {
    std::vector<std::pair<std::string, int>> creditsVector;

    std::filesystem::path creditsFilePath = std::filesystem::current_path().parent_path() / "config" / "credits.md";
    std::ifstream creditsFile(creditsFilePath);
    try {
        if (!creditsFile.is_open()) {
            throw errorHandler(errorCode::FileError);
        }
        std::string line;

        while (std::getline(creditsFile, line)) {
            int count = 0;
            for (char c: line) {
                if (c == '#') {
                    count++;
                } else if (c == ' ') {
                    break;
                } else {
                    count = 0;
                    break;
                }
            }

            if (count != 0) {
                line.erase(0, count + 1);
            }

            if (line.find('[') != std::string::npos) {
                std::string text = line.substr(line.find('[') + 1, line.find(']') - line.find('[') - 1);
                std::string link = line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1);
                creditsVector.emplace_back(text, -1);
                creditsVector.emplace_back(link, -2);
                continue;
            }

            if (line.find('-') != std::string::npos) {
                if (line.find('-') == line.find_last_of('-')) {
                    creditsVector.emplace_back(line.substr(line.find('-') + 1), -3);
                } else {
                    creditsVector.emplace_back("", -4);
                }
                continue;
            }

            creditsVector.emplace_back(line, count);
        }
    } catch (errorHandler &e) {
        return {};
    }
    creditsFile.close();

    return creditsVector;
}

std::vector<sf::Text> tamagotchiMechanics::createCreditsTexts(const std::vector<std::pair<std::string, int>> &credits) {
    std::vector<sf::Text> texts;
    for (const auto &credit: credits) {
        sf::Text text;
        text.setString(credit.first);
        text.setFont(assetManager::getInstance().getFont("Silkscreen"));

        switch (credit.second) {
            case -1:
                text.setCharacterSize(30);
                break;
            case -2:
                text.setCharacterSize(22);
                break;
            case -3:
                text.setCharacterSize(36);
                break;
            case -4:
                text.setCharacterSize(100);
                break;
            case 0:
                text.setCharacterSize(32);
                break;
            case 1:
                text.setCharacterSize(72);
                break;
            case 2:
                text.setCharacterSize(64);
                break;
            case 3:
                text.setCharacterSize(48);
                break;
            case 4:
                text.setCharacterSize(42);
                break;
            default:
                text.setCharacterSize(32);
                break;
        }

        text.setFillColor(sf::Color::White);
        text.setPosition(0, 0);
        texts.push_back(text);
    }
    return texts;
}
