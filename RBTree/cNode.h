#pragma once

#ifndef __CNODE__
#define __CNODE__

#include <iostream>

#define RED (0)
#define BLACK (1)

class cNode {
	friend class cRedBlackTree;

public:
	cNode() { left = NULL; right = NULL; parent = NULL; key = NULL; color = 0; }
	
	cNode* left;
	cNode* right;
	cNode* parent;

	void* key;
	int color;
};



#endif // !__CONDE__
