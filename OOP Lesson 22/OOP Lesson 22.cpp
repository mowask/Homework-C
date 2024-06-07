// OOP Lesson 22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

#include "User.h"
#include "Student.h"
#include "Admin.h"
#include "FileHandler.h"
#include "Menu.h"


using namespace std;

//
//namespace foo {
//    void func() {
//        std::cout << "foo\n";
//    }
//}
//
//namespace bar {
//    void func() {
//        std::cout << "bar\n";
//    }
//}
//
//namespace factory {
//    void func() {
//        std::cout << "factory\n";
//    }
//}
//
//using namespace factory;
//
//namespace factory {
//    int state = 16;
//}
//    
//namespace std {
//    int x = 5;
//}
//
//namespace test {
//    void show() {
//        std::cout << "test\n";
//    }
//    int x = 10;
//}
//
//int main()
//{
//    foo::func();
//    bar::func();
//    func();
//    std::cout << state << "\n";
//    std::cout << std::x;
//
//    using test::show;
//    show();
//    using std::cout;
//    cout << "hi";
//
//}

bool loginUser(map<string, User*>& users, string& login) {
	string password;

	cout << endl << "Enter login: ";
	cin >> login;
	cout << endl << "Enter password: ";
	cin >> password;
	cout << endl;
	return (users.count(login) && users[login]->chekPassword(login, password));
}

Student* registerUser(map<string, User*>& users, string& login) {
	string password, name, address;
	int age;

	cout << endl << "Enter password: ";
	cin >> password;
	cout << endl << "Name: ";
	getline(cin, name);
	cout << endl << "address: ";
	getline(cin, address);
	cout << endl << "age: ";
	cin >> age;

	Student* newStudent = new Student(login, password, name, address, age);
	users[login] = newStudent;
	return newStudent;
}

int main() {

	User* admin = new Admin;

	map < string, User* > users;
	users["Admin"] = admin;
	
	FileHandler fh("C:\\examples\\students.txt");
	fh.readStudentsFromFile(users);

	// vector < Student*> students;

	string login;

	bool loggedIn = false, exet = false;

	while (loggedIn == false && exet == false) {
		
		
		switch (Menu::startMenu()) {
		//system("cls");

		case 1:		 // login			
			if (loginUser(users, login)) {
				system("cls");
				cout << "Accessed\n";
				loggedIn = true;
			}
			else {
				system("cls");
				cout << "Error\n";
			}
			break;

		case 2:		// sign up
			cout << endl << "Enter login: ";
			cin >> login;
			if (!users.count(login)) {

				Student* newStudent = registerUser(users, login);
				if ( fh.writeStudentToFile(newStudent))
				loggedIn = true;	
				else {
				loggedIn = false;
				cout << "User not seved\n";
				}
			}
			else
				system("cls");
				cout << "Login already registered\n";
			break;

		case 3:		// exit			
			exet = true;	
			cout << "exit\n";
			break;					
			}
			cout << endl;
	}


	if (loggedIn) 
	{
		Admin* admin_user = dynamic_cast<Admin*> (users[login]);
		Student* student_user = dynamic_cast<Student*> (users[login]);
		
		if (admin_user) {
		for (auto user : users)
			user.second->print();
		}
	else if (student_user) 
		{
		
		while (loggedIn == true) 
			{			
			switch (Menu:: studentMenu()) 
				{
			case 1:
				cout << "test results\n";
				break;
			case 2:
				cout << "test yoursef\n";
				break;
			case 3:
				system("cls");
				cout << "logout\n";	
				loggedIn = false;
				break;
				}
			}
		}		
	}
}
