#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
动态规划，状态转移方程为f(i) = min {f(j + 1) + 1, f(i)} , i ≤ j <n
代表的是(i,j)之间是回文，j和j+1之间切一刀，然后加上f(j+1)
f(i)代表的是i到n的这段字符串的最少切割次数
*/
// 时间复杂度 O(n^2)，空间复杂度 O(n^2)
int minCut(string s) 
{
	int n = s.size();
	vector<int> v(n + 1);
	//b[i][j]为true，代表i到j上为回文
	vector<vector<bool>> b(n, vector<bool>(n, false));
	//下面这是用最坏的情况初始化v，
	//v[i]代表的是从i到n这个字符串需要切割的次数
	for (int i = 0; i <= n; ++i)
		v[i] = n - 1 - i;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			//说明i到j能构成一个回文串
			if (s[i] == s[j] && (j - i < 2 || b[i + 1][j - 1]))
			{
				b[i][j] = true;
				//j+1到n需要切割的次数+1(j和j+1需要切一刀)
				v[i] = min(v[i], v[j + 1] + 1);
			}
		}
	}
	return v[0];
}
int main(void)
{
	system("pause");
	return 0;
}