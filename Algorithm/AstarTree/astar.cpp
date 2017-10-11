#include <iostream>
#include <vector>
#include <math.h>

#define INF 99999999

using namespace std;

struct point {
	int x;
	int y;
}typedef Point;

double eucliean_dist(const Point& a, const Point& b)
{
	double x = a.x - b.x;
	double y = a.y - b.y;
	x = x < 0.0 ? -x : x;
	y = y < 0.0 ? -y : y;

	return sqrt(x*x + y*y);
}

int main(void) {
	int height, width;
	double** h;
	double** g;
	double** f;
	Point** prev;

	cin >> height >> width;

	h = new double*[height];
	g = new double*[height];
	f = new double*[height];
	prev = new Point*[height];
	for (int i = 0; i < height; i++) {
		h[i] = new double[width];
		g[i] = new double[width];
		f[i] = new double[width];
		prev[i] = new Point[width];
	}

	for (int i = 0; i<height; i++)
		for (int j = 0; j < width; j++) {
			cin >> h[i][j];
			if (h[i][j] == 0) {
				g[i][j] = INF;
				f[i][j] = INF;
			}
			else {
				g[i][j] = -1;
				f[i][j] = -1;
			}
		}

	point dst, srt;
	cin >> srt.x >> srt.y;
	cin >> dst.x >> dst.y;
	srt.x--;
	srt.y--;
	dst.x--;
	dst.y--;

	vector<Point> Q;
	Point tmp;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (h[i][j] != 1) {
				tmp.x = i;
				tmp.y = j;
				h[i][j] = eucliean_dist(tmp, dst);
				Q.push_back(tmp);
			}
			else
				h[i][j] = INF;
		}
	}

	g[srt.x][srt.y] = 0;
	f[srt.x][srt.y] = h[srt.x][srt.y];

	Point u;
	double min;
	int ct = 0;

	if (dst.x == srt.x && dst.y == srt.y) {
		cout << "(" << dst.x + 1 << ", " << dst.y + 1 << ")" << endl;
		cout << 0 << endl;
		return 0;
	}


	while (Q.size() != 0) {
		min = f[Q[0].x][Q[0].y];
		ct = 0;
		for (int i = 1; i < Q.size(); i++) {
			if (min > f[Q[i].x][Q[i].y]) {
				min = f[Q[i].x][Q[i].y];
				ct = i;
			}
			else if (min == f[Q[i].x][Q[i].y]) {
				if (Q[ct].x > Q[i].x) {
					ct = i;
				}
				else if (Q[ct].x == Q[i].x) {
					if (Q[ct].y > Q[i].y) {
						ct = i;
					}
				}
			}
		}
		u = Q[ct];
		Q.erase(Q.begin() + ct);

		/*
		for (int i = 0; i < Q.size(); i++) {
			cout << "(" << Q[i].x << " " << Q[i].y << ")-";
		}
		cout << endl;

		cout << f[u.x][u.y] << "  === " << u.x << ", " << u.y << endl;
		*/
		

		if (dst.x == u.x && dst.y == u.y && g[u.x][u.y] < INF) {

			int tx, ty, sx, sy;
			tx = dst.x;
			ty = dst.y;
			
			/*
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					cout << "(" << prev[i][j].x << ", " << prev[i][j].y << ") \t";
				}
				cout << endl;
			}
			*/
			
			vector<Point> path;
			//path.push_back(dst);
			while (true) {
				if (tx == srt.x && ty == srt.y)
					break;
				//cout << prev[tx][ty].x << " " << prev[tx][ty].y << " -> ";
				path.push_back(prev[tx][ty]);
				sx = prev[tx][ty].x;
				sy = prev[tx][ty].y;
				
				tx = sx;
				ty = sy;
			}
			//path.push_back(srt);
			//cout << endl;
			
			for (int i = path.size() - 1; i >= 0; i--)
				cout << "(" << path[i].x + 1 << ", " << path[i].y + 1 << ") -> ";
			cout << "(" << dst.x + 1 << ", " << dst.y + 1 << ")" << endl;
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << g[dst.x][dst.y] << endl;
			return 0;
			
		}
		else {
			for (int y = -1; y < 2; y++) {
				for (int x = -1; x < 2; x++) {
					if (!(y == 0 && x == 0)) {
						for (int n = 0; n < Q.size(); n++) {
							if ((u.x + x) == Q[n].x && (u.y + y) == Q[n].y) {
								tmp.x = u.x + x;
								tmp.y = u.y + y;
								if (g[u.x][u.y] + eucliean_dist(u, tmp) < g[tmp.x][tmp.y]) {
								
									g[tmp.x][tmp.y] = g[u.x][u.y] + eucliean_dist(u, tmp);
									prev[tmp.x][tmp.y] = u;
									//cout << "u =>" << u.x << ", " << u.y << endl;
									f[tmp.x][tmp.y] = g[tmp.x][tmp.y] + h[tmp.x][tmp.y];
								}
							}
						}
					}
				}
			}
		}
	}
	cout << -1 << endl;

	

	return 0;
}