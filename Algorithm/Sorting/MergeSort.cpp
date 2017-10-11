#include <iostream>

using namespace std;

class MergeSorting {
private:
	int tmp[10000];
	int *array;
	int sizeOfArray;

public:
	int complexityCount = 0;

	MergeSorting(int array[], int sizeOfArray) {
		this->sizeOfArray = sizeOfArray;
		this->array = array;
	}

	void Sorting() {
		MergeSort(array, 0, sizeOfArray-1);
	}

private:
	void MergeSort(int array[], int left, int right) {
		int middle = (left + right) / 2;;

		if (left < right) {
			MergeSort(array, left, middle);
			MergeSort(array, middle + 1, right);

			Merge(array, left, middle, right);
		}

	}

	void Merge(int array[], int left, int middle, int right) {
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

		cout << "left " << left << " right " << right << endl;
		for (int i = 0; i < sizeOfArray; i++) {
			cout << array[i] << " ";
		}
		cout << endl << endl;
	}
};

int main(void) {
	int sizeOfArray;
	int array[10000];

	cin >> sizeOfArray;
	for (int i = 0; i < sizeOfArray; i++) {
		cin >> array[i];
	}

	MergeSorting mergesortInstance = MergeSorting(array, sizeOfArray);
	mergesortInstance.Sorting();

	for (int i = 0; i < sizeOfArray; i++)
		cout << array[i] << " ";
	cout << endl;

	
	cout << mergesortInstance.complexityCount;

}