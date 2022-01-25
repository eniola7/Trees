#include <iostream>
#include "binaryTree.h"

BinaryTree::BinaryTree() {
	_data = new int[CAPACITY];
	_vacant = new bool[CAPACITY];
	clear();
}

BinaryTree::~BinaryTree() {
	delete[] _data;
	delete[] _vacant;
}
		
bool BinaryTree::insert(int data) {
	if (_data[0] == EMPTY) {
		_data[0] = data;
		return true;
	}
	else {
		return insertStep(0, data);
	}
}

bool BinaryTree::remove(int data) {
	if (_data[0] == EMPTY) {
		return false;
	}
	else {
		return removeStep(0, data);
	}
}

bool BinaryTree::search(int data) {
	if (_data[0] == EMPTY) {
		return false;
	}
	else {
		return searchStep(0, data);
	}
}

int BinaryTree::min() {
	if (_data[0] == EMPTY) {
		return EMPTY;
	}
	else {
		return minStep(0);
	}
}

int BinaryTree::max() {
	if (_data[0] == EMPTY) {
		return EMPTY;
	}
	else {
		return maxStep(0);
	}
}

void BinaryTree::inorder() {
	if (_data[0] != EMPTY) {
		inorder(0);
	}
}
		
void BinaryTree::preorder() {
	if (_data[0] != EMPTY) {
		preorder(0);
	}
}
		
void BinaryTree::postorder() {
if (_data[0] != EMPTY) {
		postorder(0);
	}
}

void BinaryTree::clear() {
	for (int i = 0; i<CAPACITY; i++) {
		_data[i] = EMPTY;
		_vacant[i] = false;
	}
}

bool BinaryTree::insertStep(int current, int data) {
	int currentData = _data[current];
	if (currentData > data) {
		int left = 2*current+1;
		if (_data[left] == EMPTY) {
			_data[left] = data;
			return true;
		}
		else {
			return insertStep(left,  data);
		}
	}
	else if (currentData < data) {
		int right = 2*current+2;
		if (_data[right] == EMPTY) {
			_data[right] = data;
			return true;
		}
		else {
			return insertStep(right,  data);
		}
	}
	else {
		if (_vacant[current]) {
			_vacant[current] = false;
			return true;
		}
		return false;
	}
}
		
bool BinaryTree::removeStep(int current, int data) {
	int currentData = _data[current];
	if (currentData > data) {
		int left = 2*current+1;
		if (_data[left] == EMPTY) {
			return false;
		}
		else {
			return removeStep(left,  data);
		}
	}
	else if (currentData < data) {
		int right = 2*current+2;
		if (_data[right] == EMPTY) {
			return false;
		}
		else {
			return removeStep(right,  data);
		}
	}
	else {
		if (!_vacant[current]) {
			_vacant[current] = true;
			return true;
		}
		return false;
	}
}
		
bool BinaryTree::searchStep(int current, int data) {
	int currentData = _data[current];
	if (currentData > data) {
		int left = 2*current+1;
		if (_data[left] == EMPTY) {
			return false;
		}
		else {
			return searchStep(left,  data);
		}
	}
	else if (currentData < data) {
		int right = 2*current+2;
		if (_data[right] == EMPTY) {
			return false;
		}
		else {
			return searchStep(right,  data);
		}
	}
	else {
		return !_vacant[current];
	}
}

int BinaryTree::minStep(int current) {
	int currentMin = _vacant[current] ? EMPTY : _data[current];

	int left = 2*current + 1;
	if (left >= CAPACITY) {
		return currentMin;
	}

	int leftMin = _data[left] == EMPTY ? EMPTY : minStep(left);

	int right = 2*current + 2;
	int rightMin = _data[right] == EMPTY ? EMPTY : minStep(right);

	if (leftMin == EMPTY && currentMin == EMPTY) {
		return rightMin;
	}

	if (leftMin == EMPTY) {
		return currentMin;
	}
	
	return leftMin;
}

int BinaryTree::maxStep(int current) {
	int currentMax = _vacant[current] ? EMPTY : _data[current];
	int left = 2*current + 1;
	if (left >= CAPACITY) {
		return currentMax;
	}

	int leftMax = _data[left] == EMPTY ? EMPTY : maxStep(left);

	int right = 2*current + 2;
	int rightMax = _data[right] == EMPTY ? EMPTY : maxStep(right);

	

	if (currentMax == EMPTY && rightMax == EMPTY) {
		return leftMax;
	}

	if (rightMax == EMPTY) {
		return currentMax;
	}

	return rightMax;
}

void BinaryTree::inorder(int current) {
	int left = 2*current+1;
	if (left < CAPACITY) {
		if (left < CAPACITY &&_data[left] != EMPTY) {
			inorder(left);
		}
		if (!_vacant[current]) {
			std::cout << _data[current] << " ";
		}
		
		int right = 2*current+2;
		if (right < CAPACITY &&_data[right] != EMPTY) {
			inorder(right);
		}
	}
	else {
		if (!_vacant[current]) {
			std::cout << _data[current] << " ";
		}
	}
}
		
void BinaryTree::preorder(int current) {
	if (!_vacant[current]) {
		std::cout << _data[current] << " ";
	}

	int left = 2*current+1;
	if (left < CAPACITY) {
		if (_data[left] != EMPTY) {
			preorder(left);
		}
		int right = 2*current+2;
		if (_data[right] != EMPTY) {
			preorder(right);
		}
	}
}
		
void BinaryTree::postorder(int current) {
	int left = 2*current+1;
	if (left < CAPACITY) {
		if (_data[left] != EMPTY) {
			postorder(left);
		}
		int right = 2*current+2;
		if (_data[right] != EMPTY) {
			postorder(right);
		}
	}
	if (!_vacant[current]) {
		std::cout << _data[current] << " ";
	}
}