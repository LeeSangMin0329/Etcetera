#ifndef __HEAP
#define __HEAP

class Heap {
public:
	Heap(int heapSize);
	~Heap();
	int Remove();
	void Add(int data);
	void DownHeap(int currentIndex);
	void PrintHeap();
	void PrintParent(int index);
	void PrintChild(int index);

private:
	int* array;
	int heapSize;
	int sizeOfArray;
};

#endif

