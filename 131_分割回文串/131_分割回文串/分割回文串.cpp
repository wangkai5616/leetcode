#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。
示例:
输入: "aab"
输出:
[
["aa","b"],
["a","a","b"]
]
*/
/*
深度优先遍历
*/
vector<vector<string>> partition(string s)
{
	vector<vector<string>> result;
	vector<string> v;
	dfs(result, v, s, 0);
	return result;
}
void dfs(vector<vector<string>> &result, vector<string> &v,
	string s, int m)
{
	if (m == s.size())
	{
		result.push_back(v);
		return;
	}
	for (int i = m; i < s.size(); ++i)
	{
		if (isPail(s.substr(m, i - m + 1)))
		{
			//从m到i是回文
			v.push_back(s.substr(m, i - m + 1));
			//判断从i+1及其之后的是否是回文
			dfs(result, v, s, i + 1);
			//加入就要弹出，不影响下次判断
			v.pop_back();
		}
	}
}
bool isPail(string s)
{
	for (int i = 0; i < s.size() / 2; ++i)
		if (s[i] != s[s.size() - i - 1])
			return false;
	return true;
}

int main(void)
{
	system("pause");
	return 0;
}