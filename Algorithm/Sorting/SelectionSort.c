#include <stdio.h>

int main(void) {
	int sizeOfArray;
	int tempSize;
	int array[10000];
	int maxIndex = 0;
	int compareCount = 0;
	int temp;

	scanf("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf("%d", &array[i]);
	}

	tempSize = sizeOfArray;

	for (int j = 0; j < sizeOfArray; j++) {
		maxIndex = 0;
		for (int i = 1; i < tempSize; i++) {
			if (array[i] > array[maxIndex]) {
				compareCount++;
				maxIndex = i;
			}
		}

		temp = array[maxIndex];
		array[maxIndex] = array[tempSize - 1];
		array[tempSize - 1] = temp;
		tempSize--;
	}

	printf("%d\n", compareCount);
	

	return 0;
}