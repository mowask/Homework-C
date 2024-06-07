#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "User.h"

using namespace std;

class Student : public User
{
	string name;
	string address;
	int age;
	vector<int> marks;
public:

	Student(string loginP, string passwordP, string nameP, string addressP, int ageP) : User(loginP, passwordP), name{ nameP }, address{ addressP }, age{ ageP } {}

	virtual void print() {
		printf("login: %s, name: %s, address: %s, age: %d\n", login.data(), name.data(), address.data(), age);
	}

	void printToFileCSV(ofstream& fout) {
		fout <<endl<<login<<";" << password<<";" << name << ";" << address<< ";" << age << "\n";
	}



};

