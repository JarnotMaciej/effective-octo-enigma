#ifndef TAMAGOTCHI_FOOD_H
#define TAMAGOTCHI_FOOD_H

#include <string>

/**
 * @brief Food class
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
    /**
     * @brief Food constructor
     */
    food();

    /**
     * @brief Food constructor
     * @param name Food name
     * @param price Food price
     * @param health Food health
     * @param hunger Food hunger
     * @param happiness Food happiness
     * @param hygiene Food hygiene
     * @param energy Food energy
     */
    food(std::string name, int price, int health, int hunger, int happiness, int hygiene, int energy);

    // Getters
    /**
     * @brief Get food name
     * @return Food name
     */
    std::string getName() const;

    /**
     * @brief Get food price
     * @return Food price
     */
    int getPrice() const;

    /**
     * @brief Get food health
     * @return Food health
     */
    int getHealth() const;

    /**
     * @brief Get food hunger
     * @return Food hunger
     */
    int getHunger() const;

    /**
     * @brief Get food happiness
     * @return Food happiness
     */
    int getHappiness() const;

    /**
     * @brief Get food hygiene
     * @return Food hygiene
     */
    int getHygiene() const;

    /**
     * @brief Get food energy
     * @return Food energy
     */
    int getEnergy() const;

    // Setters
    /**
     * @brief Set food name
     * @param name Food name
     */
    void setName(std::string name);

    /**
     * @brief Set food price
     * @param price Food price
     */
    void setPrice(int price);

    /**
     * @brief Set food health
     * @param health Food health
     */
    void setHealth(int health);

    /**
     * @brief Set food hunger
     * @param hunger Food hunger
     */
    void setHunger(int hunger);

    /**
     * @brief Set food happiness
     * @param happiness Food happiness
     */
    void setHappiness(int happiness);

    /**
     * @brief Set food hygiene
     * @param hygiene Food hygiene
     */
    void setHygiene(int hygiene);

    /**
     * @brief Set food energy
     * @param energy Food energy
     */
    void setEnergy(int energy);

    /**
     * @brief Operator <
     * @param other Other food
     * @return True if this food is less than other food
     */
    bool operator<(const food &other) const {
        return name < other.name;
    }

    /**
     * @brief Operator ==
     * @param other Other food
     * @return True if this food is equal to other food
     */
    bool operator==(const food &other) const {
        return name == other.name;
    }
};


#endif //TAMAGOTCHI_FOOD_H
