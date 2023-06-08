//
// Created by menox on 30.04.2023.
//

#include "foodMechanics.h"


void foodMechanics::printFoods(const std::map<std::string, food>& foods) {
    for (auto food : foods)
    {
        std::cout << "Name: " << food.second.getName() << std::endl;
        std::cout << "Price: " << food.second.getPrice() << std::endl;
        std::cout << "Health: " << food.second.getHealth() << std::endl;
        std::cout << "Hunger: " << food.second.getHunger() << std::endl;
        std::cout << "Happiness: " << food.second.getHappiness() << std::endl;
        std::cout << "Hygiene: " << food.second.getHygiene() << std::endl;
        std::cout << "Energy: " << food.second.getEnergy() << std::endl;
        std::cout << "---" << std::endl;
    }
}

std::map<std::string, food> foodMechanics::loadGlobalFoods() {
        debug("loading global foods");
    namespace fs = std::filesystem;

    // getting a path
    fs::path path = fs::current_path().parent_path();
    path /= "config";

    // opening a file "food.tconf"
    std::ifstream foodFile;
    path /= "food.tconf";
    foodFile.open(path);

    //generating a map of foods
    std::map<std::string, food> foods;
    std::string name;
    int price, health, hunger, happiness, hygiene, energy;
    std::string texture;
    // reading from file
    while (foodFile >> name) {
        foodFile >> price;
        foodFile >> health;
        foodFile >> hunger;
        foodFile >> happiness;
        foodFile >> hygiene;
        foodFile >> energy;

        foods.emplace(name, food(name, price, health, hunger, happiness, hygiene, energy));
    }
    foodFile.close();

    return foods;
}

void foodMechanics::saveFood(tamagotchi &pet, bool saved) {
    debug("saving foods");
    namespace fs = std::filesystem;

    // getting a path
    fs::path path = fs::current_path().parent_path();
    path /= "saves";

    //getting tamagotchi name
    std::string name = pet.getName();

    // creating a file with foods
    std::ofstream foodFile;
    path /= name + ".tmgfood"; // food file extension
    foodFile.open(path);

    // writing data to a file
    for (const auto& food : pet.getFoods())
    {
        foodFile << food.first.getName() << " " << food.second << std::endl;
    }

    foodFile.close();
    saved = true;
}
