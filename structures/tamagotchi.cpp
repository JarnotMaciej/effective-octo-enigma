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

