#include <iostream>

using namespace std;

int main(void) {
	int width, height;
	int *arr;

	cin >> width >> height;

	arr = new int[width * height];

	for (int i = 0; i < width*height; i++)
		cin >> arr[i];

	for (int i = 1; i < width; i++) {
		arr[i] += arr[(i - 1)];
	}

	for (int i = 1; i < height; i++) {
		arr[i * width] += arr[(i - 1) * width];
	}
	
	for (int i = 1; i < height; i++) {
		for (int j = 1; j < width; j++) {
			if (arr[i*width + (j - 1)] > arr[(i - 1)*width + j])
				arr[i*width + j] += arr[(i - 1)*width + j];
			else
				arr[i*width + j] += arr[i*width + (j - 1)];
		}
	}
	
	cout << arr[width * height - 1];

	return 0;
}