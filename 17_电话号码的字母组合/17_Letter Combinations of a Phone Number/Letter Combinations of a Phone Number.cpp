#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
*/
//�ݹ�汾��ʱ�临�Ӷ�ΪO(3^n)���ռ临�Ӷ�ΪO(n)
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