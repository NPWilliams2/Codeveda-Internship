#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include "Algorithms.h"

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

		cout << "Invalid input. Please enter a number" << endl;
		clearInput();
	}
}

void enterNumbers(vector<int>& numbers)
{
	numbers.clear();

	int size = getValidInt("How many numbers would you like to enter? ");

	while (size <= 0)
	{
		cout << "Size must be greater than 0" << endl;
		size = getValidInt("How many numbers would you like to enter? ");
	}

	for (int i = 0; i < size; i++)
	{
		int number = getValidInt("Enter number " + to_string(i + 1) + ": ");
		numbers.push_back(number);
	}

	cout << "Numbers saved successfully" << endl;
}

void displayMenu()
{
	cout << "\n===== Sorting & Searching Algorithms =====" << endl;
	cout << "1. Enter Numbers" << endl;
	cout << "2. Display Numbers" << endl;
	cout << "3. Bubble Sort" << endl;
	cout << "4. Linear Search" << endl;
	cout << "5. Binary Search" << endl;
	cout << "6. Display Algorithm Complexity" << endl;
	cout << "7. Exit" << endl;
}

int main()
{
	vector<int> numbers;
	int choice;

	do
	{
		displayMenu();
		choice = getValidInt("Enter your choice: ");

		switch (choice)
		{
		case 1:
			enterNumbers(numbers);
			break;

		case 2:
			displayNumbers(numbers);
			break;

		case 3:
			if (numbers.empty())
			{
				cout << "Please enter a number first" << endl;
			}
			else
			{
				bubbleSort(numbers);
				cout << "Numbers sorted successfully using Bubble Sort" << endl;
				displayNumbers(numbers);
			}
			break;

		case 4:
			if (numbers.empty())
			{
				cout << "Please enter numbers first" << endl;
			}
			else
			{
				int target = getValidInt("Enter number to search for: ");
				int index = linearSearch(numbers, target);

				if (index != -1)
				{
					cout << "Numbers found at index: " << index << endl;
				}
				else
				{
					cout << "Numbers not found" << endl;
				}
			}
			break;

		case 5:
			if (numbers.empty())
			{
				cout << "Please enter numbers first" << endl;
			}
			else
			{
				bubbleSort(numbers);

				int target = getValidInt("Enter number to search for: ");
				int index = binarySearch(numbers, target);

				cout << "Binary search works on sorted data" << endl;
				displayNumbers(numbers);

				if (index != -1)
				{
					cout << "Number found at index: " << index << endl;
				}
				else
				{
					cout << "Number not found" << endl;
				}
			}
			break;

		case 6:
			displayComplexity();
			break;

		case 7:
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid choice. Please select an option from 1 to 7" << endl;
		}
	} while (choice != 7);

	return 0;
}