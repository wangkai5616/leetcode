#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;
// ��̬�滮��ʱ�临�Ӷ� O(n^2)���ռ临�Ӷ� O(n)
bool wordBreak(string s, vector<string>& wordDict) 
{
	// ����Ϊ n ���ַ����� n+1 ������
	vector<bool> v(s.size() + 1, false);
	v[0] = true;// ���ַ���
	unordered_set<string> word;
	for (auto i : wordDict)  word.insert(i);
	for (int i = 1; i <= v.size(); ++i)
	{
		for (int j = i - 1; j >= 0;--j)
			//�ӵ�j���ַ���ʼ��i-j���ַ�
			//v[j]����s�е�ǰj���ַ�
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