#pragma once
#include <iostream>
#include <vector>
#include "Person.h"

class Student : public Person
{
protected:
	std::vector <int> marks;
public:
	Student(std::string nameP, int ageP, std::string genderP, std::vector <int> marksP) : Person (nameP, ageP, genderP), marks {marksP} {}
	//Student() : Person("", 0, 0)  {}

	//friend std::ostream& operator << (std::ostream& cout, Student& s);

	std::string getName() {
		return name;
	}

	int addMark() {

	}

	void calcAveregeMark() {
	
	}

};

