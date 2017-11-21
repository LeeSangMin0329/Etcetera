#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string sentence, pattern;
	char alphabet[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	cin >> sentence >> pattern;

	int patternHash = 0;
	int digit = 1;

	for (int i = pattern.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (alphabet[j] == pattern[i]) {
				patternHash += (j)*digit;
				digit *= 10;
			}
		}
	}

	digit = 1;
	int compare = 0;
	int firstChNum = 0;
	int headIndex = 0;
	for (int i = pattern.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (alphabet[j] == sentence[i]) {
				compare += (j)*digit;
				digit *= 10;
			}
		}
	}
	
	digit /= 10;
	int matchingCount = 0;
	int tmp = 0;
	
	
	for (int i = pattern.size() -1; i < sentence.size(); i++) {
		cout << compare << " ";
		if (i != pattern.size() -1) {
			for (int j = 0; j < 10; j++) {
				if (sentence[i] == alphabet[j]) {
					tmp = j;
				}
				if (sentence[headIndex] == alphabet[j])
					firstChNum = j*digit;
			}
			headIndex++;
			compare = 10 * (compare - firstChNum) + tmp;
		}
		
		if (patternHash == compare) {
			matchingCount++;
		}
		
	}

	cout << matchingCount << endl;


	return 0;
}