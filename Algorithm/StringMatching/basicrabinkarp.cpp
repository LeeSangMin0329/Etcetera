#include <iostream>
#include <string>
#include <math.h>

#define ASCIIOFFSET 97

using namespace std;

int main(void) {

	string pattern, alphabet;

	cin >> alphabet >> pattern;

	int pLength = pattern.size();

	int pHash = 0;
	int aHash = 0;
	int digit = pow(10, (pLength - 1));
	int matchingCount = 0;

	for (int i = 0; i < pLength; i++) {
		pHash += (pattern[i] - ASCIIOFFSET) * digit;
		aHash += (alphabet[i] - ASCIIOFFSET) * digit;
		digit /= 10;
	}

	digit = pow(10, pLength - 1);

	for (int i = 0; i < alphabet.size() - pLength + 1; i++) {
		cout << aHash << " ";
		if (i != 0) {
			aHash = (10*(aHash - digit*(alphabet[i - 1] - ASCIIOFFSET))) + (alphabet[i + pLength - 1] - ASCIIOFFSET);
		}
		if (pHash == aHash)
			matchingCount++;
	}

	cout << matchingCount << endl;

	return 0;
}