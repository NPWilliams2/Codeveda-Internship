#include <iostream>
#include "Algorithms.h"

using namespace std;

void bubbleSort(vector<int>& numbers)
{
	int size = numbers.size();

	for (int i = 0; i < size - 1; i++)
	{
		bool swapped = false;

		for (int j = 0; j < size - 1; j++)
		{
			if (numbers[j] > numbers[j + 1]) 
			{
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;

				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}

int linearSearch(const vector<int>& numbers, int target)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == target)
		{
			return i;
		}
	}

	return -1;
}

int binarySearch(const vector<int>& numbers, int target)
{
	int left = 0;
	int right = numbers.size() - 1;

	while (left <= right)
	{
		int middle = left + (right - left) / 2;

		if (numbers[middle] == target)
		{
			return middle;
		}
		else if (numbers[middle] < target)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}

	return -1;
}

void displayNumbers(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		cout << "No numbers have been entered yet." << endl;
		return;
	}

	cout << "Numbers: ";

	for (int number : numbers)
	{
		cout << number << " ";
	}

	cout << endl;
}

void displayComplexity()
{
	cout << "\n===== Algorithm Time Complexity =====" << endl;

	cout << "\nBubble Sort." << endl;
	cout << "Best Case: 0(n)" << endl;
	cout << "Avarage Case: 0(n^2)" << endl;
	cout << "Worst Case: 0(n^2)" << endl;

	cout << "\nLinear Search:" << endl;
	cout << "Best Case: 0(1)" << endl;
	cout << "Avarage Case: 0(n)" << endl;
	cout << "Worst Case: 0(n)" << endl;

	cout << "\nBinary Search:" << endl;
	cout << "Best Case: 0(1)" << endl;
	cout << "Average Case: 0(log n)" << endl;
	cout << "Worst Case: 0(log n)" << endl;
}