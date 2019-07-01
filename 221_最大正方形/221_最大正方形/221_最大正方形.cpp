#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
ʹ�ö�̬�滮��ʱ�临�Ӷ�ΪO(n^2)
dp[i][j]��ʾ�����Ե�(i,j)Ϊ���½ǵ������εı߳�
״̬ת�Ʒ����ǣ�dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
*/
int maximalSquare(vector<vector<char>>& matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> v(m, vector<int>(n, 0));
	int result = 0;
	for (int i = 0; i < m; ++i)
		if (matrix[i][0] == '1')
		{
			v[i][0] = 1;
			result = 1;
		}
	for (int i = 0; i < n; ++i)
		if (matrix[0][i] == '1')
		{
			v[0][i] = 1;
			result = 1;
		}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (matrix[i][j] == '1')
				v[i][j] = min(v[i - 1][j - 1], min(v[i][j - 1], v[i - 1][j])) + 1;
			result = max(result, v[i][j]);
		}
	}
	return result*result;
}