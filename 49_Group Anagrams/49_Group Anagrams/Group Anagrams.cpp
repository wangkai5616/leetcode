#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
ʾ��:
����: ["eat", "tea", "tan", "ate", "nat", "bat"],
���:
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