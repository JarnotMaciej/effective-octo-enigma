//
// Created by menox on 19.03.2023.
//

#include "tamagotchi.h"

tamagotchi::equipment::equipment()
{
	food apple("Apple", 3, 5, 10, 0, -2, -5);
	food pizza("Pizza", 10, -5, 35, 5, -10, -15);
	food hamburger("Hamburger", 12, -5, 40, 10, -15, -15);
	food falafel("Falafel", 8, 0, 25, 5, -5, -10);

	addFood(apple);
	addFood(pizza);
	addFood(hamburger);
	addFood(falafel);
    // TODO -> remove upper thing, and add loading from file
}

void tamagotchi::equipment::addFood(const food& food)
{
	foods.push_back(food);
}

void tamagotchi::equipment::removeFood(food food)
{
	for (int i = 0; i < foods.size(); i++)
	{
		if (foods[i].getName() == food.getName())
		{
			foods.erase(foods.begin() + i);
		}
	}
}

void tamagotchi::equipment::printFoods()
{
	for (int i = 0; i < foods.size(); i++)
	{
		std::cout << foods[i].getName() << std::endl;
	}

}

unsigned long long int tamagotchi::equipment::foodSize()
{
	return foods.size();
}

std::vector<food> tamagotchi::equipment::getFoods() {
    return foods;
}

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
	defaultEquipment = equipment();
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
	defaultEquipment = equipment();
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
	std::cout << "Items in equipment:\t\t" << defaultEquipment.foodSize() << std::endl;
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

std::string tamagotchi::getName()
{
	return name;
}

void tamagotchi::printEquipment()
{
	defaultEquipment.printFoods();
}

long long int tamagotchi::getBornTime() const
{
	return bornTime;
}

