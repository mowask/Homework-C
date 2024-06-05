#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"



//std::ostream& operator << (std::ostream& cout, Student& p) {
//	cout << "name: " << p.name << "\n age: " << p.age << "\nage: " << p.gender << "\n";
//	return cout;
//}
//
//std::ostream& operator << (std::ostream& cout, Student& s) {
//	cout << "name: " << s.name << "\n age: " << s.age << "\nage: " << s.gender << "\n";
//	return cout;
//}

int main() {
	std::vector<int> marks1 = { 5, 4, 5 };
	std::vector<int> marks2 = { 4, 5, 4 };
	
	Student student1("John", 18, "M", marks1);
	Student student2("Jane", 19, "F", marks2);

	std::cout << student1.getName() << "\n";


}