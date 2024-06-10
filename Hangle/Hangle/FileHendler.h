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

	ifstream fin;

	FileHandler(string pathP) : path{ pathP } {}

	void readThemeAnimals(vector<string>& wordsA) {
		fin.open(path);
		if (fin.is_open()) {
			string lineA, wordA;
			while (!fin.eof()) {
				if (getline(fin, lineA)) {
					stringstream ss(lineA);
					getline(ss, wordA, '\n');
					wordsA.push_back(wordA);					
				}
			}
			fin.close();
		}
	}

	void readThemeClothes(vector<string>& wordsC) {
		fin.open(path);
		if (fin.is_open()) {
			string lineC, wordC;
			while (!fin.eof()) {
				if (getline(fin, lineC)) {
					stringstream ss(lineC);
					getline(ss, wordC, '\n');
					wordsC.push_back(wordC);
				}
			}
			fin.close();
		}
	}
	void readThemeFood(vector<string>& wordsF) {
		fin.open(path);
		if (fin.is_open()) {
			string lineF, wordF;
			while (!fin.eof()) {
				if (getline(fin, lineF)) {
					stringstream ss(lineF);
					getline(ss, wordF, '\n');
					wordsF.push_back(wordF);
				}
			}
			fin.close();
		}
	}
	void readThemeItems(vector<string>& wordsI) {
		fin.open(path);
		if (fin.is_open()) {
			string lineI, wordI;
			while (!fin.eof()) {
				if (getline(fin, lineI)) {
					stringstream ss(lineI);
					getline(ss, wordI, '\n');
					wordsI.push_back(wordI);
				}
			}
			fin.close();
		}
	}
	void readThemePlans(vector<string>& wordsP) {
		fin.open(path);
		if (fin.is_open()) {
			string lineP, wordP;
			while (!fin.eof()) {
				if (getline(fin, lineP)) {
					stringstream ss(lineP);
					getline(ss, wordP, '\n');
					wordsP.push_back(wordP);
				}
			}
			fin.close();
		}
	}




};

