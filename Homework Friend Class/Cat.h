#pragma once
#include <iostream>
#include "Animal.h"

class Cat : public Animal
{
private:
	std::string color;
public:
	Cat(std::string nameP, std::string colorP) : Animal(nameP), color{ colorP } {}

	friend std::ostream& operator << (std::ostream& cout, Cat& c);
};