#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/
/*
动态规划法，时间复杂度为O(n^2)，空间复杂度为O(n^2)
*/
string longestPalindrome(string s)
{
	int const n = s.size();
	vector<vector<bool>> v(n, vector<bool>(n, false));
	size_t maxLength = 1;//最长回文子串的长度
	size_t start = 0;//最长回文子串的起点
	for (size_t i = 0; i < s.size(); ++i)
	{
		v[i][i] = true;
		for (size_t j = 0; j < i; ++j)
		{
			//v[j][i]==true;说明s字符串在i-j区间内为回文结构
			//i-j<2说明是相邻的相等，这也算回文
			v[j][i] = (s[j] == s[i] && (i - j < 2 || v[j + 1][i - 1]));
			if (v[j][i] && maxLength < (i - j + 1))
			{
				maxLength = i - j + 1;
				start = j;
			}
		}
	}
	return s.substr(start, maxLength);
}
int main(void)
{
	system("pause");
	return 0;
}