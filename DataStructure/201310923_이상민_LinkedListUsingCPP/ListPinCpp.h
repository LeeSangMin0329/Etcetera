#ifndef __LISTPINCPP
#define __LISTPINCPP

class Node {
public:
	int Data;
	Node* Next;
	Node(int item) { Data = item; Next = NULL; }
};

class ListP {
public:
	ListP();
	~ListP();
	void Insert(int position, int item);
	void Delete(int position);
	int Length();
	void PrintList();
	void Reverse();
	void RandomAppend(int sizeOfElement);
	void Retrieve(int item);
	void DeDuplicate();

private:
	int Count;
	Node* Head;
};


#endif // !__LISTPINCPP
