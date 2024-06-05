#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{
	string name;
	int age;
	string address;
public:
	Student(string nameP, int ageP, string addressP) : name{ nameP }, age{ ageP }, address{ addressP } {}

	void print() {
		cout << name << " " << age << " " << address << "\n";
	}

	//	метод для сохранения информации в файл CSV
	void printToFileCSV(ofstream& fout) {
		fout << name << ";" << age << ";" << address << "\n";
	}
};

