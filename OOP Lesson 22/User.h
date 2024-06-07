#pragma once
#include <iostream>


using namespace std;

class User
{
protected:
	std::string login;
	std::string password;
public:

	User(string loginP, string passwordP) : login{ loginP }, password{ passwordP } {}

	bool chekPassword(string loginP, string passwordP) {
		return (login == loginP && password == passwordP);		
	}

	virtual void print() = 0;

};

