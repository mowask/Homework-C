#pragma once
#include <iostream>
#include "Animal.h"


class Dog : public Animal
{
	std::string breed;
	int age;
public:
	Dog(std::string nameP, std::string breedP, int ageP) : Animal(nameP), breed{ breedP }, age{ ageP } {}

	friend std::ostream& operator << (std::ostream& cout, Dog& d);

};

