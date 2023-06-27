#include "tamagotchi.h"

tamagotchi::tamagotchi() {
    name = "Tamagotchi";
    health = 90;
    hunger = 50;
    happiness = 50;
    hygiene = 50;
    energy = 100;
    money = 20;
    bornTime = getTime();

    isSleeping = false;
    sleepStart = 0;
}

tamagotchi::tamagotchi(std::string _name) {
    name = _name;
    health = 90;
    hunger = 50;
    happiness = 50;
    hygiene = 50;
    energy = 100;
    money = 20;
    bornTime = getTime();

    isSleeping = false;
    sleepStart = 0;
}

void tamagotchi::printInfo() {
    std::cout << "Hunger:\t\t" << hunger << "/100%" << std::endl;
    std::cout << "Happiness:\t" << happiness << "/100%" << std::endl;
    std::cout << "Hygiene:\t" << hygiene << "/100%" << std::endl;
    std::cout << "Energy:\t\t" << energy << "/100%" << std::endl;
    std::cout << "Money:\t\t" << money << " gold coins" << std::endl;
    std::cout << "Foods: " << std::endl;
    for (const auto &food: foods) {
        std::cout << "\t" << food.first.getName() << " - " << food.second << std::endl;
    }
}

void tamagotchi::setMoney(int money) {
    tamagotchi::money = money;
}

void tamagotchi::setEnergy(int energy) {
    tamagotchi::energy = energy;
}

void tamagotchi::setHygiene(int hygiene) {
    tamagotchi::hygiene = hygiene;
}

void tamagotchi::setHappiness(int happiness) {
    tamagotchi::happiness = happiness;
}

void tamagotchi::setHunger(int hunger) {
    tamagotchi::hunger = hunger;
}

void tamagotchi::setHealth(int health) {
    tamagotchi::health = health;
}

void tamagotchi::setName(std::string name) {
    tamagotchi::name = name;
}

int tamagotchi::getMoney() {
    return money;
}

int tamagotchi::getEnergy() {
    return energy;
}

int tamagotchi::getHygiene() {
    return hygiene;
}

int tamagotchi::getHappiness() {
    return happiness;
}

int tamagotchi::getHunger() {
    return hunger;
}

int tamagotchi::getHealth() {
    return health;
}

std::string tamagotchi::getName() const {
    return name;
}

long long int tamagotchi::getBornTime() const {
    return bornTime;
}

bool tamagotchi::getIsSleeping() const {
    return isSleeping;
}

void tamagotchi::setIsSleeping(bool isSleeping) {
    tamagotchi::isSleeping = isSleeping;
}

long long int tamagotchi::getSleepStart() const {
    return sleepStart;
}

void tamagotchi::setSleepStart(long long int sleepStart) {
    tamagotchi::sleepStart = sleepStart;
}

std::map<food, int> tamagotchi::getFoods() const {
    return foods;
}

void tamagotchi::setFoods(std::map<food, int> _foods) {
    foods = _foods;
}

tamagotchi::tamagotchiType tamagotchi::getTamagotchiType() {
    return tamagotchi::tamagotchiType::CAT;
}

void tamagotchi::setBornTime(long long int bornTime) {
    tamagotchi::bornTime = bornTime;
}


void tamagotchi::addFood(const std::string &foodName, int quantity) {

    auto foodIterator = std::find_if(foods.begin(), foods.end(), [&](const std::pair<food, int> &pair) {
        return pair.first.getName() == foodName;
    });

    try {
        if (quantity < 0) {
            throw errorHandler{errorCode::OutOfRange};
        }
        if (foodName.empty()) {
            throw errorHandler{errorCode::EmptyString};
        }
    } catch (errorHandler &e) {
        std::cout << e.what() << std::endl;
        return;
    }

    try {
        if (foodIterator != foods.end()) {

            foodIterator->second += quantity;
        } else {

            throw errorHandler{errorCode::FoodDoesNotExist};
            food newFood(foodName, 0, 0, 0, 0, 0, 0);
            foods.insert(std::make_pair(newFood, quantity));
        }
    } catch (errorHandler &e) {
        std::cout << e.what() << std::endl;
    }
}

bool tamagotchi::eatFood(const std::string &foodName) {
    for (auto &food: foods) {
        if (food.first.getName() == foodName && food.second > 0) {
            tamagotchi::hunger = indicatorFunction(tamagotchi::hunger + food.first.getHunger());
            tamagotchi::happiness = indicatorFunction(tamagotchi::happiness + food.first.getHappiness());
            tamagotchi::hygiene = indicatorFunction(tamagotchi::hygiene + food.first.getHygiene());
            tamagotchi::energy = indicatorFunction(tamagotchi::energy + food.first.getEnergy());
            tamagotchi::health = indicatorFunction(tamagotchi::health + food.first.getHealth());
            food.second--;
            return true;
        }
    }
    return false;
}

bool tamagotchi::buyFood(const std::string &foodName) {
    for (auto &food: foods) {
        if (food.first.getName() == foodName && food.second < 999) {
            if (tamagotchi::money >= food.first.getPrice()) {
                tamagotchi::money -= food.first.getPrice();
                food.second++;
                return true;
            }
            break;
        }
    }
    return false;
}

bool tamagotchi::sellFood(const std::string &foodName) {

    for (auto &food: foods) {
        if (food.first.getName() == foodName && food.second > 0) {
            tamagotchi::money += food.first.getPrice() / 2;
            food.second--;
            return true;
        }
    }
    return false;
}

food tamagotchi::findFood(const std::string &foodName) const {

    for (auto &food: foods) {
        if (food.first.getName() == foodName) {
            return food.first;
        }
    }
    return food();
}

int indicatorFunction(int value) {

    if (value < 0) {
        return 0;
    } else if (value > 100) {
        return 100;
    } else {
        return value;
    }
}
