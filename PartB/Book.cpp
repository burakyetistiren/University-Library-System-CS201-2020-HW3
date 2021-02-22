#include <iostream>
#include "Book.h"
using namespace std;
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
Book::Book(int id, string name, int year)
{
    this->id = id;
    this->name = name;
    this->year = year;
}

Book::~Book(){}

void Book::setId(int id)
{
    this->id = id;
}

void Book::setName(string name)
{
    this->name = name;
}

void Book::setYear(int year)
{
    this->year = year;
}

int Book::getId() const
{
    return id;
}

string Book::getName() const
{
    return name;
}

int Book::getYear() const
{
    return year;
}

void Book::operator=(const Book& right)
{
    this->id = right.id;
    this->name = right.name;
    this->year = right.year;
}