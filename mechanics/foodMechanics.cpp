//
// Created by menox on 30.04.2023.
//

#include "foodMechanics.h"

std::map<std::string, food> loadGlobalFoods() {
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
        foodFile >> texture; // TODO -> texture need to be implemented in food class
        foods.emplace(name, food(name, price, health, hunger, happiness, hygiene, energy));
    }
    foodFile.close();

    return foods;
}
