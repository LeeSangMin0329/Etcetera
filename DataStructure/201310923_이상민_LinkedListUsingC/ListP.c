#include <stdio.h>
#include <stdlib.h>
#include "ListP.h"

void Insert(ListType* lptr, int position, int item) {

	if ((position > lptr->Count) || (position < 0)) {
		printf("\nERROR : Position out of Range\n");
	}
	else {
		Node* p = (Node*)malloc(sizeof(Node));
		p->Data = item;
		p->Next = NULL;
		if (position == 0) {
			p->Next = lptr->Head;
			lptr->Head = p;
		}
		else {
			Node* temp = lptr->Head;
			int i;
			for (i = 0; i < (position - 1); i++) {
				temp = temp->Next;
			}
			p->Next = temp->Next;
			temp->Next = p;
		}
		lptr->Count++;
	}
}


void Delete(ListType* lptr, int position) {

	if (Length(lptr) <= 0) {
		printf("\nERROR : Deletion on Empty List\n");
	}
	else if (position > (lptr->Count - 1) || position < 0) {
		printf("\nERROR : Position out of Range\n");
	}
	else {
		Node* p;
		if (position == 0) {
			p = lptr->Head;
			lptr->Head = lptr->Head->Next;
		}
		else {
			int i;
			Node* temp = lptr->Head;
			for (i = 0; i < (position - 1); i++) {
				temp = temp->Next;
			}
			p = temp->Next;
			temp->Next = p->Next;
		}
		lptr->Count--;
		free(p);
	}
}


void Init(ListType* lptr) {
	lptr->Head = NULL;
	lptr->Count = 0;
}

int Length(ListType* lptr) {
	return lptr->Count;
}

void PrintList(ListType* lptr) {
	int i;

	if (lptr->Head == NULL) {
		printf("\nNOTICE : List is Empty\n");
		return;
	}

	Node* temp = lptr->Head;
	printf("\nNOTICE : Print List\n\n     %d -> ", temp->Data);

	for (i = 1; i < Length(lptr); i++) {
		temp = temp->Next;
		printf("%d -> ", temp->Data);
	}
	printf("NULL\n");
}

void Reverse(ListType* lptr) {
	Node* head;
	Node* newHead;
	Node* tempNewhead;
	
	head = lptr->Head;
	newHead = NULL;
	tempNewhead = NULL;

	while (head != NULL) {
		tempNewhead = newHead;
		newHead = head;
		head = head->Next;
		newHead->Next = tempNewhead;
	}

	lptr->Head = newHead;

}

void RandomAppend(ListType* lptr, int sizeOfElement) {
	srand(time(NULL));

	int i;
	for (i = 0; i < sizeOfElement; i++) {
		Insert(lptr, Length(lptr), rand());
	}
}

void Retrieve(ListType* lptr, int item) {
	Node* iter = lptr->Head;
	printf("\n");
	int i;
	int count = 0;
	for (i = 0; i < Length(lptr); i++) {
		if (iter->Data == item) {
			printf("NOTICE : position %d, item %d\n", i, iter->Data);
			count++;
		}
		iter = iter->Next;
	}
	if (count == 0) {
		printf("    No result\n");
	}
}

void Destroy(ListType* lptr) {
	while(Length(lptr)) {
		Delete(lptr, 0);
	}
}