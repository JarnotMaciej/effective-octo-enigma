//
// Created by menox on 19.03.2023.
//
// TODO -> Kill Tamagotchi after 2 days od inactivity

#ifndef TAMAGOTCHI_TAMAGOTCHI_H
#define TAMAGOTCHI_TAMAGOTCHI_H

// C++
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

// Headers
#include "food.h"
#include "../functions.h"

/**
 * Tamagotchi class
 */
class tamagotchi
{
 private:
	class equipment
	{
	 private:
		std::vector<food> foods; // Tamagotchi items
	 public:
		equipment(); // Constructor
		// Methods
		/**
		 * @brief Add food to equipment
		 *
		 * @param food - Food to add
		 */
		void addFood(const food& food);
		/**
		 * @brief Remove food from equipment
		 *
		 * @param food - Food to remove
		 */
		void removeFood(food food);
		void printFoods(); // Print foods from equipment
		unsigned long long int foodSize(); // Print foods size
		// save equipment to file
//		void saveEquipment(); //TODO -> implement equipment saving
	};

	std::string name; // Tamagotchi name
	int age; // Tamagotchi age (in days)
	int health; // Tamagotchi health (in percent)
	int hunger; // Tamagotchi hunger (in percent)
	int happiness; // Tamagotchi happiness (in percent)
	int hygiene; // Tamagotchi hygiene (in percent)
	int energy; // Tamagotchi energy (in percent)
	int money; // Tamagotchi money (in gold coins)
	long long int bornTime; // Tamagotchi born time (in seconds)
	equipment defaultEquipment; // Tamagotchi default equipment (with default foods)

 public:
	tamagotchi(); // Constructor
	tamagotchi(std::string _name); // Constructor with name
	// Getters
	std::string getName(); // Get tamagotchi name
	int getAge(); // Get tamagotchi age
	int getHealth(); // Get tamagotchi health
	int getHunger(); // Get tamagotchi hunger
	int getHappiness(); // Get tamagotchi happiness
	int getHygiene(); // Get tamagotchi hygiene
	int getEnergy(); // Get tamagotchi energy
	int getMoney(); // Get tamagotchi money
	long long int getBornTime() const; // Get tamagotchi born time
	// Setters
	void setName(std::string name); // Set tamagotchi name
	void setAge(int age); // Set tamagotchi age
	void setHealth(int health); // Set tamagotchi health
	void setHunger(int hunger); // Set tamagotchi hunger
	void setHappiness(int happiness); // Set tamagotchi happiness
	void setHygiene(int hygiene); // Set tamagotchi hygiene
	void setEnergy(int energy); // Set tamagotchi energy
	void setMoney(int money); // Set tamagotchi money
	void setBornTime(long long int bornTime); // Set tamagotchi born time
	// Methods
	void printInfo(); // Print tamagotchi info
	void printEquipment(); // Print tamagotchi equipment
};

#endif //TAMAGOTCHI_TAMAGOTCHI_H
