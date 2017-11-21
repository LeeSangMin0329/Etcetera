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

	// ������ ���� �ڵ� ���� ������� �ϸ� Ʋ���ϴ�. ���� �ٲ�ߵǿ�
	for (int i = sizeOfArray - 1; i >= 0; i--) {
		arrayValueCount[array[i] - arrayMinValue]--; // <-- �ֶ� C[A[j]-min]--
		arrayResult[arrayValueCount[array[i] - arrayMinValue]] = array[i]; // <-- �� B[C[A[j]-min] = A[j]
	}
	// ---------------
	
	return 0;
}