#include <iostream>
#include "Book.h"
using namespace std;
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#ifndef _STUDENT_H
#define _STUDENT_H


class Student {
public:
    Student(int id = 0, string name = "");
    ~Student();
    void setId(int id);
    void setName(string name);
    int getId() const;
    int getBookCount() const;
    string getName() const;
    void operator=(const Student& right);
    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void deleteAllBooks();
    void showAllBooks() const;
private:
    int id;
    string name;
    struct BookNode
    {
        Book b;
        BookNode* next;
    };
    BookNode* head;
    BookNode* findBook(int id) const;
    int bookCount;
};

#endif //_STUDENT_H