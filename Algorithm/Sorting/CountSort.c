#include <stdio.h>

int main(void) {
	int array[10000];
	int sizeOfArray;
	int * arrayValueCount;
	int arrayMaxValue;
	int arrayMinValue;
	int k;
	int arrayResult[10000];

	scanf_s("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf_s("%d", &array[i]);
	}

	arrayMaxValue = array[0];
	arrayMinValue = array[0];
	for (int i = 1; i < sizeOfArray; i++) {
		if (arrayMaxValue < array[i])
			arrayMaxValue = array[i];
		if (arrayMinValue > array[i])
			arrayMinValue = array[i];
	}
	
	k = arrayMaxValue - arrayMinValue + 1;
	arrayValueCount = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++) {
		arrayValueCount[i] = 0;
	}
	
	for (int i = 0; i < sizeOfArray; i++) {
		arrayValueCount[array[i] - arrayMinValue]++;
	}
	

	for (int i = 1; i < k; i++) {
		arrayValueCount[i] = arrayValueCount[i] + arrayValueCount[i - 1];
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", arrayValueCount[i]);
	}

	// 교수님 여기 코드 순서 문제대로 하면 틀립니다. 순서 바꿔야되요
	for (int i = sizeOfArray - 1; i >= 0; i--) {
		arrayValueCount[array[i] - arrayMinValue]--; // <-- 애랑 C[A[j]-min]--
		arrayResult[arrayValueCount[array[i] - arrayMinValue]] = array[i]; // <-- 애 B[C[A[j]-min] = A[j]
	}
	// ---------------
	
	return 0;
}