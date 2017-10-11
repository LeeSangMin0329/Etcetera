#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	int** arr;
	int numOfVertex, numOfEdge;
	int srt, dst;
	bool* visit;

	cin >> numOfVertex >> numOfEdge;

	arr = new int*[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
		arr[i] = new int[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
		for (int j = 0; j < numOfVertex; j++)
			arr[i][j] = 0;

	visit = new bool[numOfVertex];
	for (int i = 0; i < numOfVertex; i++)
		visit[i] = false;

	for (int i = 0; i < numOfEdge; i++) {
		cin >> srt >> dst;
		arr[srt-1][dst-1] = 1;
		arr[dst-1][srt-1] = 1;
	}

	int startVertex;

	cin >> startVertex;

	q.push(startVertex - 1);
	visit[startVertex - 1] = true;
	cout << startVertex << " ";

	int node;
	while (true) {
		if (q.empty())
			break;
		else {
			node = q.front();
			q.pop();
		}
		
		for (int j = 0; j < numOfVertex; j++) {
			if (arr[node][j] && !visit[j]) {
				visit[j] = true;
				q.push(j);
				cout << j + 1 << " ";
			}
		}

	}



	return 0;
}