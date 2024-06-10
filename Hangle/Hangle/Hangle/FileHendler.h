#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class FileHandler
{
	string path;

public:
	vector <string> wordsA;
	vector <string> wordsC;
	vector <string> wordsF;
	vector <string> wordsI;
	vector <string> wordsP;

	ofstream fin;

	FileHandler(string pathP) : path{ pathP } {}

	void readThemeAnimals(string wordsA) {
		fin.open(path);
		if (fin.is_open()) {
			vector<string> line;
			while (!fin.eof()) {
				/*if (getline(fin, line)) {
					stringstream ss(line);
					getline(ss, loginTemp, ';');					
					ss.ignore();
					users[loginTemp] = new Student(loginTemp);*/
				}
			}
			fin.close();
	}
	void readThemeClothes(string wordsC) {}
	void readThemeFood(string wordsF) {}
	void readThemeItems(string wordsI) {}
	void readThemePlans(string wordsP) {}




};

