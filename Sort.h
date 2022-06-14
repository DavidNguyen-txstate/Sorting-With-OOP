#ifndef SORT_H
#define SORT_H
#include <vector>
using namespace std;

class Sort
{
	private:
		std::vector<int> vec;
		int left;
		int mid;
		int right;
		int x;
		int y;
		void Swap(vector<int> &vec, int x, int y);
		void Merge(vector<int> &vec, int left, int mid, int right);
		int Partition(vector<int> &vec, int left, int right);
	public:
		Sort();
		void PrintVector(const vector <int> &vec);
		void SelectionSort(vector<int> &vec);
		void InsertionSort(vector<int> &vec);
		void BubbleSort(vector<int> &vec);
		void MergeSort(vector<int> &vec, int left, int right);
		void QuickSort(vector<int> &vec, int left, int right);
};
#include "Sort.cpp"
#endif
