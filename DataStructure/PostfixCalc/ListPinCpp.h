#ifndef __LISTPINCPP
#define __LISTPINCPP

class Node {
public:
	double Data;
	Node* Next;
	Node(double item) { Data = item; Next = NULL; }
};

class ListP {
public:
	ListP();
	~ListP();
	void Insert(int position, double item);
	void Delete(int position);
	int Length();
	void PrintList();
	void Reverse();
	void RandomAppend(int sizeOfElement);
	void Retrieve(double item);
	void DeDuplicate();
	bool SearchIndex(int index, double* outItem);

private:
	int Count;
	Node* Head;
};


#endif // !__LISTPINCPP
