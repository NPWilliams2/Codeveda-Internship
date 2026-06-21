#include <iostream>
#include <fstream>
#include <limits>
#include "StudentManager.h"

using namespace std;

void clearInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidInt(string message)
{
	int value;

	while (true)
	{
		cout << message;

		if (cin >> value)
		{
			clearInput();
			return value;
		}

		cout << "Invalid Input. Please enter a number" << endl;
		clearInput();
	}
}

double getValidDouble(string message)
{
	double value;

	while (true)
	{
		cout << message;

		if (cin >> value)
		{
			clearInput();
			return value;
		}

		cout << "Invalid Input. Please enter a valid grade" << endl;
		clearInput();
	}
}

Student* findStudentByID(vector<Student>& students, int id)
{
	for (Student& student : students)
	{
		if (student.id == id)
		{
			return &student;
		}
	}

	return nullptr;
}

const Student* findStudentByID(const vector<Student>& students, int id)
{
	for (const Student& student : students)
	{
		if (student.id == id)
		{
			return &student;
		}
	}

	return nullptr;
}

void loadStudents(vector<Student>& students)
{
	ifstream file("student.txt");

	if (!file)
	{
		return;
	}

	Student student;

	while (file >> student.id)
	{
		file.ignore();
		getline(file, student.name);
		file >> student.grade;
		file.ignore();

		students.push_back(student);
	}

	file.close();
}

void saveStudents(const vector<Student>& students)
{
	ofstream file("student.txt");

	for (const Student& student : students)
	{
		file << student.id << endl;
		file << student.name << endl;
		file << student.grade << endl;
	}

	file.close();
}

void addStudent(vector<Student>& students)
{
	Student student;

	cout << "\n===== Add Student =====" << endl;

	student.id = getValidInt("Enter Student ID: ");

	if (findStudentByID(students, student.id) != nullptr)
	{
		cout << "Error: A student with this ID already exists" << endl;
		return;
	}

	cout << "Enter student name: ";
	getline(cin, student.name);

	student.grade = getValidDouble("Enter student grade: ");

	students.push_back(student);

	cout << "Student added successfully" << endl;
}

void displayStudents(const vector<Student>& students)
{
	cout << "\n===== Student Records =====" << endl;

	if (students.empty())
	{
		cout << "No student records found" << endl;
		return;
	}

	for (const Student& student : students)
	{
		cout << "\nID: " << student.id << endl;
		cout << "Name: " << student.name << endl;
		cout << "Grade: " << student.grade << endl;
	}
}

void searchStudent(const vector<Student>& students)
{
	cout << "\n===== Search Student =====" << endl;

	int id = getValidInt("Enter student ID to search: ");

	const Student* student = findStudentByID(students, id);

	if (student != nullptr)
	{
		cout << "\nStudent found: " << endl;
		cout << "ID: " << student->id << endl;
		cout << "Name: " << student->name << endl;
		cout << "Grade: " << student->grade << endl;
	}
	else
	{
		cout << "Student not found" << endl;
	}
}

void deleteStudent(vector<Student>& students)
{
	cout << "\n===== Delete Student =====" << endl;

	int id = getValidInt("Enter student ID to delete: ");

	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].id == id)
		{
			students.erase(students.begin() + i);
			cout << "Student deleted successfully" << endl;
			return;
		}
	}

	cout << "Student not found" << endl;
}

void updateStudent(vector<Student>& students)
{
	cout << "\n===== Update Student =====" << endl;

	int id = getValidInt("Enter student ID to update: ");

	Student* student = findStudentByID(students, id);

	if (student != nullptr)
	{
		cout << "Enter new student name: ";
		getline(cin, student->name);

		student->grade = getValidDouble("Enter new student grade: ");

		cout << "Student updated successfully" << endl;
	}
	else
	{
		cout << "Student not found" << endl;
	}
}