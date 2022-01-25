#include <iostream>
#include "binaryTree.h"

#define N 11

using namespace std;


void showState(BinaryTree& t) {
	cout << "Inorder: ";
	t.inorder();
	cout << endl;
		
	cout << "Preorder: ";
	t.preorder();
	cout << endl;
		
	cout << "Postorder: ";
	t.postorder();
	cout << endl;

	cout << "Min: " << t.min() << endl;
	cout << "Max: " << t.max() << endl;
	cout << endl;

	for (int i = 0; i<N+1; i++) {
		cout << "Tree contains " << i << "? " << t.search(i) << endl;
	}
}

int main() {
	BinaryTree t;
	for (int i = 1; i<N; i++) {
		t.insert((7*i) % N);
	}

	cout << "------AFTER TREE CREATION------" << endl;
	showState(t);


	for (int i = 1; i<11; i++) {
		int toRemove = (3*i) % 11;
		t.remove(toRemove);
		cout << "------AFTER REMOVING " << toRemove <<  " ------" << endl;
		showState(t);
	}
}