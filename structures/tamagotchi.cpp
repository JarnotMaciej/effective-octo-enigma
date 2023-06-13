//
// Created by menox on 19.03.2023.
//

#include "tamagotchi.h"

tamagotchi::tamagotchi()
{
	name = "Tamagotchi";
	age = 0;
	health = 100;
	hunger = 100;
	happiness = 100;
	hygiene = 100;
	energy = 100;
	money = 20;
    bornTime = getTime();

    isSleeping = false;
    sleepStart = 0;
}

tamagotchi::tamagotchi(std::string _name)
{
	name = _name;
	age = 0;
	health = 100;
	hunger = 100;
	happiness = 100;
	hygiene = 100;
	energy = 100;
	money = 20;
	bornTime = getTime();

    isSleeping = false;
    sleepStart = 0;
}

void tamagotchi::printInfo()
{
	std::cout << "Name:\t\t" << name << std::endl;
	std::cout << "Age:\t\t" << age << " days" << std::endl;
	std::cout << "Health:\t\t" << health << "/100%" << std::endl;
	std::cout << "Hunger:\t\t" << hunger << "/100%" << std::endl;
	std::cout << "Happiness:\t" << happiness << "/100%" << std::endl;
	std::cout << "Hygiene:\t" << hygiene << "/100%" << std::endl;
	std::cout << "Energy:\t\t" << energy << "/100%" << std::endl;
	std::cout << "Money:\t\t" << money << " gold coins" << std::endl;
    std::cout << "Foods: " << std::endl;
    for (const auto& food : foods)
    {
        std::cout << "\t" << food.first.getName() << " - " << food.second << std::endl;
    }
}

void tamagotchi::setMoney(int money)
{
	tamagotchi::money = money;
}

void tamagotchi::setEnergy(int energy)
{
	tamagotchi::energy = energy;
}

void tamagotchi::setHygiene(int hygiene)
{
	tamagotchi::hygiene = hygiene;
}

void tamagotchi::setHappiness(int happiness)
{
	tamagotchi::happiness = happiness;
}

void tamagotchi::setHunger(int hunger)
{
	tamagotchi::hunger = hunger;
}

void tamagotchi::setHealth(int health)
{
	tamagotchi::health = health;
}

void tamagotchi::setAge(int age)
{
	tamagotchi::age = age;
}

void tamagotchi::setName(std::string name)
{
	tamagotchi::name = name;
}

int tamagotchi::getMoney()
{
	return money;
}

int tamagotchi::getEnergy()
{
	return energy;
}

int tamagotchi::getHygiene()
{
	return hygiene;
}

int tamagotchi::getHappiness()
{
	return happiness;
}

int tamagotchi::getHunger()
{
	return hunger;
}

int tamagotchi::getHealth()
{
	return health;
}

int tamagotchi::getAge()
{
	return age;
}

std::string tamagotchi::getName() const {
	return name;
}

long long int tamagotchi::getBornTime() const
{
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

//void tamagotchi::addFood(const food& _food, int quantity){
//    auto it = foods.find(_food);
//    if (it != foods.end())
//    {
//        it->second += quantity;
//    }
//    else
//    {
//        foods[_food] = quantity;
//    }
//}

void tamagotchi::setBornTime(long long int bornTime) {
    tamagotchi::bornTime = bornTime;
}


void tamagotchi::addFood(const std::string& foodName, int quantity) {
    // Check if the food already exists in the map
    auto foodIterator = std::find_if(foods.begin(), foods.end(), [&](const std::pair<food, int>& pair) {
        return pair.first.getName() == foodName;
    });

    if (foodIterator != foods.end()) {
        // Food already exists, update the quantity
        foodIterator->second += quantity;
    } else {
        // Food doesn't exist, create a new food object and add it to the map
        food newFood(foodName, 0, 0, 0, 0, 0, 0);  // You can replace the default values with the actual values
        foods.insert(std::make_pair(newFood, quantity));
    }
}

void tamagotchi::eatFood(const std::string& foodName){
    for (auto& food : foods)
    {
        if (food.first.getName() == foodName && food.second > 0)
        {
            tamagotchi::hunger = indicatorFunction(tamagotchi::hunger + food.first.getHunger());
            tamagotchi::happiness = indicatorFunction(tamagotchi::happiness + food.first.getHappiness());
            tamagotchi::hygiene = indicatorFunction(tamagotchi::hygiene + food.first.getHygiene());
            tamagotchi::energy = indicatorFunction(tamagotchi::energy + food.first.getEnergy());
            tamagotchi::health = indicatorFunction(tamagotchi::health + food.first.getHealth());
            food.second--;
            break;
        }
    }
}

void tamagotchi::buyFood(const std::string &foodName) {
    for (auto& food : foods)
    {
        if (food.first.getName() == foodName)
        {
            if (tamagotchi::money >= food.first.getPrice())
            {
                tamagotchi::money -= food.first.getPrice();
                food.second++;
            }
            break;
        }
    }
}

void tamagotchi::sellFood(const std::string &foodName) {
    // sell tamagotchi food for 50% of the price
    for (auto& food : foods)
    {
        if (food.first.getName() == foodName && food.second > 0)
        {
            tamagotchi::money += food.first.getPrice() / 2;
            food.second--;
            break;
        }
    }
}

int indicatorFunction(int value) {
    // This function is used to make sure that the value is between 0 and 100
    if (value < 0) {
        return 0;
    } else if (value > 100) {
        return 100;
    } else {
        return value;
    }
}
