#include<iostream>
#include<vector>
using namespace std;
int uniquePaths(int m, int n) {
	vector<vector<int>> result(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			result[i][j] = result[i - 1][j] + result[i][j - 1];
		}
	}
	return result[m - 1][n - 1];
}

int main(void)
{
	int result = uniquePaths(7, 3);
	cout << result << endl;
	system("pause");
	return 0;
}