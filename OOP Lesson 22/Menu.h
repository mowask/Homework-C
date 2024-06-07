#pragma once
#include <iostream>
using namespace std;

class Menu
{
public:
	static int startMenu() {
		int choice;
		cout << "1 - Login\n";
		cout << "2 - Sign up\n";
		cout << "3 - Exit\n";
		cin >> choice;
		return choice;
	}

	static int studentMenu() {
		system("cls");
		cout << "1. test results\n";
		cout << "2. test yoursef\n";
		cout << "3. logout\n";
		int choice;
		cin >> choice;
		return choice;
	}
};

