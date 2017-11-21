#include <stdio.h>

void HeapSorting(int * array, int sizeOfArray);
void Max_heap(int* array, int sizeOfArray);
void Heapify(int *array, int rootIndex, int sizeOfArray);

static int ComplexityCount = 0;

int main(void) {
	int array[10000];
	int sizeOfArray;

	scanf("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf("%d", &array[i]);
	}

	HeapSorting(array, sizeOfArray);

	return 0;
}

void HeapSorting(int * array, int sizeOfArray) {
	int temp;
	int complxTemp;

	Max_heap(array, sizeOfArray);
	complxTemp = ComplexityCount;
	
	for (int i = sizeOfArray - 1; i > 0; i--) {
		
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		
		Heapify(array, 0, i);
	}
	ComplexityCount -= complxTemp;
	printf("%d", ComplexityCount);
}

void Max_heap(int* array, int sizeOfArray) {
	for (int i = sizeOfArray / 2; i >= 0; i--) {
		Heapify(array, i, sizeOfArray);
	}
}

void Heapify(int *array, int rootIndex, int sizeOfArray) {
	int left = rootIndex * 2 + 1;
	int right = rootIndex * 2 + 2;
	int bigger, temp;

	if (right < sizeOfArray) {
		if (array[left] <= array[right])
			bigger = right;
		else
			bigger = left;
	}
	else if (left < sizeOfArray) {
		bigger = left;
	}
	else
		return;

	if (array[bigger] > array[rootIndex]) {
		ComplexityCount++;

		temp = array[rootIndex];
		array[rootIndex] = array[bigger];
		array[bigger] = temp;
		Heapify(array, bigger, sizeOfArray);
	}
	
}