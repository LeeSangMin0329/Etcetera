#include <iostream>

using namespace std;

int max(int **arr, int width, int p);

int main(void) {

	int* arr[3];
	int width;

	cin >> width;

	arr[0] = new int[width];
	arr[1] = new int[width];
	arr[2] = new int[width];

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < width; i++) {
			cin >> arr[j][i];
		}
	}

	int* peb[4];
	peb[0] = new int[width];
	peb[1] = new int[width];
	peb[2] = new int[width];
	peb[3] = new int[width];

	for (int i = 0; i < 4; i++) {
		if (i == 3)
			peb[i][0] = arr[0][0] + arr[2][0];
		else
			peb[i][0] = arr[i][0];
	}

	for (int i = 1; i < width; i++) {
		for (int p = 0; p < 4; p++) {
			if (p == 3)
				peb[p][i] = max(peb, i - 1, p) + arr[0][i] + arr[2][i];
			else
				peb[p][i] = max(peb, i - 1, p) + arr[p][i];
		}

	}
	
	int m = peb[0][width-1];
	if (m < peb[1][width-1])
		m = peb[1][width-1];
	if (m < peb[2][width-1])
		m = peb[2][width-1];
	if (m < peb[3][width-1])
		m = peb[3][width-1];
	cout << m;

	return 0;
}

int max(int **arr, int width, int p) {
	int m = 0;
	if (p == 0) {
		m = arr[1][width];
		if (m < arr[2][width])
			m = arr[2][width];
		return m;
	}
	else if (p == 1) {
		m = arr[0][width];
		if (m < arr[2][width])
			m = arr[2][width];
		if (m < arr[3][width])
			m = arr[3][width];
		return m;
	}
	else if (p == 2) {
		
		m = arr[0][width];
		if (m < arr[1][width])
			m = arr[1][width];
		return m;
	}
	else if (p == 3) {
		m = arr[1][width];
		return m;
	}
	
	return m;
}