#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Parrot.h"

std::ostream& operator << (std::ostream& cout, Dog& d) {
	cout << "dog name: " << d.name << "\ndog breed: "<< d.breed << "\ndog age: " << d.age<< "\n";
	return cout;
}

std::ostream& operator << (std::ostream& cout, Cat& c) {
	cout << "cat name: " << c.name << "\ncat color: " << c.color << "\n";
	return cout;
}

std::ostream& operator << (std::ostream& cout, Parrot& p) {
	cout << "parrot name: " << p.name; //<< "\ndog alive " << p.alive << "\n";
	return cout;
}

int main(){

	Dog dog1("Rex", "shepherd", 5);
	Cat cat1("Tom", "grey");
	Parrot parrot1("Polly", true);

	std::cout << dog1<< std::endl;
	std::cout << cat1 << std::endl;
	std::cout << parrot1 << std::endl;
	if (parrot1.getAlive())



}

