#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ListPinCpp.h"

using namespace std;

ListP::ListP() {
	this->Count = 0;
	this->Head = NULL;
}

ListP::~ListP() {
	while (Length()) {
		Delete(0);
	}
}

void ListP::Insert(int position, int item) {

	if ((position > Count) || (position < 0)) {
		cout << "\n\nERROR : Position out of Range\n";
	}
	else {
		Node* p = new Node(item);
		
		if (position == 0) {
			p->Next = Head;
			Head = p;
		}
		else {
			Node* temp = Head;
			for (int i = 0; i < position - 1; i++) {
				temp = temp->Next;
			}
			p->Next = temp->Next;
			temp->Next = p;
		}
		Count++;
	}
}

void ListP::Delete(int position) {

	if (Length() <= 0) {
		cout << "\nERROR : Deletion on Empty List\n";
	}
	else if(position > (Count - 1) || position < 0) {
		cout << "\nERROR : Position out of Range\n";
	}
	else {
		Node* p;
		if (position == 0) {
			p = Head;
			Head = Head->Next;
		}
		else {
			Node* temp = Head;
			for (int i = 1; i < position - 1; i++) {
				temp = temp->Next;
			}
			p = temp->Next;
			temp->Next = p->Next;
		}
		Count--;
		delete(p);
	}
}

int ListP::Length() {
	return Count;
}

void ListP::PrintList() {
	if (Head == NULL) {
		cout << "\nNOTICE : List is Empty\n";
		return;
	}

	Node* temp = Head;
	cout << "\nNOTICE : Print List\n\n     " << temp->Data << " -> ";

	for (int i = 0; i < Length() - 1; i++) {
		temp = temp->Next;
		cout << temp->Data << " -> ";
	}
	cout << "NULL\n";
}

void ListP::Reverse() {
	Node* head;
	Node* newHead;
	Node* tempNewHead;

	head = this->Head;
	newHead = NULL;
	tempNewHead = NULL;

	while (head != NULL) {
		tempNewHead = newHead;
		newHead = head;
		head = head->Next;
		newHead->Next = tempNewHead;
	}

	this->Head = newHead;
}

void ListP::RandomAppend(int sizeOfElement) {
	srand(static_cast<unsigned int>(time(NULL)));
	
	for (int i = 0; i < sizeOfElement; i++) {
		Insert(Length(), rand());
	}
}

void ListP::Retrieve(int item) {
	Node* iter = this->Head;
	int count = 0;
	cout << endl;
	for (int i = 0; i < Length(); i++) {
		if (iter->Data == item) {
			cout << "NOTICE : position " << i << ", item " << iter->Data << endl;
			count++;
		}
		iter = iter->Next;
	}
	if (count == 0) {
		cout << "    No result" << endl;
	}
}

void ListP::DeDuplicate() {
	Node* iterator;
	Node* comparisonTarget;
	Node* pointerToNodeDelete;

	iterator = this->Head;

	while (iterator != NULL) {
		comparisonTarget = iterator;
		while (comparisonTarget->Next != NULL) {

			if (comparisonTarget->Next->Data == iterator->Data) {

				pointerToNodeDelete = comparisonTarget->Next;
				comparisonTarget->Next = comparisonTarget->Next->Next;
				delete(pointerToNodeDelete);
				this->Count--;
			}
			else {
				comparisonTarget = comparisonTarget->Next;
			}
		}
		iterator = iterator->Next;
	}
}