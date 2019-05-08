#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
//递归版本，时间复杂度为O(3^n)，空间复杂度为O(n)
void dfs(const string &digits, size_t cur, string &path,
	vector<string> &result, const vector<string> &keyboard);
vector<string> letterCombinations(string digits)
{
	vector<string> keyboard{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> result;
	if (digits.empty())
		return result;
	string path = "";
	dfs(digits, 0, path, result, keyboard);
	return result;
}
void dfs(const string &digits, size_t cur, string &path,
	vector<string> &result, const vector<string> &keyboard)
{
	if (cur == digits.size())
	{
		result.push_back(path);
		return;
	}
	for (auto i : keyboard[digits[cur] - '0'])
	{
		path.push_back(i);
		dfs(digits, cur + 1, path, result, keyboard);
		path.pop_back();
	}
}
int main(void)
{
	
	system("pause");
	return 0;
}