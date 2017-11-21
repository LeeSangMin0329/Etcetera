#include <iostream>
#include <string>

using namespace std;

int matchCount = 0;
int perfectMatchingCount = 0;

bool matching(string s, string p, int index) {
	for (int i = 0; i < p.size(); i++) {
		matchCount++;
		if (p[i] != s[index + i]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	string pattern, sentence;

	cin >> sentence >> pattern;

	for (int i = 0; i <= sentence.size() - pattern.size(); i++) {
		if (matching(sentence, pattern, i)) {
			perfectMatchingCount++;
		}
	}

	cout << matchCount << " " << perfectMatchingCount << endl;

	return 0;
}