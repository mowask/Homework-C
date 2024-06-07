#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "User.h"
#include "Student.h"

using namespace std;

class FileHandler
{
	string path;
public:
	ofstream fout;
	ifstream fin;

	FileHandler(string pathP) : path{ pathP } {}

	void readStudentsFromFile(std::map<string,User*>& users) {
		
		fin.open(path);
		if (fin.is_open()) {
			string line, loginTemp, passwordTemp, nameTemp, addressTemp, lineTemp;
			int ageTemp;
			while (!fin.eof()) {
				if (getline(fin, line)) {
					stringstream ss(line);
					getline(ss, loginTemp, ';');
					getline(ss, passwordTemp, ';');
					getline(ss, nameTemp, ';');
					getline(ss, addressTemp, ';');
					ss >> ageTemp;
					ss.ignore();
					users[loginTemp] = new Student(loginTemp, passwordTemp, nameTemp, addressTemp, ageTemp);
				}
			}
			fin.close();

			/*for (auto stud : students)
				stud->print();*/
		}
		else {
			cout << "Error open file!\n";
		}
	}


	bool writeStudentToFile(Student* newStudent) {
		fout.open(path, ios::app);
		if (fout.is_open()) {			
			newStudent->printToFileCSV(fout);
			fout.close();
			return true;
		}
		return false;	
	}

};

