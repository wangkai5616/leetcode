#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
*/
/*
设状态为 f[i][j]，表示 A[0,i] 和 B[0,j] 之间的最小编辑距离。设 A[0,i] 的形式是
str1c，B[0,j] 的形式是 str2d，
1. 如果 c==d，则 f[i][j]=f[i-1][j-1]；
2. 如果 c!=d，
(b) 如果在 c 后面添加一个 d，则 f[i][j]=f[i][j-1]+1；
(c) 如果将 c 删除，则 f[i][j]=f[i-1][j]+1;
*/
int minDistance(string word1, string word2)
{
	int n = word1.size();
	int m = word2.size();
	vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; ++i)
		v[i][0] = i;
	for (int j = 0; j <= m; ++j)
		v[0][j] = j;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				v[i][j] = v[i - 1][j - 1];
			else
			{
				int k = min(v[i - 1][j], v[i][j - 1]);
				v[i][j] = 1 + min(v[i - 1][j - 1], k);
			}
		}
	}
	return v[n][m];
}
int main(void)
{
	system("pasue");
	return 0;
}