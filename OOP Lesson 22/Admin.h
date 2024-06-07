#pragma once
#include <iostream>
#include "User.h"

class Admin : public User
{
public:

	Admin() : User("Admin", "Password") {}

	virtual void print() {
		printf("login: %s\n", login.data());
	}

};

