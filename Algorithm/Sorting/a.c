#include <stdio.h>
void Merge(int *array, int left, int middle, int right);
void MergeSort(int *array, int left, int right);

static int complexityCount = 0;
static int tmp[10000];

void MergeSort(int *array, int left, int right) {
	int middle = (left + right) / 2;;

	if (left < right) {
		MergeSort(array, left, middle);
		MergeSort(array, middle + 1, right);

		Merge(array, left, middle, right);
	}

}

void Merge(int *array, int left, int middle, int right) {
	int i = left;
	int j = middle + 1;
	int t = left;

	while (i <= middle && j <= right) {
		complexityCount++;
		if (array[i] < array[j]) {
			tmp[t++] = array[i++];
		}
		else {
			tmp[t++] = array[j++];
		}


	}

	while (i <= middle)
		tmp[t++] = array[i++];
	while (j <= right)
		tmp[t++] = array[j++];

	i = left;
	t = left;
	while (i <= right)
		array[i++] = tmp[t++];


}



int main(void) {
	int sizeOfArray;
	int array[10000];

	scanf_s("%d", &sizeOfArray);
	for (int i = 0; i < sizeOfArray; i++) {
		scanf_s("%d", &array[i]);
	}

	MergeSort(array, 0, sizeOfArray - 1);

	printf("%d", complexityCount);


	return 0;
}