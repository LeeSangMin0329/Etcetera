
#include <iostream> 
#include "cBinarySearchTree.h"


using namespace std;

int main() {
	char cmd;
	int n, x;

	cBinarySearchTree<int> tree;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		
		tree.treeInsert(x);
		
	}
	cout << tree.count;
	return 0;
}