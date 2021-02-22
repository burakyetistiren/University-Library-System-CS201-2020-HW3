#include "SimpleLibrarySystem.h"
/*
   Name: Burak Yetistiren
   ID: 21802608
*/
LibrarySystem::LibrarySystem():head(NULL), studentCount(0) {}

LibrarySystem::~LibrarySystem() {
    while(head)
    {
        deleteStudent(head->s.getId());
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

            if(head)
            {
                StudentNode* cur = head;
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
            ++studentCount;
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
        if(head)
        {
        StudentNode *toBeDeleted = findStudent(studentId);
        if(toBeDeleted)
        {
            if(toBeDeleted == head)
            {
                toBeDeleted = head;
                head = head->next;
            }
            else
            {
                StudentNode* prev = head;
                while( prev->next != toBeDeleted)
                    prev = prev->next;
                toBeDeleted = prev->next;
                prev->next = toBeDeleted->next;
            }
            toBeDeleted->next = NULL;
            delete toBeDeleted;
            toBeDeleted = NULL;
            --studentCount;
        }
        else
            cout << "Student " << studentId << " does not exist in the system." << endl;
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

        }
        else
            cout << "Student " << studentId << " does not exist in the system." << endl;
    //delete toDisplay;
    }
    else
        cout << "Please enter a valid student ID." << endl;
}

LibrarySystem::StudentNode* LibrarySystem::findStudent(int id) const {
    if(head)
    {
        StudentNode* curr = head;
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

void LibrarySystem::printStudents()
{
    cout << endl;
    for( StudentNode* cur = head; cur; cur = cur->next)
        cout << cur->s.getId() << "      " << cur->s.getName() <<endl;
}