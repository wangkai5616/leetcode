#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，
使得句子中所有的单词都在词典中。返回所有这些可能的句子。
说明：
分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
"cats and dog",
"cat sand dog"
]
*/
// 动态规划，时间复杂度 O(n^2)，空间复杂度 O(n^2)
vector<string> wordBreak(string s, vector<string>& wordDict)
{
	// 长度为 n 的字符串有 n+1 个隔板
	vector<bool> v(s.size() + 1, false);
	v[0] = true;//空字符串
	// prev[i][j] 为 true，表示 s[j, i) 是一个合法单词，可以从 j 处切开
	vector<vector<bool>> prev(s.size() + 1, vector<bool>(s.size()));
	//把字典中的单词移到set中，方便O(1)时间查找
	unordered_set<string> word;
	for (auto i : wordDict)  word.insert(i);
	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (v[j] && word.find(s.substr(j, i - j)) != word.end())
			{
				v[i] = true;
				prev[i][j] = true;
			}
		}
	}

	vector<string> result;//最后的结果
	vector<string> path;//每一次的结果
	dfs(s, prev, s.size(), path, result);
	return result;
}
void dfs(const string &s, const vector<vector<bool>> &prev,
	int cur, vector<string> &path, vector<string> &result)
{
	//找到了一次结果，并且这次结果是在path中保存的
	if (cur == 0)
	{
		string temp;
		for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
			temp += *iter + " ";
		temp.erase(temp.end() - 1);//将最后一个""移除
		result.push_back(temp);
	}
	for (int i = 0; i < s.size(); ++i)
	{
		//s[cur,i)在字典中有
		if (prev[cur][i])
		{
			path.push_back(s.substr(i, cur - i));
			//判断i之前的
			dfs(s, prev, i, path, result);
			path.pop_back();
		}
	}
}
int main(void)
{
	system("pause");
	return 0;
}