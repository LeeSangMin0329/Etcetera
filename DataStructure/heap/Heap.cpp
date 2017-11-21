#include <iostream>
#include "Heap.h"

using namespace std;
Heap::Heap(int arraySize) {
	this->array = new int[arraySize];
	this->heapSize = 0;
	this->sizeOfArray = arraySize;
}

Heap::~Heap() {
	delete(array);
}

void Heap::PrintParent(int index) {
	if (index == 0) {
		cout << "this is root" << endl;
		return;
	}

	cout << array[(index - 1) / 2] << "(" << (index - 1) / 2 << ")" << "->"
		<< array[index] << "(" << index << ")" << endl;
}

void Heap::PrintChild(int index) {
	if (index * 2 + 1 >= heapSize) {
		cout << "no have child this node" << endl;
		return;
	}
	if (index * 2 + 1 < heapSize) {
		cout << array[index * 2 + 1] << "(" << index * 2 + 1 << ")<-";
	}
	cout << array[index] << "(" << index << ")";
	if (index * 2 + 2 < heapSize) {
		cout << "->" << array[index * 2 + 2] << "(" << index * 2 + 2 << ")";
	}
	cout << endl;
}

void Heap::PrintHeap() {
	cout << "node : " << heapSize << endl;
	for (int i = 0; i < heapSize; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int Heap::Remove() {
	if (heapSize == 0) {
		cout << "heap empty" << endl;
		// must do not return there but book give wrong code to me 
		return -1;
	}
	int temp = array[0];
	array[0] = array[heapSize - 1];
	heapSize--;
	DownHeap(0);

	return temp;
}

void Heap::Add(int data) {
	if (sizeOfArray <= heapSize) {
		cout << "heap is full" << endl;
		return;
	}
	array[heapSize] = data;
	int temp;
	int current = heapSize;
	int parent = (current - 1) / 2;
	while ((current != 0) && (array[current] > array[parent])) {
		temp = array[current];
		array[current] = array[parent];
		array[parent] = temp;
		current = parent;
		parent = (current - 1) / 2;
	}
	heapSize++;
}

void Heap::DownHeap(int currentIndex) {
	int left = currentIndex * 2 + 1;
	int right = currentIndex * 2 + 2;
	int bigger, temp;

	if (right < heapSize) {
		if (array[left] <= array[right])
			bigger = right;
		else
			bigger = left;
	}
	else if (left < heapSize) {
		bigger = left;
	}
	else
		return;

	if (array[bigger] > array[currentIndex]) {

		temp = array[currentIndex];
		array[currentIndex] = array[bigger];
		array[bigger] = temp;
		DownHeap(bigger);
	}

}