#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
������������ word1 �� word2��������� word1 ת���� word2 ��ʹ�õ����ٲ����� ��
����Զ�һ�����ʽ����������ֲ�����
����һ���ַ�
ɾ��һ���ַ�
�滻һ���ַ�
*/
/*
��״̬Ϊ f[i][j]����ʾ A[0,i] �� B[0,j] ֮�����С�༭���롣�� A[0,i] ����ʽ��
str1c��B[0,j] ����ʽ�� str2d��
1. ��� c==d���� f[i][j]=f[i-1][j-1]��
2. ��� c!=d��
(b) ����� c �������һ�� d���� f[i][j]=f[i][j-1]+1��
(c) ����� c ɾ������ f[i][j]=f[i-1][j]+1;
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