#include<iostream>

class MaxHeap {

public:
		static const int EMPTY = -10000;
		
		MaxHeap();
    ~MaxHeap();
		
		void heapify(int* arr, int n);
    void push(int a);
		int pop();
		int peek();
		void clear();
		void print();

private:
		static const int CAPACITY = 131071;
    int* _data;
		int size;
		
		void siftUp(int a);
		void siftDown(int a);
};
