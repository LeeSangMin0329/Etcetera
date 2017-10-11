#include <iostream>

#define MAX 9999999

using namespace std;

int main(void) {
	int** arr;
	int numOfVertex;
	int numOfEdge;
	int srt, dst, weight;
	bool* selected;
	int* dist;

	cin >> numOfVertex >> numOfEdge;

	arr = new int*[++numOfVertex];
	for (int i = 0; i < numOfVertex; i++) {
		arr[i] = new int[numOfVertex];
	}
	for (int i = 0; i < numOfVertex; i++)
		for (int j = 0; j < numOfVertex; j++)
			arr[i][j] = MAX;

	selected = new bool[numOfVertex];
	dist = new int[numOfVertex];

	for (int i = 0; i < numOfEdge; i++) {
		cin >> srt >> dst >> weight;
		arr[srt][dst] = weight;
	}

	for (int i = 0; i < numOfVertex; i++) {
		dist[i] = MAX;
		selected[i] = false;
	}

	int* prev = new int[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
		prev[i] = 0;

	int startVertex, dstVertex;
	cin >> startVertex >> dstVertex;

	int u;
	dist[startVertex] = 0;

	int min;
	for (int i = 1; i < numOfVertex; i++) {
		min = MAX;

		for (int j = 1; j < numOfVertex; j++) {
			if (!selected[j] && min > dist[j]) {
				min = dist[j];
				u = j;
			}
		}

		selected[u] = true;

		for (int j = 1; j < numOfVertex; j++) {
			if (dist[j] > dist[u] + arr[u][j]) {
				dist[j] = dist[u] + arr[u][j];
				prev[j] = u;
			}
			
		}
	}

	for (int i = 1; i < numOfVertex; i++)
		cout << prev[i] << " ";

	if (dist[dstVertex] == MAX)
		cout << "Impossible";
	else
		cout << dist[dstVertex];

	return 0;
}

