#include "cBinarySearchTree.h"

template <typename T>
void cBinarySearchTree<T>::treeInsert(T x) {
	root = treeInsert(root, x);
}


template <typename T>
void cBinarySearchTree<T>::treeDelete(T t) {
	cNode<T>* r = root;
	cNode<T>* p = 0;

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
	if (t == NULL) {
		root = new cNode<T>(x);
	}

	if (t->key < x) {
		if (t->right != NULL) {
			treeInsert(t->right, x);
		}
		else {
			t->right = new cNode<T>(x);
		}
	}
	else if (t->key > x) {
		if (t->left != NULL) {
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
	else if(r == p->right) {
		p->right = deleteNode(r);
	}
}

template <typename T>
cNode<T>* cBinarySearchTree<T>::deleteNode(cNode<T>* r) {
	cNode<T>* s;
	cNode<T>* parent;

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
		cNode s = r->right;
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
		cout << "\t";
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