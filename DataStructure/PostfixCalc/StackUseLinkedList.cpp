#include <iostream>
#include <assert.h>

#include "StackUseLinkedList.h"

using namespace std;

StackUseLinkedList::StackUseLinkedList() {
	buffer = new ListP();
}

StackUseLinkedList::~StackUseLinkedList() {
	delete(buffer);
}

int StackUseLinkedList::Count() {
	return buffer->Length();
}

bool StackUseLinkedList::isEmpty() {
	if (buffer->Length() == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool StackUseLinkedList::Pop(double* outItem) {
	assert(outItem != NULL); // NULL love

	if (buffer->Length() == 0) {
		cout << "stack is empty" << endl;
		return false;
	}
	else {
		buffer->SearchIndex(0, outItem);
		buffer->Delete(0);
	}
	return true;
}

bool StackUseLinkedList::Push(double item) {
	buffer->Insert(0, item);
	return true;
}

void StackUseLinkedList::PrintStack() {
	buffer->PrintList();
}
