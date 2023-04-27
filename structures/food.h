//
// Created by menox on 19.03.2023.
//

#ifndef TAMAGOTCHI_FOOD_H
#define TAMAGOTCHI_FOOD_H

#include <string>

/**
 * Food class
 */
class food {
    private:
        std::string name; // Food name
        int price; // Food price
        int health; // Food health
        int hunger; // Food hunger
        int happiness; // Food happiness
        int hygiene; // Food hygiene
        int energy; // Food energy
    public:
        food(); // Constructor
        food(std::string name, int price, int health, int hunger, int happiness, int hygiene, int energy);
        // Getters
        std::string getName(); // Get food name
        int getPrice(); // Get food price
        int getHealth(); // Get food health
        int getHunger(); // Get food hunger
        int getHappiness(); // Get food happiness
        int getHygiene(); // Get food hygiene
        int getEnergy(); // Get food energy
        // Setters
        void setName(std::string name); // Set food name
        void setPrice(int price); // Set food price
        void setHealth(int health); // Set food health
        void setHunger(int hunger); // Set food hunger
        void setHappiness(int happiness); // Set food happiness
        void setHygiene(int hygiene); // Set food hygiene
        void setEnergy(int energy); // Set food energy
};


#endif //TAMAGOTCHI_FOOD_H
