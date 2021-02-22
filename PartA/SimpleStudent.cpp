#include "SimpleStudent.h"
#include <iostream>
using namespace std;
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
Student::Student(int id, string name) {}

Student::~Student() {}

void Student::setId(int id) {
    this->id = id;
}

void Student::setName(string name) {
    this->name = name;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

void Student::operator=(const Student &right) {
    name = right.name;
    id = right.id;
}