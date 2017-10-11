#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str1, str2;

	cin >> str1 >> str2;

	str1 = '0' + str1;
	str2 = '0' + str2;

	int** arr;
	arr = new int*[str1.size()];
	for (int i = 0; i < str1.size(); i++) {
		arr[i] = new int[str2.size()];
	}

	for (int i = 0; i < str2.size(); i++)
		arr[0][i] = 0;
	for (int i = 0; i < str1.size(); i++)
		arr[i][0] = 0;

	for (int i = 1; i < str1.size(); i++) {
		for (int j = 1; j < str2.size(); j++) {
			
			if (str1[i] == str2[j]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				if (arr[i - 1][j] < arr[i][j - 1])
					arr[i][j] = arr[i][j - 1];
				else
					arr[i][j] = arr[i - 1][j];
			}
		}
	}
	
	cout << arr[str1.size() - 1][str2.size() - 1];

	return 0;
}