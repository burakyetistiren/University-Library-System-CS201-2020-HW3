#include <iostream>
using namespace std;
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#ifndef PART_A_SIMPLESTUDENT_H
#define PART_A_SIMPLESTUDENT_H


class Student {
public:
    Student(int id = 0, string name = "");
    ~Student();
    void setId(int id);
    void setName(string name);
    int getId() const;
    string getName() const;
    void operator=(const Student& right);
private:
    int id;
    string name;
};

#endif //PART_A_SIMPLESTUDENT_H