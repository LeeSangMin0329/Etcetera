#include <stdio.h>
#include <math.h>

int partitionByMedian(int * array, int left, int right, int medianValue);
int LinearSelect(int* array, int left, int right, int fromTheSmallest);
int Select(int * array, int left, int right, int fromTheSmallest);
int Partition(int* array, int left, int right);
void swapInt(int* a, int* b);

int main(void) {
	int sizeOfArray;
	int array[10000];
	int fromTheSmallest;
	

	scanf("%d", &sizeOfArray);
	scanf("%d", &fromTheSmallest);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf("%d", &array[i]);
	}

	LinearSelect(array, 0, sizeOfArray - 1, fromTheSmallest);
	
	return 0;
}


int partitionByMedian(int * array, int left, int right, int medianValue) {
	int i;
	
	for (i = left; i <= right; i++) {
		if (array[i] == medianValue)
			break;
	}

	swapInt(&array[i], &array[right]);

	return Partition(array, left, right);
}

int LinearSelect(int* array, int left, int right, int fromTheSmallest) {
	int M, pivot;
	int* ceilArray;
	
	if (right - left + 1 <= 5) {
		int temp = Select(array, left, right, fromTheSmallest);
		return temp;
	}

	int ceilSize = ceil((right - left + 1) / (double)5);

	ceilArray = (int*)malloc(sizeof(int) * ceilSize);

	int ceilIndex = 0;
	for (int i = left; i <= right; i += 5) {

		if (right - i + 1 < 5) {
			if(right - i + 1 == 1)
				ceilArray[ceilIndex++] = array[i];
			else if(right - i + 1 == 2)
				ceilArray[ceilIndex++] = Select(array, i, i + 1, 1);
			else if(right - i + 1 == 3)
				ceilArray[ceilIndex++] = Select(array, i, i + 2, 2);
			else if(right - i + 1 == 4)
				ceilArray[ceilIndex++] = Select(array, i, i + 3, 2);
		}
		else
			ceilArray[ceilIndex++] = Select(array, i, i + 4, 3);
	}

	M = LinearSelect(ceilArray, 0, ceilSize - 1, ceil(ceilSize / (double)2));
	printf("%d\n", M);

	free(ceilArray);

	int k;
	pivot = partitionByMedian(array, left, right, M);
	k = pivot - left + 1;
	if (fromTheSmallest < k)
		return LinearSelect(array, left, pivot - 1, fromTheSmallest);
	else if (fromTheSmallest > k)
		return LinearSelect(array, pivot + 1, right, fromTheSmallest - k);
	else
		return array[pivot];

}


// select----------------------------------------------------

int Select(int * array, int left, int right, int fromTheSmallest) {
	int pivot;
	int k;
	if (left == right)
		return array[left];

	pivot = Partition(array, left, right);
	k = pivot - left + 1;
	if (fromTheSmallest < k)
		return Select(array, left, pivot - 1, fromTheSmallest);
	else if (fromTheSmallest > k)
		return Select(array, pivot + 1, right, fromTheSmallest - k);
	else
		return array[pivot];

}

int Partition(int* array, int left, int right) {
	int x = array[right];
	int i = left - 1;
	for (int j = left; j <= right-1; j++) {
		if (array[j] <= x)
			swapInt(&array[++i], &array[j]);
	}
	swapInt(&array[i + 1], &array[right]);
	
	return i + 1;
}

void swapInt(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}