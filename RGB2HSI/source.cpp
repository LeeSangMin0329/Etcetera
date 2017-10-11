#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	double r, g, b, h, s, i;
	
	cout << "Input (R, G, B) :";
	cin >> r >> g >> b;

	i = (r + g + b) / 3.0f;

	double min;
	if (r < g) {
		if (r < b)
			min = r;
		else
			min = b;
	}
	else {
		if (g < b)
			min = g;
		else
			min = b;
	}

	s = 1.0f - (3.0f / (r + g + b)) * min;
	
	double angle;
	angle = (r - 0.5f * g - 0.5f *b) / (double)sqrt((r - g)*(r - g) + (r - b) * (g - b));
	h = (double)acos(angle);
	h *= 57.29577951f;

	if (b > g)
		h = 360.0f - h;

	cout << "RGB :(" << r << ", " << g << ", " << b << ") -> (" << h << ", " << s << ", " << i << ")" << endl;

	return 0;
}