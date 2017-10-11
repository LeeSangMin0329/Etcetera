#include <iostream>
#include <queue>
#include <cmath>

#define INF 99999999

using namespace std;

double eucliean_dist(const pair<int, int>& a, const pair<int, int>& b) {
	double x = a.first - b.first;
	double y = a.second - b.second;
	x = x < 0.0 ? -x : x;
	y = y < 0.0 ? -y : y;

	return sqrt(x*x + y*y);
}

class node {
public:
	int x, y;
	int dist;
	int depth;

	node* parent;

};

int main(void) {

	priority_queue< pair<double, pair<int, int> > > qu;

	int width, height;
	int **map;

	cin >> height >> width;
	map = new int*[height];
	for (int i = 0; i < height; i++) {
		map[i] = new int[width];
	}

	for (int i = 0; i < height; i++)
		for (int j = 0; j < height; j++)
			cin >> map[i][j];

	pair<int, int> dst, srt;

	cin >> srt.first >> srt.second;
	cin >> dst.first >> dst.second;

	pair<int, int> tmp;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < height; j++) {
			if (map[i][j] == 0) {
				tmp.first = j;
				tmp.second = i;
				map[i][j] = eucliean_dist(tmp, dst);
			}
			else
				map[i][j] = INF;
		}
			


	return 0;
}