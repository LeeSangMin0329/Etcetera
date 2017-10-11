#include "cRedBlackTree.h"

cRedBlackTree::~cRedBlackTree() {}
cRedBlackTree::cRedBlackTree() { root = NULL; nil = NULL; }

void cRedBlackTree::treePrint() {
	PreorderPrint(root, 0);
}

void cRedBlackTree::PreorderPrint(cNode* r, int step) {
	if (r == NULL)
		return;
	for (int i = 0; i < step; i++)
		cout << "    ";
	if (r->color == BLACK)
		cout << "BLACK ";
	else if (r->color == RED)
		cout << "RED ";
	cout << (int)r->key << endl;
	PreorderPrint(r->left, step + 1);
	PreorderPrint(r->right, step + 1);
}

int compareInt(void* left, void* right) {
	int leftint = (int)left;
	int rightint = (int)right;
	if (leftint < rightint)
		return -1;
	else if (leftint > rightint)
		return 1;
	else {
		//assert(leftint == rightint);
		return 0;
	}
}

void cRedBlackTree::treeInsert(int d) {
	rbtreeInsert((void*)d, compareInt);
}

void cRedBlackTree::treeDelete(int d) {
	rbtreeDelete((void*)d, compareInt);
}

cNode* cRedBlackTree::grandParent(cNode* n) {
	//assert(n != NULL);
	//assert(n->parent != NULL);
	//assert(n->parent->parent != NULL);
	return n->parent->parent;
}

cNode* cRedBlackTree::sibling(cNode* n) {
	//assert(n != NULL);
	//assert(n->parent != NULL);
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}

cNode* cRedBlackTree::uncle(cNode* n)
{
	//assert(n != NULL);
	//assert(n->parent != NULL);
	//assert(n->parent->parent != NULL);
	return sibling(n->parent);
}

int cRedBlackTree::nodeColor(cNode* n) {
	return n == NULL ? BLACK : n->color;
}

cNode* cRedBlackTree::newNode(void* key, int color, cNode* left, cNode* right) {
	cNode* result = new cNode();
	result->key = key;
	result->color = color;
	result->left = left;
	result->right = right;
	if (left != NULL)
		left->parent = result;
	if (right != NULL)
		right->parent = result;
	result->parent = NULL;
	return result;
}

cNode* cRedBlackTree::lookupNode(void* key, compare_func compare) {
	cNode* n = root;
	while (n != NULL) {
		int comp_result = compare(key, n->key);
		if (comp_result == 0)
		{
			return n;
		}
		else if (comp_result < 0)
		{
			n = n->left;
		}
		else
		{
			//assert(comp_result > 0);
			n = n->right;
		}
	}
	return n;
}

void cRedBlackTree::rotateLeft(cNode* n) {
	cNode* r = n->right;
	replaceNode(n, r);
	n->right = r->left;
	if (r->left != NULL)
	{
		r->left->parent = n;
	}
	r->left = n;
	n->parent = r;
}

void cRedBlackTree::rotateRight(cNode* n) {
	cNode* l = n->left;
	replaceNode(n, l);
	n->left = l->right;
	if (l->right != NULL)
	{
		l->right->parent = n;
	}
	l->right = n;
	n->parent = l;
}

void cRedBlackTree::replaceNode(cNode* oldn, cNode* newn) {
	if (oldn->parent == NULL)
	{
		newn->color = BLACK;
		root = newn;
	}
	else
	{
		if (oldn == oldn->parent->left)
			oldn->parent->left = newn;
		else
			oldn->parent->right = newn;
	}
	if (newn != NULL)
	{
		newn->parent = oldn->parent;
	}
}

void cRedBlackTree::rbtreeInsert(void* key, compare_func compare)
{
	cNode* inserted_node = newNode(key, RED, NULL, NULL);
	if (root == NULL)
	{
		root = inserted_node;
	}
	else
	{
		cNode* n = root;
		while (true)
		{
			int comp_result = compare(key, n->key);
			if (comp_result == 0)
			{
				return;
			}
			else if (comp_result < 0)
			{
				if (n->left == NULL)
				{
					n->left = inserted_node;
					break;
				}
				else
				{
					n = n->left;
				}
			}
			else
			{
				//assert(comp_result > 0);
				if (n->right == NULL)
				{
					n->right = inserted_node;
					break;
				}
				else
				{
					n = n->right;
				}
			}
		}
		inserted_node->parent = n;
	}
	insertCase1(inserted_node);
}

void cRedBlackTree::insertCase1(cNode* n) {
	if (n->parent == NULL)
		n->color = BLACK;
	else
		insertCase2(n);
}

