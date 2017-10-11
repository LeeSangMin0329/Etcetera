#include <iostream>
#include <algorithm>

using namespace std;

class Edge {
public:
	int srt;
	int dst;
	int weight;
};

bool compare(const Edge& e1, const Edge& e2) {
	return e1.weight < e2.weight;
}

int find(int* vertex, int num) {
	if (vertex[num] == num)
		return num;
	return vertex[num] = find(vertex, vertex[num]);
}

int main(void) {
	int numOfVertex, numOfEdge;
	int srt, dst, weight;
	Edge* edges;
	int* nodes;

	cin >> numOfVertex >> numOfEdge;
	nodes = new int[++numOfVertex];
	for (int i = 1; i < numOfVertex; i++) {
		nodes[i] = i;
	}
	edges = new Edge[++numOfEdge];
	for (int i = 1; i < numOfEdge; i++) {
		cin >> srt >> dst >> weight;
		edges[i].srt = srt;
		edges[i].dst = dst;
		edges[i].weight = weight;
	}
	sort(edges + 1, edges + 1 + numOfEdge - 1, compare);
	
	int srtTmp, dstTmp;
	int sum = 0;
	for (int i = 1; i < numOfEdge; i++) {
		srtTmp = find(nodes, edges[i].srt);
		dstTmp = find(nodes, edges[i].dst);
		if (srtTmp == dstTmp)
			continue; //cycle
		if (srtTmp > dstTmp)
			nodes[srtTmp] = dstTmp;
		else
			nodes[dstTmp] = srtTmp;

		sum += edges[i].weight;
		cout << edges[i].weight << " ";
	}

	cout << sum;

	return 0;
}