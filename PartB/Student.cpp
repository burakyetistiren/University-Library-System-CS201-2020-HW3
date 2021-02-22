#include "Student.h"
#include <iostream>
using namespace std;
/*
   Name: Burak Yetistiren
   ID: 21802608
*/

Student::Student(int id, string name):head(NULL), bookCount(0)
{
    this->id = id;
    this->name = name;
}

Student::~Student() {
    deleteAllBooks();
}

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

int Student::getBookCount() const
{
    return bookCount;
}

void Student::operator=(const Student &right) { //CHANGE
    name = right.name;
    id = right.id;
}

void Student::addBook(const int bookId, const string bookName, const int bookYear)
{

    BookNode* newNode = new BookNode;
    newNode->b.setName(bookName);
    newNode->b.setId(bookId);
    newNode->b.setYear(bookYear);
    newNode->next = NULL;

    if(head)
    {
        BookNode* cur = head;
        while(cur) //iterate until end
        {
            if(!cur->next)
            {
                cur->next = newNode;
                break;
            }
            cur = cur->next;
        }
    }
    else
        head = newNode;
    ++bookCount;
}

void Student::deleteAllBooks()
{
    while(head)
    {
        deleteBook(head->b.getId());
    }
}

void Student::deleteBook(const int bookId)
{
    if(bookCount > 0)
    {
        if(head)
        {
            BookNode *toBeDeleted = findBook(bookId);
            if(toBeDeleted)
            {
                if(toBeDeleted == head)
                {
                    toBeDeleted = head;
                    head = head->next;
                }
                else
                {
                    BookNode* prev = head;
                    while( prev->next != toBeDeleted)
                        prev = prev->next;
                    toBeDeleted = prev->next;
                    prev->next = toBeDeleted->next;
                }
                toBeDeleted->next = NULL;
                delete toBeDeleted;
                toBeDeleted = NULL;
                --bookCount;
            }
            else
                cout << "Student " << id << " does not have the book " << bookId << "." << endl;
        }
        else
            cout << "There is no book of the student." << endl;
    }
    else
        cout << "There is no book of the student." << endl;
}

void Student::showAllBooks() const
{
    if(bookCount > 0)
    {
        cout << "Student " << id << " has checked out the following books:" << endl;
        cout << "Book ID          Book Name                 Book Year" << endl;
        for( BookNode* cur = head; cur; cur = cur->next)
        {
            int space;
            cout << cur->b.getId() << "             " << cur->b.getName();
            space = 27 - cur->b.getName().length();
            for( int i = 1; i < space; ++i)
                cout << " ";
            cout << cur->b.getYear();
            cout << endl;
        }
    }
    else
        cout << "Student " << id << " has no books." << endl;
}

Student::BookNode* Student::findBook(int id) const
{
    if(head)
    {
        BookNode* curr = head;
        while(curr)
        {
            if( curr->b.getId() == id)
                return curr;
            curr = curr->next;
        }
        delete curr;
    }
    else
        return NULL;
    return NULL;
}