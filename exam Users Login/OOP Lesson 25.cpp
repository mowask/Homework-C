// OOP Lesson 25.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Student.h"

using namespace std;

int main()
{
    /*int x = 12;
    ofstream fout;
    fout.open("C:\\examples\\example.txt");
    if (fout.is_open()) {
        fout << x;
        fout.close();
    }*/

    /*int x;
    ifstream fin;
    fin.open("C:\\examples\\example.txt");
    if (fin.is_open()) {
        if (fin >> x)
            cout << x;
        fin.close();
    }*/

//    string name;
//    ofstream fout;
//    char delim = '0';
//    fout.open("C:\\examples\\example.txt", std::ios::app);
//    if (fout.is_open()) {   
//    ////cout << "Enter your name: ";
//    //if (getline(cin, name, delim));
//    //cout << "Hello, "<< name<<"!" << endl;
//    while (true) {
//        getline(cin, name);
//        if (name == "0") break;
//        fout << name << endl;
//    }
//    fout.close();
//}
//    else { cout << "couldn't open file!\n";
//    }


    /*string name;
    ifstream fin;
    fin.open("C:\\examples\\example.txt");
    if (fin.is_open()) {
        while (!fin.eof()) {
            if (getline(fin, name)) {
                cout << name << endl;
            }
        }
        fin.close();
    }
    else {
        cout << "couldn't open file!\n";
    }*/


    //string data = "Ivan Ivanov;35;Vladimir,Russia\n";
    //std:: stringstream ss(data);
    //string name;
    //int age;
    //string address;
    //getline(ss, name, ';');
    //ss >> age;
    //ss.ignore();                                           // пропускает   ';'
    //getline(ss, address);
    //cout << "name: " << name << endl;
    //cout << "age: " << age << endl;
    //cout << "address: " << address << endl;
   

    /*int x = 16;
    ofstream fout;
    fout.open("C:\\examples\\example.txt", ios::binary);
    if (fout.is_open()) {
        fout.write(reinterpret_cast<char*>(&x), sizeof(x));
        fout.close();
    }
    else {
        cout << "Error open file!\n";
    }*/

    /*int x;
    ifstream fin;
    fin.open("C:\\examples\\example.txt", ios::binary);
    if (fin.is_open()) {
        fin.read(reinterpret_cast<char*>(&x), sizeof(x));
        cout << x;
        fin.close();
    }
    else {
        cout << "Error open file!\n";
    }*/



    vector < Student*> students;
    students.push_back(new Student("Ivan Ivanov", 35, "Vladimir, Russia"));
    students.push_back(new Student("Mark Markov", 24, "Vladimir, Russia"));
    students.push_back(new Student("Test Testov", 19, "Moscow, Russia"));

    ofstream fout;
    fout.open("C:\\examples\\students.txt", ios::app);
    if (fout.is_open()) {
        for (auto stud : students)
            stud->printToFileCSV(fout);
    }
    else {
        cout << "Error open file!\n";
    }


    string line, name, address;
    int age;
    ifstream fin;
    fin.open("C:\\examples\\students.txt");
    if (fin.is_open()) {
        while (!fin.eof()) {
            if (getline(fin, line)) {
                stringstream ss(line);
                getline(ss, name, ';');
                ss >> age;
                ss.ignore();
                getline(ss, address);

                students.push_back(new Student(name, age, address));        //создаем объект студент с извлечением данных и добавлением его в вектор
            }
        }
        fin.close();

        for (auto stud : students)
            stud->print();
    }
    else {
        cout << "Error open file!\n";
    }

    return 0;
}
