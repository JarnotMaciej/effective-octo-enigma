//
// Created by menox on 30.04.2023.
//

#include "foodMechanics.h"


void foodMechanics::printFoods(const std::map<food, int>& foods) {
    for (auto food : foods)
    {
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

    // getting a path
    fs::path path = fs::current_path().parent_path();
    path /= "config";

    // opening a file "food.tconf"
    std::ifstream foodFile;
    path /= "food.tconf";
    foodFile.open(path);

    //generating a map of foods
    std::map<food, int> foods;
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

        foods.emplace(food(name, price, health, hunger, happiness, hygiene, energy), 0);
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

void foodMechanics::loadTamagotchiFoods(const std::string &fileName, tamagotchi &pet) {
    // opening file using filesystem
    namespace fs = std::filesystem;
    fs::path path = fs::current_path().parent_path();
    path /= "saves";
    path /= fileName + ".tmgfood";

    std::list <std::pair<std::string, int>> foodsList;

    std::ifstream foodFile;
    foodFile.open(path);

    std::string name;
    int amount;

    while (foodFile >> name)
    {
        foodFile >> amount;
        foodsList.emplace_back(name, amount);
    }

    foodFile.close();

    // loading foods to tamagotchi
    for (const auto& food : foodsList)
    {
        pet.addFood(food.first, food.second);
    }
}
