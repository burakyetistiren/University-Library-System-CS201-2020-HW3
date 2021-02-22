#include "Student.h"
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
    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showAllBooks() const;
    void showBook(const int bookId) const;
private:
    struct StudentNode
    {
        Student s;
        StudentNode* next;
    };
    StudentNode* headStudent;
    StudentNode* findStudent(int id) const;
    int studentCount;

    struct BookNode
    {
        Book b;
        bool isCheckedOut;
        BookNode* next;
        int studentId;
    };
    BookNode* headBook;
    BookNode* findBook(int id) const;
    int bookCount;
};


#endif //PART_A_SIMPLELIBRARYSYSTEM_H