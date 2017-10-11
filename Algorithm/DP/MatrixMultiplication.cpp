#include <iostream>

using namespace std;

int main(void) {
	int num;
	int* arr;


	cin >> num;

	arr = new int[num + 1];
	
	int n1, n2;
	for (int i = 0; i < num; i++) {
		cin >> n1 >> n2;
		if (i == 0)
			arr[i] = n1;
		arr[i + 1] = n2;
	}

	int **matrix = new int*[num + 1];
	for (int i = 0; i < num + 1; i++) {
		matrix[i] = new int[num + 1];
	}
	for (int i = 1; i <= num; i++) {
			matrix[i][i] = 0;
			
	}


	int i, j, k, diagonal;
	bool flag;
	for (diagonal = 1;diagonal <= num - 1;diagonal++)
		for (i = 1;i <= num - diagonal;i++)
		{
			j = i + diagonal; // 측 방향 증가
			flag = true;
			for (k = i;k <= j - 1;k++)
			{
				//cout << "i : " << i << " k : " << k << " j : " << j << endl;
				int temp = matrix[i][k] + matrix[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (flag) // 가장 첫번째 값을 초기 비교 기준값으로 저장
				{
					matrix[i][j] = temp;
					flag = false;
				}
				if (matrix[i][j] > temp)
					matrix[i][j] = temp;
			}
		}
	
	cout << matrix[1][num];

	return 0;
}