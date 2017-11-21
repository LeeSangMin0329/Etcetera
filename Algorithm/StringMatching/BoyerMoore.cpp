#include <iostream>
#include <string>

using namespace std;

void ComputeJump(string pattern, char* jump) {

}

int main(void) {
	string pattern, alphabet;
	int jump[256];

	cin >> alphabet >> pattern;
	for (int i = 0; i < 256; i++) {
		jump[i] = pattern.size();
	}

	for (int i = 0; i < pattern.size() - 1; i++) {
		jump[pattern[i]] = pattern.size() - i - 1;
	}
	
	int i = 0;
	int j;
	int k;
	int count = 0;
	int matchCount = 0;
	while (i <= alphabet.size() - pattern.size()) {
		j = pattern.size();
		k = i + pattern.size();
		while (j > 0 && pattern[j - 1] == alphabet[k - 1]) {
			count++;
			j--;
			k--;
		}
		if (j == 0)
			matchCount++;
		i += jump[alphabet[i + pattern.size() - 1]];
	}
	
	cout << count << " " << matchCount << endl;
}