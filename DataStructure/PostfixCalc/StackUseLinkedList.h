#ifndef __STACKUSELINKEDLIST
#define __STACKUSELINKEDLIST
#include "ListPinCpp.h"

class StackUseLinkedList {
private:
	ListP* buffer;

public:
	StackUseLinkedList();
	~StackUseLinkedList();
	bool Pop(double* outItem);
	bool Push(double item);
	bool isEmpty();
	int Count();
	void PrintStack();
};

#endif // !__STACKUSELINKEDLIST
