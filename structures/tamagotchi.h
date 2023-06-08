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
	std::string name; // Tamagotchi name
	int age; // Tamagotchi age (in days)
	int health; // Tamagotchi health (in percent)
	int hunger; // Tamagotchi hunger (in percent)
	int happiness; // Tamagotchi happiness (in percent)
	int hygiene; // Tamagotchi hygiene (in percent)
	int energy; // Tamagotchi energy (in percent)
	int money; // Tamagotchi money (in gold coins)
	long long int bornTime; // Tamagotchi born time (in seconds)
    std::map<food, int> foods; // Tamagotchi foods -> food, quantity

    // sleepMechanics
    bool isSleeping;
    long long int sleepStart;

 public:
    /**
     * @brief Constructor
     */
	tamagotchi();

    /**
     * @brief Constructor
     * @param _name - Tamagotchi name
     */
	explicit tamagotchi(std::string _name);

    /**
     * @brief Get tamagotchi equipment
     * @return Tamagotchi equipment
     */
	std::string getName() const;

    /**
     * @brief Get tamagotchi age
     * @return Tamagotchi age
     */
	int getAge();
    /**
     * @brief Get tamagotchi health
     * @return Tamagotchi health
     */
	int getHealth();

    /**
     * @brief Get tamagotchi hunger
     * @return Tamagotchi hunger
     */
	int getHunger();

    /**
     * @brief Get tamagotchi happiness
     * @return Tamagotchi happiness
     */
	int getHappiness();

    /**
     * @brief Get tamagotchi hygiene
     * @return Tamagotchi hygiene
     */
	int getHygiene();

    /**
     * @brief Get tamagotchi energy
     * @return Tamagotchi energy
     */
	int getEnergy();

    /**
     * @brief Get tamagotchi money
     * @return Tamagotchi money
     */
	int getMoney();

    /**
     * @brief Get tamagotchi born time
     * @return Tamagotchi born time
     */
	long long int getBornTime() const;

    /**
     * @brief Set tamagotchi name
     * @param name - Tamagotchi name
     */
	void setName(std::string name);

    /**
     * @brief Set tamagotchi age
     * @param age - Tamagotchi age
     */
	void setAge(int age);

    /**
     * @brief Set tamagotchi health
     * @param health - Tamagotchi health
     */
	void setHealth(int health);

    /**
     * @brief Set tamagotchi hunger
     * @param hunger - Tamagotchi hunger
     */
	void setHunger(int hunger);

    /**
     * @brief Set tamagotchi happiness
     * @param happiness - Tamagotchi happiness
     */
	void setHappiness(int happiness);

    /**
     * @brief Set tamagotchi hygiene
     * @param hygiene - Tamagotchi hygiene
     */
	void setHygiene(int hygiene);

    /**
     * @brief Set tamagotchi energy
     * @param energy - Tamagotchi energy
     */
	void setEnergy(int energy);

    /**
     * @brief Set tamagotchi money
     * @param money - Tamagotchi money
     */
	void setMoney(int money);

    /**
     * @brief Set tamagotchi born time
     * @param bornTime - Tamagotchi born time
     */
	void setBornTime(long long int bornTime);

    /**
     * @brief Print tamagotchi info // Used for debugging, should be removed in final version
     */
	void printInfo();

    /**
     * @brief Get tamagotchi foods
     * @return Tamagotchi foods
     */
    [[nodiscard]] std::map<food, int> getFoods() const;

    /**
     * @brief Set tamagotchi foods
     * @param _foods - Tamagotchi foods
     */
    void setFoods(std::map<food, int> _foods);

    /**
     * @brief Enum class for tamagotchi types
     */
    enum class tamagotchiType
    {
        CAT,
        DOG,
        FISH
    };

    /**
     * @brief Get tamagotchi type
     * @return Tamagotchi type
     */
    virtual tamagotchiType getTamagotchiType() = 0;

    /**
     * @brief Get sleeping bool
     * @return Sleeping bool
     */
    bool getIsSleeping() const;

    /**
     * @brief Set sleeping bool
     * @param isSleeping - Sleeping bool
     */
    void setIsSleeping(bool isSleeping);

    /**
     * @brief Get sleepMechanics start time
     * @return Sleep start time
     */
    long long int getSleepStart() const;

    /**
     * @brief Set sleepMechanics start time
     * @param sleepStart - Sleep start time
     */
    void setSleepStart(long long int sleepStart);
};

#endif //TAMAGOTCHI_TAMAGOTCHI_H
