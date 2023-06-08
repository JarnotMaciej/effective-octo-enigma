//
// Created by menox on 19.03.2023.
//

#include "food.h"

food::food()
{
	name = "Food";
	price = 0;
	health = 0;
	hunger = 0;
	happiness = 0;
	hygiene = 0;
	energy = 0;
}

food::food(std::string name, int price, int health, int hunger, int happiness, int hygiene, int energy)
{
	this->name = name;
	this->price = price;
	this->health = health;
	this->hunger = hunger;
	this->happiness = happiness;
	this->hygiene = hygiene;
	this->energy = energy;
}

std::string food::getName() const {
	return name;
}

int food::getPrice()
{
	return price;
}

int food::getHealth()
{
	return health;
}

int food::getHunger()
{
	return hunger;
}

int food::getHappiness()
{
	return happiness;
}

int food::getHygiene()
{
	return hygiene;
}

int food::getEnergy()
{
	return energy;
}

void food::setName(std::string name)
{
	this->name = name;
}

void food::setPrice(int price)
{
	this->price = price;
}

void food::setHealth(int health)
{
	this->health = health;
}

void food::setHunger(int hunger)
{
	this->hunger = hunger;
}

void food::setHappiness(int happiness)
{
	this->happiness = happiness;
}

void food::setHygiene(int hygiene)
{
	this->hygiene = hygiene;
}

void food::setEnergy(int energy)
{
	this->energy = energy;
}


