#include <stdio.h>

int main(void) {
	int array[10000];
	int sizeOfArray;
	int temp;
	int complexityCount = 0;
	
	scanf_s("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf_s("%d", &array[i]);
	}

	for (int pivot = 1;pivot < sizeOfArray; pivot++) {
		temp = array[pivot];
		for (int i = pivot; i > 0; i--) {
			if (array[i - 1] > temp) {
				complexityCount++;
				array[i] = array[i - 1];
				if (i == 1) {
					array[0] = temp;
					complexityCount++;
				}
			}
			else {
				complexityCount++;
				array[i] = temp;
				break;
			}
		}
	}

	for (int i = 0;i < sizeOfArray; i++) {
		printf("%d ", array[i]);
	}
	printf("%d", complexityCount);

	return 0;
}