void cRedBlackTree::insertCase2(cNode* n) {
	if (nodeColor(n->parent) == BLACK)
		return;
	else
		insertCase3(n);
}

void cRedBlackTree::insertCase3(cNode* n) {
	if (nodeColor(uncle(n)) == RED)
	{
		n->parent->color = BLACK;
		uncle(n)->color = BLACK;
		grandParent(n)->color = RED;
		insertCase1(grandParent(n));
	}
	else
	{
		insertCase4(n);
	}
}

void cRedBlackTree::insertCase4(cNode* n) {
	if (n == n->parent->right && n->parent == grandParent(n)->left)
	{
		rotateLeft(n->parent);
		n = n->left;
	}
	else if (n == n->parent->left && n->parent == grandParent(n)->right)
	{
		rotateRight(n->parent);
		n = n->right;
	}
	insertCase5(n);
}

void cRedBlackTree::insertCase5(cNode* n) {
	n->parent->color = BLACK;
	grandParent(n)->color = RED;
	if (n == n->parent->left && n->parent == grandParent(n)->left)
	{
		rotateRight(grandParent(n));
	}
	else
	{
		//assert(n == n->parent->right && n->parent == grandParent(n)->right);
		rotateLeft(grandParent(n));
	}
}

void cRedBlackTree::rbtreeDelete(void* key, compare_func compare) {
	cNode* child;
	cNode* n = lookupNode(key, compare);
	if (n == NULL)
		return;
	if (n->left != NULL && n->right != NULL)
	{
		cNode* pred = maximumNode(n->right);
		n->key = pred->key;
		n = pred;
	}
	//assert(n->left == NULL || n->right == NULL);
	child = n->right == NULL ? n->left : n->right;
	if (nodeColor(n) == BLACK)
	{
		n->color = nodeColor(child);
		deleteCase1(n);
	}
	replaceNode(n, child);
	free(n);
}

void cRedBlackTree::deleteCase1(cNode* n) {
	if (n->parent == NULL) {
		return;
	}
	else
		deleteCase2(n);
}

void cRedBlackTree::deleteCase2(cNode* n) {
	if (nodeColor(sibling(n)) == RED)
	{
		n->parent->color = RED;
		sibling(n)->color = BLACK;
		if (n == n->parent->left)
			rotateLeft(n->parent);
		else
			rotateRight(n->parent);
	}
	deleteCase3(n);
}

void cRedBlackTree::deleteCase3(cNode* n) {
	if (nodeColor(n->parent) == BLACK && nodeColor(sibling(n)) == BLACK &&
		nodeColor(sibling(n)->left) == BLACK && nodeColor(sibling(n)->right) == BLACK)
	{
		sibling(n)->color = RED;
		deleteCase1(n->parent);
	}
	else
		deleteCase4(n);
}

void cRedBlackTree::deleteCase4(cNode* n)
{
	if (nodeColor(n->parent) == RED && nodeColor(sibling(n)) == BLACK &&
		nodeColor(sibling(n)->left) == BLACK && nodeColor(sibling(n)->right) == BLACK)
	{
		sibling(n)->color = RED;
		n->parent->color = BLACK;
	}
	else
		deleteCase5(n);
}

void cRedBlackTree::deleteCase5(cNode* n) {
	if (n == n->parent->left && nodeColor(sibling(n)) == BLACK &&
		nodeColor(sibling(n)->left) == RED && nodeColor(sibling(n)->right) == BLACK)
	{
		sibling(n)->color = RED;
		sibling(n)->left->color = BLACK;
		rotateRight(sibling(n));
	}
	else if (n == n->parent->right && nodeColor(sibling(n)) == BLACK &&
		nodeColor(sibling(n)->right) == RED && nodeColor(sibling(n)->left) == BLACK)
	{
		sibling(n)->color = RED;
		sibling(n)->right->color = BLACK;
		rotateLeft(sibling(n));
	}
	deleteCase6(n);
}

void cRedBlackTree::deleteCase6(cNode* n) {
	sibling(n)->color = nodeColor(n->parent);
	n->parent->color = BLACK;
	if (n == n->parent->left)
	{
		//assert(nodeColor(sibling(n)->right) == RED);
		sibling(n)->right->color = BLACK;
		rotateLeft(n->parent);
	}
	else
	{
		//assert(nodeColor(sibling(n)->left) == RED);
		sibling(n)->left->color = BLACK;
		rotateRight(n->parent);
	}
}

cNode* cRedBlackTree::maximumNode(cNode* n) {
	//assert(n != NULL);
	while (n->left != NULL)
	{
		n = n->left;
	}
	return n;
}