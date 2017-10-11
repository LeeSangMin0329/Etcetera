#include <iostream>

#define MAX 9999999

using namespace std;

// linear
int ExtraMin(bool* selected, int* dist, int numofvertex) {
	int min;
	for (int i = 0; i < numofvertex; i++) {
		if (!selected[i]) {
			min = i;
			break;
		}
	}

	for (int i = 0; i < numofvertex; i++) {
		if (!selected[i] && (dist[i] < dist[min]))
			min = i;
	}

	return min;
}

int main(void) {
	int** arr;
	int numOfVertex;
	int numOfEdge;
	int srt, dst, weight;
	bool* selected;
	int* dist;

	cin >> numOfVertex >> numOfEdge;

	arr = new int*[numOfVertex];
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
		arr[srt-1][dst-1] = weight;
		arr[dst - 1][srt - 1] = weight;
	}
	
	for (int i = 0; i < numOfVertex; i++) {
		dist[i] = MAX;
		selected[i] = false;
	}
	

	int u;
	dist[0] = 0;
	for (int i = 0; i < numOfVertex; i++) {
		u = ExtraMin(selected, dist, numOfVertex);
		selected[u] = true;

		if (dist[u] == MAX)
			break;

		cout << u + 1 << " ";

		for (int j = 0; j < numOfVertex; j++) {
			if (arr[u][j] != MAX) {
				if (!selected[j] && arr[u][j] < dist[j])
					dist[j] = arr[u][j];
			}
		}
	}
	
	int sum = 0;
	for (int i = 0; i < numOfVertex; i++)
		sum += dist[i];

	cout << sum;

	return 0;
}

