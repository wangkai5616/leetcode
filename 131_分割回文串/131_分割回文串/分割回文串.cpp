#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���
���� s ���п��ܵķָ����
ʾ��:
����: "aab"
���:
[
["aa","b"],
["a","a","b"]
]
*/
/*
������ȱ���
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
			//��m��i�ǻ���
			v.push_back(s.substr(m, i - m + 1));
			//�жϴ�i+1����֮����Ƿ��ǻ���
			dfs(result, v, s, i + 1);
			//�����Ҫ��������Ӱ���´��ж�
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