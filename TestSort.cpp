#include "Sort.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec1 = {9, 7, 2, 4};
	vector<int> vec2 = {9, 7, 2, 4};
	vector<int> vec3 = {9, 7, 2, 4};
	vector<int> vec4 = {2, 4, 1, 3};
	vector<int> vec5 = {1, 2, 4, 5, 3};
	Sort new_sort;
	cout << "Selection Sort: " << endl;
	cout << "Before: ";
	new_sort.PrintVector(vec1);
	new_sort.SelectionSort(vec1);
	cout << "After: ";
	new_sort.PrintVector(vec1);
	cout << "Insertion Sort: " << endl;
	cout << "Before: ";
	new_sort.PrintVector(vec2);
	new_sort.InsertionSort(vec2);
	cout << "After: ";
	new_sort.PrintVector(vec2);
	cout << "Bubble Sort: " << endl;
	cout << "Before: ";
	new_sort.PrintVector(vec3);
	new_sort.BubbleSort(vec3);
	cout << "After: ";
	new_sort.PrintVector(vec3);
	cout << "Merge Sort: " << endl;
	cout << "Before: ";
	new_sort.PrintVector(vec4);
	new_sort.MergeSort(vec4, 0, vec4.size() - 1);
	cout << "After: ";
	new_sort.PrintVector(vec4);
	cout << "Quick Sort: " << endl;
	cout << "Before: ";
	new_sort.PrintVector(vec5);
	new_sort.QuickSort(vec5, 0, vec5.size() - 1);
	cout << "After: ";
	new_sort.PrintVector(vec5);
}
