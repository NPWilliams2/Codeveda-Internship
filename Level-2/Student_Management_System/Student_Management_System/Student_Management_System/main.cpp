#include <iostream>
#include <vector>
#include "StudentManager.h"

using namespace std;

void displayMenu()
{
    cout << "\n===== Student Management System =====" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search Student by ID" << endl;
    cout << "4. Update Student" << endl;
    cout << "5. Delete Student" << endl;
    cout << "6. Save and Exit" << endl;
}

int main()
{
    vector<Student> students;
    int choice;

    loadStudents(students);

    do
    {
        displayMenu();

        choice = getValidInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            displayStudents(students);
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            updateStudent(students);
            break;
        case 5:
            deleteStudent(students);
            break;
        case 6:
            saveStudents(students);
            cout << "Student records saved successfully" << endl;
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please select an option from 1 to 6" << endl;
        }

    } while (choice != 6);

    return 0;
}
