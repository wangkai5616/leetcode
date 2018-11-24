#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
*/
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> group;
	for (auto s : strs)
	{
		string key = s;
		sort(key.begin(), key.end());
		group[key].push_back(s);
	}
	vector<vector<string>> result;
	for (auto i = group.begin(); i != group.end(); ++i)
	{
		result.push_back(i->second);
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}