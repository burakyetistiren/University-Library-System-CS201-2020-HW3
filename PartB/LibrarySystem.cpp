#include "LibrarySystem.h"
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
LibrarySystem::LibrarySystem():headStudent(NULL), studentCount(0), headBook(NULL), bookCount(0) {}

LibrarySystem::~LibrarySystem() {
	cout << "ENTERING DESTRUCTOR" << endl;
    while(headStudent)
    {
        deleteStudent(headStudent->s.getId());
    }

    while(headBook)
    {
        deleteBook(headBook->b.getId());
    }
}

void LibrarySystem::addStudent(const int studentId, const string studentName) {
    if(!(studentId < 0))
    {
        if(!findStudent(studentId))
        {
            StudentNode* newNode = new StudentNode;
            newNode->s.setName(studentName);
            newNode->s.setId(studentId);
            newNode->next = NULL;

            if(headStudent)
            {
                StudentNode* cur = headStudent;
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
                headStudent = newNode;
            ++studentCount;
            cout << "Student " << studentId << " has been added." << endl;
        }
        else
            cout << "Student " << studentId << " already exists." << endl;
    }
    else
        cout << "Please enter a valid student ID." << endl;

}

void LibrarySystem::deleteStudent(const int studentId) {
    if(!(studentId < 0))
    {
        if(headStudent)
        {
            StudentNode *toBeDeleted = findStudent(studentId);
            if(toBeDeleted)
            {
                if(toBeDeleted->s.getBookCount() > 0)
                {
                    for( BookNode* cur = headBook; cur; cur = cur->next)
                        if(studentId == cur->studentId)
                            returnBook(cur->b.getId());
                    toBeDeleted->s.deleteAllBooks();
                }
                if(toBeDeleted == headStudent)
                {
                    toBeDeleted = headStudent;
                    headStudent = headStudent->next;
                }
                else
                {
                    StudentNode* prev = headStudent;
                    while( prev->next != toBeDeleted)
                        prev = prev->next;
                    toBeDeleted = prev->next;
                    prev->next = toBeDeleted->next;
                }
                toBeDeleted->next = NULL;
                delete toBeDeleted;
                toBeDeleted = NULL;
                --studentCount;
                cout << "Student " << studentId << " has been deleted." << endl;
            }
            else
                cout << "Student " << studentId << " does not exist." << endl;
        }
        else
            cout << "There are no students in the system." << endl;
    }
    else
        cout << "Please enter a valid student ID." << endl;

}

void LibrarySystem::showStudent(const int studentId) const {
    cout << endl;
    if(!(studentId < 0))
    {
        StudentNode* toDisplay = findStudent(studentId);
        if(toDisplay)
        {
            cout << "Student Id: " << toDisplay->s.getId() << " "
            << "Student Name: " << toDisplay->s.getName() << endl;
           toDisplay->s.showAllBooks();

        }
        else
            cout << "Student " << studentId << " does not exist." << endl;
    //delete toDisplay;
    }
    else
        cout << "Please enter a valid student ID." << endl;
}

LibrarySystem::StudentNode* LibrarySystem::findStudent(int id) const {
    if(headStudent)
    {
        StudentNode* curr = headStudent;
        while(curr)
        {
            if( curr->s.getId() == id)
                return curr;
            curr = curr->next;
        }
        delete curr;
    }
    else
        return NULL;
    return NULL;
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear)
{
    if( bookId > 0)
    {
        if(!findBook(bookId))
        {
            BookNode* newNode = new BookNode;
            newNode->b.setName(bookName);
            newNode->b.setId(bookId);
            newNode->b.setYear(bookYear);
            newNode->next = NULL;
            newNode->isCheckedOut = false;

            if(headBook)
            {
                BookNode* cur = headBook;
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
                headBook = newNode;
            ++bookCount;
            cout << "Book " << bookId << " has been added." << endl;
        }
        else
            cout << "Book " << bookId << " already exists." << endl;
    }
    else
        cout << "Pleas enter a valid book ID" << endl;
}

void LibrarySystem::deleteBook(const int bookId)
{
    if(bookCount > 0)
    {
        BookNode *toBeDeleted = findBook(bookId);
        if(toBeDeleted)
        {
            returnBook(bookId);
            if(toBeDeleted == headBook)
            {
                toBeDeleted = headBook;
                headBook = headBook->next;
            }
            else
            {
                BookNode* prev = headBook;
                while( prev->next != toBeDeleted)
                    prev = prev->next;
                toBeDeleted = prev->next;
                prev->next = toBeDeleted->next;
            }
            toBeDeleted->next = NULL;
            delete toBeDeleted;
            toBeDeleted = NULL;
            --bookCount;
            cout << "Book " << bookId << " has been deleted." << endl;
        }
        else
            cout << "Book " << bookId << " does not exist." << endl;
    }
    else
        cout << "There are no books in the library." << endl;
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
    BookNode* book = findBook(bookId);
    if(book)
    {
        StudentNode* student = findStudent(studentId);
        if(student)
        {
            if(!book->isCheckedOut)
            {
                book->isCheckedOut = true;
                book->studentId = studentId;

                student->s.addBook(bookId, book->b.getName(), book->b.getYear());
                cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
            }
            else
                cout << "Book has been already checked out by student " << book->studentId << endl;
        }
        else
            cout << "Student " << studentId << " does not exist for checkout." << endl;
    }
    else
        cout << "Book " << bookId << " does not exist for checkout." << endl;
}

void LibrarySystem::returnBook(const int bookId)
{
    BookNode* book = findBook(bookId);
    if(book)
    {
        if(book->isCheckedOut)
        {
            StudentNode* student = findStudent(book->studentId);
            book->isCheckedOut = false;
            book->studentId = 0;

            student->s.deleteBook(bookId);
            cout << "Book " << bookId << " has been returned" << endl;
        }
        else
            cout << "Book " << bookId << " has not been checked out." << endl;
    }
    else
        cout << "Book does not exist in the library." << endl;
}

void LibrarySystem::showAllBooks() const
{
    if(headBook)
    {
        cout << "Book ID          Book Name                 Book Year          Status" << endl;
        for(BookNode* cur = headBook; cur; cur = cur->next)
        {
            int space;
            cout << cur->b.getId() << "             " << cur->b.getName();
            space = 27 - cur->b.getName().length();
            for( int i = 1; i < space; ++i)
                cout << " ";
            cout << cur->b.getYear();
            if( cur->isCheckedOut)
                cout << "               Checked out by student " << cur->studentId << endl;
            else
                cout << "               Not checked out" << endl;
        }
    }
    else
        cout << "There are no books in the library." << endl;
}

void LibrarySystem::showBook(const int bookId) const
{
    BookNode* book = findBook(bookId);
    if(book)
    {
        int space;
        cout << book->b.getId() << "             " << book->b.getName();
        space = 27 - book->b.getName().length();
        for( int i = 1; i < space; ++i)
                cout << " ";
        cout << book->b.getYear();
        if( book->isCheckedOut)
            cout << "               Checked out by student " << book->studentId << endl;
        else
            cout << "               Not checked out" << endl;
    }
    else
        cout << "Book does not exist in the library." << endl;
}

LibrarySystem::BookNode* LibrarySystem::findBook(int id) const
{
    if(headBook)
    {
        BookNode* curr = headBook;
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