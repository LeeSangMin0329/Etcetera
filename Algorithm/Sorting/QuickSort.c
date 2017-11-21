#include <stdio.h>
int quickSort(int* array, int left, int right);
int partition(int *A, int p, int r);

static int ComplexityCount = 0;

int main(void) {
	int array[10000];
	int sizeOfArray;

	scanf_s("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf_s("%d", &array[i]);
	}

	quickSort(array, 0, sizeOfArray);

	printf("%d ", ComplexityCount);

	return 0;
}

int quickSort(int* array, int left, int right) {
	if (abs(right - left) < 2)
		return 1;

	int pivot = partition(array, left, right);
	quickSort(array, left,  pivot);
	quickSort(array, pivot + 1, right);

	return 0;
}

int partition(int *A, int p, int r) {
	int x = A[r - 1];
	int i = p - 1;
	int temp;

	for (int j = p; j < r - 1; j++) {
		if (A[j] <= x) {
			ComplexityCount++;
			temp = A[j];
			A[j] = A[++i];
			A[i] = temp;
		}
	}

	ComplexityCount++;
	temp = A[i + 1];
	A[i + 1] = A[r - 1];
	A[r - 1] = temp;

	return i + 1;
}
