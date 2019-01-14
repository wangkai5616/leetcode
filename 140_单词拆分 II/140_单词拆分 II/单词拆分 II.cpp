#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
/*
����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict�����ַ��������ӿո�������һ�����ӣ�
ʹ�þ��������еĵ��ʶ��ڴʵ��С�����������Щ���ܵľ��ӡ�
˵����
�ָ�ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
����Լ����ֵ���û���ظ��ĵ��ʡ�
ʾ�� 1��

����:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
���:
[
"cats and dog",
"cat sand dog"
]
*/
// ��̬�滮��ʱ�临�Ӷ� O(n^2)���ռ临�Ӷ� O(n^2)
vector<string> wordBreak(string s, vector<string>& wordDict)
{
	// ����Ϊ n ���ַ����� n+1 ������
	vector<bool> v(s.size() + 1, false);
	v[0] = true;//���ַ���
	// prev[i][j] Ϊ true����ʾ s[j, i) ��һ���Ϸ����ʣ����Դ� j ���п�
	vector<vector<bool>> prev(s.size() + 1, vector<bool>(s.size()));
	//���ֵ��еĵ����Ƶ�set�У�����O(1)ʱ�����
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

	vector<string> result;//���Ľ��
	vector<string> path;//ÿһ�εĽ��
	dfs(s, prev, s.size(), path, result);
	return result;
}
void dfs(const string &s, const vector<vector<bool>> &prev,
	int cur, vector<string> &path, vector<string> &result)
{
	//�ҵ���һ�ν����������ν������path�б����
	if (cur == 0)
	{
		string temp;
		for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
			temp += *iter + " ";
		temp.erase(temp.end() - 1);//�����һ��""�Ƴ�
		result.push_back(temp);
	}
	for (int i = 0; i < s.size(); ++i)
	{
		//s[cur,i)���ֵ�����
		if (prev[cur][i])
		{
			path.push_back(s.substr(i, cur - i));
			//�ж�i֮ǰ��
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