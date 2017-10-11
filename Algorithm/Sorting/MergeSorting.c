#include <stdio.h>
#include <stdlib.h>

void MergeSorting(int* array, int left, int right);
void Merge(int* array, int left, int middle, int right);

int main(void) {
	int array[10000];
	int sizeOfArray;

	scanf_s("%d", &sizeOfArray);
	for (int i = 0;i < sizeOfArray;i++) {
		scanf_s("%d", &array[i]);
	}

	printf("%d\n", sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		printf("%d ", array[i]);
	}


	MergeSorting(array, 0, sizeOfArray);

	

	return 0;
}

void MergeSorting(int* array, int left, int right) {
	int middle;

	if (left < right) {
		middle = (left + right) / 2;
		
		MergeSorting(array, left, middle);
		MergeSorting(array, middle+1, right);

		Merge(array, left, middle, right);
	}

}

void Merge(int* array, int left, int middle, int right) {
	int i = left;
	int j = middle;
	int t = 0;
	int* tmp = (int*)malloc(sizeof(int)*(right - left + 1));
	
	while (i < middle && j < right) {
		if (array[i] < array[j]) {
			tmp[t++] = array[i++];
		}
		else {
			tmp[t++] = array[j++];
		}
	}
	while (i < middle) {
		tmp[t++] = array[i++];
	}
	while (j < right) {
		tmp[t++] = array[j++];
	}

	i = left;
	t = 0;
	while (i < right) {
		array[i++] = tmp[t++];
	}
	free(tmp);
}