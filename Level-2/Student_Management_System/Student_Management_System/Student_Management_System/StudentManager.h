#pragma once
#include <vector>
#include "Student.h"

void loadStudents(vector<Student>& students);
void saveStudents(const vector<Student>& students);

void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

Student* findStudentByID(vector<Student>& students, int id);
const Student* findStudentByID(const vector<Student>& studnets, int id);

int getValidInt(string message);
double getValidDouble(string message);
void clearInput();