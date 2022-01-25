#include "heap.h"

MaxHeap::MaxHeap() {
	_data = new int[CAPACITY];
	size = 0;
}

MaxHeap::~MaxHeap() {
	delete[] _data;
}

void MaxHeap::heapify(int* arr, int n) {
	for (int i = 0; i<n; i++) {
		push(arr[i]);
	}
}

void MaxHeap::push(int a) {
	_data[size] = a;
	size++;
	siftUp(size-1);
}

int MaxHeap::pop() {
	if (size == 0) {
		return EMPTY;
	}

	int result = _data[0];
	_data[0] = _data[size-1];
	size--;
	siftDown(0);
	return result;
}

int MaxHeap::peek() {
	if (size == 0) {
		return EMPTY;
	}
	return _data[0];
}

void MaxHeap::clear() {
	size = 0;
}

void MaxHeap::print() {
	for (int i = 0; i<size; i++) {
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}

void MaxHeap::siftUp(int a) {
	if (a == 0) {
		return;
	}

	int parent = (a-1) / 2;
	if (_data[parent] >= _data[a]) {
		return;
	}

	int sw = _data[a];
	_data[a] = _data[parent];
	_data[parent] = sw;
	siftUp(parent); 
}

void MaxHeap::siftDown(int a) {
	int left = 2*a + 1;
	int right = 2*a + 2;

	if (left >= size) {
		return;
	}

	if (right >= size || _data[left] >= _data[right]) {
		if (_data[a] >= _data[left]) {
			return;
		}

		int sw = _data[a];
		_data[a] = _data[left];
		_data[left] = sw;
		siftDown(left); 
	}
	else {
		if (_data[a] >= _data[right]) {
			return;
		}

		int sw = _data[a];
		_data[a] = _data[right];
		_data[right] = sw;
		siftDown(right); 
	}
}