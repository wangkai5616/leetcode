#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;
// 动态规划，时间复杂度 O(n^2)，空间复杂度 O(n)
bool wordBreak(string s, vector<string>& wordDict) 
{
	// 长度为 n 的字符串有 n+1 个隔板
	vector<bool> v(s.size() + 1, false);
	v[0] = true;// 空字符串
	unordered_set<string> word;
	for (auto i : wordDict)  word.insert(i);
	for (int i = 1; i <= v.size(); ++i)
	{
		for (int j = i - 1; j >= 0;--j)
			//从第j个字符开始的i-j个字符
			//v[j]代表s中的前j个字符
			if (v[j] && word.find(s.substr(j, i - j)) != word.end())
			{
				v[i] = true;
				break;
			}
	}
	return v[s.size()];
}
int main(void)
{
	system("pause");
}