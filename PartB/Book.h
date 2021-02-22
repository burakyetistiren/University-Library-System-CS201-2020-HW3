#include <iostream>
using namespace std;
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
#ifndef _BOOK_H
#define _BOOK_H


class Book {
public:
    Book(int id = 0, string name = "", int year = 0);
    ~Book();
    void setId(int id);
    void setName(string name);
    void setYear(int year);
    int getId() const;
    string getName() const;
    int getYear() const;
    void operator=(const Book& right);
private:
    int id;
    int year;
    string name;
};

#endif //_BOOK_H