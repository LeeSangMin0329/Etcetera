#include <stdio.h>

void InsertionSorting(int * array, int sizeOfArray);

static int complexityCount = 0;

int main(void) {

	int array[10000];
	int sizeOfArray;

	scanf("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf("%d", &array[i]);
	}

	InsertionSorting(array, sizeOfArray);

	
	printf("%d", complexityCount);
	

	return 0;
}

void InsertionSorting(int * array, int sizeOfArray) {
	int loc;
	int newItem;

	for (int i = 1; i < sizeOfArray; i++) {
		loc = i - 1;
		newItem = array[i];

		while (loc >= 0 && newItem < array[loc]) {
			complexityCount++;
			array[loc + 1] = array[loc];
			loc--;
		}
		complexityCount++;
		array[loc + 1] = newItem;
	}
}