#ifndef __LISTP
#define __LISTP

typedef struct node {
	int Data;
	struct node* Next;
}Node;

typedef struct {
	int Count;
	Node* Head;
}ListType;

void Insert(ListType* lptr, int position, int item);
void Delete(ListType* lptr, int position);
//void Retrieve(ListType* lptr, int position, int* itemPtr);
void Retrieve(ListType* lptr, int item);
void Init(ListType* lptr);
int Length(ListType* lptr);
void PrintList(ListType* lptr);
void Reverse(ListType* lptr);
void RandomAppend(ListType* lptr, int sizeOfElement);
void Destroy(ListType* lptr);


#endif // !__LISTP
