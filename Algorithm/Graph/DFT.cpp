#include <iostream>

using namespace std;

void Dfs(int** arr, bool* visit, int numofvertex, int startvertex);

int main(void) {
	int** g;
	int numOfVertex;
	int numOfEdge;
	int stp, dst;
	int startVertex;
	bool *visit;

	cin >> numOfVertex >> numOfEdge;

	g = new int* [numOfVertex + 1];
	for (int i = 0; i < numOfVertex + 1; i++) {
		g[i] = new int[numOfVertex + 1];
	}

	for (int i = 1; i < numOfVertex + 1; i++)
		for (int j = 1; j<numOfVertex + 1; j++)
			g[i][j] = 0;

	visit = new bool[numOfVertex];
	for (int i = 1; i < numOfVertex + 1; i++)
		visit[i] = false;

	for (int i = 0; i < numOfEdge; i++) {
		cin >> stp >> dst;
		g[stp][dst] = 1;
		g[dst][stp] = 1;
	}

	
	cin >> startVertex;

	Dfs(g, visit, numOfVertex, startVertex);


	return 0;
}

void Dfs(int** arr, bool* visit, int numofvertex, int startvertex) {
	visit[startvertex] = true;
	cout << startvertex<< " ";

	for (int i = 1; i < numofvertex + 1; i++) {
		if (arr[startvertex][i] && !visit[i]) {
			Dfs(arr, visit, numofvertex, i);
		}
	}
}