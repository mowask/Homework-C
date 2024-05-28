#pragma once
#include <iostream>
#include "Animal.h"

class Parrot : public Animal
{
	bool alive;
public:
	Parrot(std::string nameP,bool aliveP) : Animal(nameP), alive{ aliveP } {}

	friend std::ostream& operator << (std::ostream& cout, Parrot& p);

	bool getAlive() {
		return alive;
	}

};

