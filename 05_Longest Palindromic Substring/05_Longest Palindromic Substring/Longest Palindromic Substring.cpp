#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��
*/
/*
��̬�滮����ʱ�临�Ӷ�ΪO(n^2)���ռ临�Ӷ�ΪO(n^2)
*/
string longestPalindrome(string s)
{
	int const n = s.size();
	vector<vector<bool>> v(n, vector<bool>(n, false));
	size_t maxLength = 1;//������Ӵ��ĳ���
	size_t start = 0;//������Ӵ������
	for (size_t i = 0; i < s.size(); ++i)
	{
		v[i][i] = true;
		for (size_t j = 0; j < i; ++j)
		{
			//v[j][i]==true;˵��s�ַ�����i-j������Ϊ���Ľṹ
			//i-j<2˵�������ڵ���ȣ���Ҳ�����
			v[j][i] = (s[j] == s[i] && (i - j < 2 || v[j + 1][i - 1]));
			if (v[j][i] && maxLength < (i - j + 1))
			{
				maxLength = i - j + 1;
				start = j;
			}
		}
	}
	return s.substr(start, maxLength);
}
int main(void)
{
	system("pause");
	return 0;
}