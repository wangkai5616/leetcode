#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且
有效的括号组合。
*/
/*
当左括号出现次数 < n 时，就可以放置新的左括号。当右括号出现次数小
于左括号出现次数时，就可以放置新的右括号。
*/
void dfs(int n, string s, int l, int r, vector<string> &result);
vector<string> generateParenthesis(int n)
{
	vector<string> result;
	if (n < 1)
		return result;
	int l = 0;
	int r = 0;
	dfs(n, "", l, r, result);
	return result;
}
void dfs(int n, string s, int l, int r, vector<string> &result)
{
	//说明'('都进来了
	if (l == n)
	{
		result.push_back(s.append(n - r, ')'));
		return;
	}
	dfs(n, s + '(', l + 1, r, result);
	if (l > r)
		dfs(n, s + ')', l, r + 1, result);
}
int main(void)
{
	system("pause");
	return 0;
}