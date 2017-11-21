#include <stdio.h>

int main(void) {

	int array[10000];
	int sizeOfArray;
	int tempSizeOfArray;
	int temp;
	int swapCount = 0;

	scanf("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf("%d", &array[i]);
	}

	tempSizeOfArray = sizeOfArray;
	for (int j = 0; j < sizeOfArray-2; j++) {
		for (int i = 0; i < tempSizeOfArray-1; i++) {
			if (array[i] > array[i + 1]) {
				swapCount++;
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
			}
		}
		tempSizeOfArray--;
	}

	printf("%d", swapCount);
	

	return 0;
}