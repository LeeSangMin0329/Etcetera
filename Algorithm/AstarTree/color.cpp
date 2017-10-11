#include <iostream>

using namespace std;

int** graph;
int* colorArr;
int vertexNum, edgeNum, colorNum;

bool valid(int i, int c) {
	int j;
	for (j = 1; j <= i - 1; j++) {
		if (graph[i][j] != 0 && colorArr[j] == c)
			return false;
	}
	return true;
}

bool kColoring(int i, int c) {
	bool result;
	int d;

	cout << "(" << i << ", " << c << ")" << endl;

	if (valid(i, c)) {
		colorArr[i] = c;
		if (i == vertexNum) {
			return true;
		}
		else {
			result = false;
			d = 1;
			while (result == false && d <= colorNum) {
				result = kColoring(i + 1, d);
				d++;
			}
		}
		return result;
	}
	else if (i == vertexNum && c == colorNum) {
		cout << "impossible" << endl;
		exit(1);
	}
	else
		return false;
}


int main(void) {

	cin >> vertexNum >> edgeNum >> colorNum;

	if (colorNum == 0) {
		cout << "impossible" << endl;
		return 0;
	}

	graph = new int*[vertexNum+1];
	for (int i = 0; i < vertexNum+1; i++) {
		graph[i] = new int[vertexNum+1];
	}

	for (int i = 0; i < vertexNum+1; i++)
		for (int j = 0; j < vertexNum+1; j++)
			graph[i][j] = 0;

	colorArr = new int[vertexNum+1];
	for (int i = 0; i < vertexNum+1; i++) {
		colorArr[i] = -1;
	}

	int from, to;
	for (int i = 0; i < edgeNum; i++) {
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	if (kColoring(1, 1))
		cout << "possible" << endl;
	else
		cout << "impossible" << endl;


	return 0;
}

