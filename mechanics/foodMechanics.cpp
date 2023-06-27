#include "foodMechanics.h"

void foodMechanics::printFoods(const std::map<food, int> &foods) {
    for (auto food: foods) {
        std::cout << "Name: " << food.first.getName() << std::endl;
        std::cout << "Price: " << food.first.getPrice() << std::endl;
        std::cout << "Health: " << food.first.getHealth() << std::endl;
        std::cout << "Hunger: " << food.first.getHunger() << std::endl;
        std::cout << "Happiness: " << food.first.getHappiness() << std::endl;
        std::cout << "Hygiene: " << food.first.getHygiene() << std::endl;
        std::cout << "Energy: " << food.first.getEnergy() << std::endl;
        std::cout << "---" << std::endl;
    }
}

std::map<food, int> foodMechanics::loadGlobalFoods() {
    debug("loading global foods");
    namespace fs = std::filesystem;

    fs::path path = fs::current_path().parent_path();
    path /= "config";

    std::ifstream foodFile;
    path /= "food.tconf";
    foodFile.open(path);

    try {
        if (!foodFile.is_open()) {
            throw errorHandler(errorCode::FileError);
        }
    } catch (errorHandler &e) {
        return {};
    }

    std::map<food, int> foods;
    std::string name;
    int price, health, hunger, happiness, hygiene, energy;
    std::string texture;

    std::string line;

    while (std::getline(foodFile, line)) {
        try {
            if (!foodConfigValidation(line)) {
                throw errorHandler(errorCode::ValidationError);
            }
        } catch (errorHandler &e) {
            continue;
        }

        std::istringstream iss(line);

        try {
            if (!(iss >> name >> price >> health >> hunger >> happiness >> hygiene >> energy)) {
                throw errorHandler(errorCode::FileError);
            }
        } catch (errorHandler &e) {
            continue;
        }

        foods.emplace(food(name, price, health, hunger, happiness, hygiene, energy), 0);
    }
    foodFile.close();
    return foods;
}

void foodMechanics::saveFood(tamagotchi &pet, bool saved) {
    debug("saving foods");
    namespace fs = std::filesystem;

    fs::path path = fs::current_path().parent_path();
    path /= "saves";

    std::string name = pet.getName();

    std::ofstream foodFile;
    path /= name + ".tmgfood";
    foodFile.open(path);

    try {
        if (!foodFile.is_open()) {
            throw errorHandler(errorCode::FileError);
        }
    } catch (errorHandler &e) {
        return;
    }

    for (const auto &food: pet.getFoods()) {
        foodFile << food.first.getName() << " " << food.second << std::endl;
    }
    foodFile.close();
    saved = true;
}

void foodMechanics::loadTamagotchiFoods(const std::string &fileName, tamagotchi &pet) {
    namespace fs = std::filesystem;
    fs::path path = fs::current_path().parent_path();
    path /= "saves";
    path /= fileName + ".tmgfood";
    std::list<std::pair<std::string, int>> foodsList;

    std::ifstream foodFile;
    foodFile.open(path);

    try {
        if (!foodFile.is_open()) {
            throw errorHandler(errorCode::FileError);
        }
    } catch (errorHandler &e) {
        return;
    }

    std::string name;
    int amount;

    std::string line;
    while (std::getline(foodFile, line)) {
        try {
            if (!foodSaveValidation(line)) {
                throw errorHandler(errorCode::ValidationError);
            }
        } catch (errorHandler &e) {
            continue;
        }
        try {
            std::istringstream iss(line);
            if (!(iss >> name >> amount)) {
                throw errorHandler(errorCode());
            }
        } catch (errorHandler &e) {
            continue;
        }

        foodsList.emplace_back(name, amount);
    }
    foodFile.close();

    for (const auto &food: foodsList) {
        pet.addFood(food.first, food.second);
    }
}
