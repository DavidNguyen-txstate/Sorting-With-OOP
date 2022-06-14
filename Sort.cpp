#include "Sort.h"
#include <vector>
#include <iostream>
using namespace std;

Sort::Sort() {
	
}

void Sort::Swap(vector<int> &vec, int x, int y) {
	int temp = vec[x];
  	vec[x] = vec[y];
  	vec[y] = temp;
}

void Sort::SelectionSort(vector<int> &vec) {
  	for (int i = 0; i < vec.size(); i++) {
    	int min = i;
    	for (int j = i+1; j < vec.size(); j++) {
      		if (vec[j] < vec[min]) {
        		min = j;
      		}
    	}
    	Swap(vec, i, min); // Assume this is implemented and is O(1) time
  	}
}

void Sort::InsertionSort(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++) {
    	int element = vec[i];
    	int j = i - 1;
    	while (j >= 0 && vec[j] > element) {
      		vec[j+1] = vec[j];
      		j--;
    	}
    	vec[j+1] = element;
	}
}

void Sort::BubbleSort(vector<int> &vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
    	for (int j = 0; j < vec.size() - i - 1; j++) {
      		if (vec[j] > vec[j + 1]) {
        		Swap(vec, j, j + 1); // Assume this is implemented and is O(1) time
      		}
    	}
  	}
}

void Sort::Merge(vector<int> &vec, int left, int mid, int right) {
	int left_size = mid - left + 1;
  	int right_size = right - mid;

  	vector<int> left_vec(left_size, 0);
  	for (int i = 0; i < left_size; i++) {
    	left_vec[i] = vec[left + i];
  	}

  	vector<int> right_vec(right_size, 0);
  	for (int j = 0; j < right_size; j++) {
    	right_vec[j] = vec[mid + 1 + j];
  	}

  	int left_index = 0;
  	int right_index = 0;
  	int merged_index = left;
  	while (left_index < left_size && right_index < right_size) {
    	if (left_vec[left_index] <= right_vec[right_index]) {
      		vec[merged_index] = left_vec[left_index];
      		left_index++;
      		merged_index++;
    	} 
		else {
      		vec[merged_index] = right_vec[right_index];
      		right_index++;
      		merged_index++;
    	}
  	}

  	while (left_index < left_size) {
    	vec[merged_index] = left_vec[left_index];
    	left_index++;
    	merged_index++;
  	}

  	while (right_index < right_size) {
    	vec[merged_index] = right_vec[right_index] ;
    	right_index++;
    	merged_index++;
  	}
}

void Sort::MergeSort(vector<int> &vec, int left, int right) {
	if (left < right){
    	int mid = (left + right)/ 2;
    	MergeSort(vec, left, mid);
    	MergeSort(vec, mid + 1, right);
    	Merge(vec, left, mid, right);
  	}
}

int Sort::Partition(vector<int> &vec, int left, int right) {
	int pivot = vec[right]; // Select last element as pivot
  	int small_index = left - 1; // Keeps track of last element smaller than pivot

  	for (int curr_index = left; curr_index < right; curr_index++) {  
    	if (vec[curr_index] < pivot) {
      		small_index++;
      		Swap(vec, small_index, curr_index);
    	}
  	}

  	Swap(vec, small_index + 1, right); // Swap pivot with first element larger than pivot
  	return small_index + 1; // Return new location of pivot
}

void Sort::QuickSort(vector<int> &vec, int left, int right) {
	if (left < right){
    	int pivot = Partition(vec, left, right);
    	QuickSort(vec, left, pivot - 1);
    	QuickSort(vec, pivot + 1, right);
  	}
}

void Sort::PrintVector(const vector<int> &vec) {
	cout << "[ ";
  	for (int i = 0; i < vec.size(); i++) {
    	cout << vec[i] << " ";
  	}
  	cout << "]" << endl;
}
