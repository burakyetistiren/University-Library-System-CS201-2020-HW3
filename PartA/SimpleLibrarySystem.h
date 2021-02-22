#include "SimpleStudent.h"
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#ifndef PART_A_SIMPLELIBRARYSYSTEM_H
#define PART_A_SIMPLELIBRARYSYSTEM_H


class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void showStudent(const int studentId) const;

    void printStudents();

private:
    struct StudentNode
    {
        Student s;
        StudentNode* next;
    };
    StudentNode* head;
    StudentNode* findStudent(int id) const;
    int studentCount;
};


#endif //PART_A_SIMPLELIBRARYSYSTEM_H