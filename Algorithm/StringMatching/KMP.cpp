#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string pattern, alphabet;
	int* PI;
	int i, j;

	cin >> alphabet >> pattern;

	PI = new int[pattern.size() + 1];
	
	i = 0;
	j = -1;
	PI[0] = -1;
	while (i < pattern.size()) {
		if (j == -1 || pattern[i] == pattern[j]) {
			i++;
			j++;
			PI[i] = j;
		}
		else
			j = PI[j];
	}

	i = 0;
	j = 0;
	int cnt = 0;
	bool f = false;
	while (i < alphabet.size()) {
		cnt++;
		if (j == -1 || alphabet[i] == pattern[j]) {
			i++;
			j++;
		}
		else
			j = PI[j];

		if (j == pattern.size()) {
			cout << cnt << endl;
			j = PI[j];
			f = true;
		}
	}

	if (!f)
		cout << "fail" << endl;

	return 0;
}