#pragma once

#ifndef __CREDBLACKTREE__
#define __CREDBLACKTREE__

#include "cNode.h"
#include <iostream>
//#include <cassert>
using namespace std;

class cRedBlackTree {
public:
	cRedBlackTree();
	~cRedBlackTree();
	void treeInsert(int d);
	void treeDelete(int d);
	void treePrint();
private:
	cNode* root;
	cNode* nil;

	

	void PreorderPrint(cNode* node, int step);

	typedef int(*compare_func) (void* left, void* right);
	cNode* grandParent(cNode* n);
	cNode* sibling(cNode* n);
	cNode* uncle(cNode* n);
	int nodeColor(cNode* n);
	cNode* lookupNode(void* key, compare_func compare);
	cNode* newNode(void* key, int color, cNode* left, cNode* right);
	void rotateLeft(cNode* n);
	void rotateRight(cNode* n);
	void replaceNode(cNode* oldn, cNode* newn);
	void rbtreeInsert(void* key, compare_func compare);
	void insertCase1(cNode* n);
	void insertCase2(cNode* n);
	void insertCase3(cNode* n);
	void insertCase4(cNode* n);
	void insertCase5(cNode* n);

	void rbtreeDelete(void* key, compare_func compare);
	void deleteCase1(cNode* n);
	void deleteCase2(cNode* n);
	void deleteCase3(cNode* n);
	void deleteCase4(cNode* n);
	void deleteCase5(cNode* n);
	void deleteCase6(cNode* n);
	cNode* maximumNode(cNode*);
};

#endif // !__CREDBLACKTREE__
