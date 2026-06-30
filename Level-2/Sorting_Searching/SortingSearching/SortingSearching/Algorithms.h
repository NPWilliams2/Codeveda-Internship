#pragma once
#include <vector>

using namespace std;

void bubbleSort(vector<int>& numbers);

int linearSearch(const vector<int>& numbers, int target);
int binarySearch(const vector<int>& numbers, int target);

void displayNumbers(const vector<int>& numbers);
void displayComplexity();