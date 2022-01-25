#include <iostream>
#include "heap.h"

#define N 11

using namespace std;

void heapSort(int* arr, int n) {
	MaxHeap mh;
	mh.heapify(arr, n);

	for (int i = n-1; i>=0; i--) {
		arr[i] = mh.pop();
	}
}

int main() {
	int arr[N-1]; 
	for (int i = 1; i<N; i++) {
		arr[i-1] = (7*i) % N;
	}

	cout << "Before Sorting" << endl;
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;

	cout << "Sorted" << endl;
	heapSort(arr, N-1);
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;
}