#include <iostream>

using namespace std;

int main(void) {
	int** graph;
	int* colorArr;
	int vertexNum, edgeNum, colorNum;

	cin >> vertexNum >> edgeNum >> colorNum;

	graph = new int*[vertexNum];
	for (int i = 0; i < vertexNum; i++) {
		graph[i] = new int[vertexNum];
	}

	for (int i = 0; i < vertexNum; i++)
		for (int j = 0; j < vertexNum; j++)
			graph[i][j] = 0;

	colorArr = new int[vertexNum];
	for (int i = 0; i < vertexNum; i++) {
		colorArr[i] = -1;
	}

	int from, to;
	for (int i = 0; i < edgeNum; i++) {
		cin >> from >> to;
		graph[from-1][to-1] = 1;
		graph[to-1][from-1] = 1;
	}

	int count = 0;
	
	for (int i = 0; i < vertexNum; i++) {
		colorArr[i] = 0;
		cout << "(" << i + 1 << ", " << colorArr[i] + 1 << ")" << endl;
		for (int j = 0; j < vertexNum; j++) {
			if (graph[i][j] == 1) {
				count = 0;
				while (true) {
					if (++count > colorNum - 1) {
						cout << "impossible" << endl;
						return 0;
					}
					if (colorArr[i] == colorArr[j]) {
						colorArr[i] = (colorArr[i] + 1) % colorNum;
						cout << "(" << i + 1 << ", " << colorArr[i] + 1 << ")" << endl;
					}
					else
						break;
				}
			}
		}
	}

	cout << "possible" << endl;
		


	return 0;
}