// 고대문서?

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class RadixSorting {

private:
	int *array;
	int sizeOfArray;
	int digitMax;

public:
	RadixSorting(int array[], int sizeOfArray, int digitMax) {
		this->sizeOfArray = sizeOfArray;
		this->array = array;
		this->digitMax = digitMax;
	}

	void Sorting() {
		RadixSort(array, sizeOfArray, digitMax);
	}

private:
	void RadixSort(int array[], int sizeOfArray, int digitMax) {
		queue<int> DigitQueue[10];
		int temp;
		int pointer;

		for (int i = 1; i <= digitMax; i++) {
			for (int j = 0; j < sizeOfArray; j++) {
				temp = digit(array[j], i);
				DigitQueue[temp].push(array[j]);
			}
			pointer = 0;
			for (int j = 0; j < 10; j++) {
				while (!DigitQueue[j].empty()) {
					array[pointer++] = DigitQueue[j].front();
					DigitQueue[j].pop();
				}
			}
		}
	}

	int digit(int num, int digitNum) {
		for (int i = 1; i < digitNum; i++) {
			if(num != 0)
				num /= 10;
		}

		return num % 10;
	}
};


int main() {
	int sizeOfArray, digitMax;
	int array[10000];

	cin >> sizeOfArray >> digitMax;
	for (int i = 0; i < sizeOfArray; i++) {
		cin >> array[i];
	}

	RadixSorting RSortInstance = RadixSorting(array, sizeOfArray, digitMax);
	RSortInstance.Sorting();

	for (int i = 0; i < sizeOfArray; i++) {
		cout << array[i] << " ";
	}

	return 0;
}