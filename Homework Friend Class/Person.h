#pragma once
#include <iostream>

class Person
{
protected:
	std::string name;
	int age;
	std::string gender;
public:
	Person(std::string nameP, int ageP, std::string genderP) : name{ nameP }, age{ ageP }, gender {genderP} {}

	//friend std::ostream& operator << (std::ostream& cout, Student& p);
};

