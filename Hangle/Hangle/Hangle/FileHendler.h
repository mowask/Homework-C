#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

	void readThemeAnimals(string wordsA) {}
	void readThemeClothes(string wordsC) {}
	void readThemeFood(string wordsF) {}
	void readThemeItems(string wordsI) {}
	void readThemePlans(string wordsP) {}




};

