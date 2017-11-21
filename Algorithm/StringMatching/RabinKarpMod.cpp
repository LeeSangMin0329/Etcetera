#include <iostream>
#include <string>
#include <math.h>

#define ASCIIOFFSET 97

using namespace std;

int Mod(long long x, long long y) {
	return (((x%y) + y) % y);
}

int main(void) {

	string pattern, alphabet;

	cin >> alphabet >> pattern;

	int pLength = pattern.size();

	long long pHash = 0;
	long long aHash = 0;
	long long digit = 1;
	int matchingCount = 0;

	for (int i = 0; i < pLength; i++) {
		pHash = (pattern[i] - ASCIIOFFSET) + pHash * 26;
		pHash = Mod(pHash, 113);
		aHash = (alphabet[i] - ASCIIOFFSET) + aHash * 26;
		aHash = Mod(aHash, 113);
	}

	

	digit = 1;
	int j;
	for (int i = 0; i < pLength - 1; i++) {
		digit *= 26;
		digit = Mod(digit, 113);
	}
	
	for (int i = 0; i < alphabet.size() - pLength + 1; i++) {
		cout << aHash << " ";
		if (i != 0) {
			aHash = (26 * (aHash - digit*(alphabet[i - 1] - ASCIIOFFSET))) + (alphabet[i + pLength - 1] - ASCIIOFFSET);
			aHash = Mod(aHash, 113);
		}
		if (pHash == aHash) {
			for (j = 0; j < pLength; j++) {
				if (pattern[j] != alphabet[i + j]) {
					break;
				}
			}
			if(j == pLength)
				matchingCount++;
		}
			
	}

	cout << matchingCount << endl;

	return 0;
}