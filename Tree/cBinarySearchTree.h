#pragma once

#ifndef __CBINARYSEARCHTREE__
#define __CBINARYSEARCHTREE__


#include <iostream>
#include "cNode.h"

using namespace std;


template <typename T>
class cBinarySearchTree {
	friend class cNode<T>;
public:
	cBinarySearchTree();
	~cBinarySearchTree();
	void treeInsert(T x);
	void treeDelete(T x);
	void treePrint();

	int count = 0;

private:
	cNode<T>* treeInsert(cNode<T>* t, T x);
	void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p);
	cNode<T>* deleteNode(cNode<T>* r);
	void treePrint(cNode<T>* t, int step);
	cNode<T>* root;
};




// Template Body
template <typename T>
cBinarySearchTree<T>::cBinarySearchTree() {
	root = NULL;
}
template <typename T>
cBinarySearchTree<T>::~cBinarySearchTree() {
}

template <typename T>
void cBinarySearchTree<T>::treeInsert(T x) {
	root = treeInsert(root, x);
}


template <typename T>
void cBinarySearchTree<T>::treeDelete(T t) {
	if (root == NULL)
		return;

	cNode<T>* r = root;
	cNode<T>* p = NULL;

	while (true) {
		if (r->key == t) {
			break;
		}
		else if (r->key < t) {
			p = r;
			r = r->right;
		}
		else if (r->key > t) {
			p = r;
			r = r->left;
		}
	}

	if (r)
		treeDelete(root, r, p);
}


template <typename T>
cNode<T>* cBinarySearchTree<T>::treeInsert(cNode<T>* t, T x) {
	count++;
	if (t == NULL) {
		t = new cNode<T>(x);

		return t;
	}

	if (t->key < x) {
		if (t->right != NULL) {
			count++;
			treeInsert(t->right, x);
		}
		else {
			t->right = new cNode<T>(x);
		}
	}
	else if (t->key > x) {
		if (t->left != NULL) {
			count++;
			treeInsert(t->left, x);
		}
		else {
			t->left = new cNode<T>(x);
		}
	}

	return t;
}

template <typename T>
void cBinarySearchTree<T>::treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p) {
	if (r == t) {
		root = deleteNode(t);
	}
	else if (r == p->left) {
		p->left = deleteNode(r);
	}
	else if (r == p->right) {
		p->right = deleteNode(r);
	}
}

template <typename T>
cNode<T>* cBinarySearchTree<T>::deleteNode(cNode<T>* r) {
	cNode<T>* s;
	cNode<T>* parent = NULL;

	if (r->left == NULL && r->right == NULL) {
		return NULL;
	}
	else if (r->left == NULL && r->right != NULL) {
		return r->right;
	}
	else if (r->left != NULL && r->right == NULL) {
		return r->left;
	}
	else {
		s = r->right;
		while (s->left != NULL) {
			parent = s;
			s = s->left;
		}
		r->key = s->key;
		if (s == r->right) {
			r->right = s->right;
		}
		else {
			parent->left = s->right;
		}

		return r;
	}
}

template <typename T>
void cBinarySearchTree<T>::treePrint(cNode<T>* t, int step) {
	if (t == NULL)
		return;

	for (int i = 0; i < step; i++)
		cout << "    ";
	cout << t->key << endl;

	if (t->left != NULL)
		treePrint(t->left, step + 1);
	if (t->right != NULL)
		treePrint(t->right, step + 1);

}

template <typename T>
void cBinarySearchTree<T>::treePrint() {
	treePrint(root, 0);
}


#endif // !__CBINARYSEARCHTREE__
