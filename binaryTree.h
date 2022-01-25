#include<iostream>

class BinaryTree {

public:
		static const int EMPTY = -10000;
		
    BinaryTree();
    ~BinaryTree();
		
    bool insert(int data);
    bool remove(int data);
		bool search(int data);
		int min();
		int max();
		void inorder();
		void preorder();
		void postorder();
    void clear();

private:
		static const int CAPACITY = 131071;
    int* _data;
		bool* _vacant;
		
		bool insertStep(int curr, int data);
		bool removeStep(int curr, int data);
		bool searchStep(int curr, int data);
		int minStep(int curr);
		int maxStep(int curr);

		void inorder(int curr);
		void preorder(int curr);
		void postorder(int curr);
};
