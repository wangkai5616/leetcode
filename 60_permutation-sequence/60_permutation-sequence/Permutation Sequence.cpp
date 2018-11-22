#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
�������� [1,2,3,��,n]��������Ԫ�ع��� n! �����С�
���� n �� k�����ص� k �����С�
˵����
���� n �ķ�Χ�� [1, 9]��
���� k �ķ�Χ��[1,  n!]��
*/
void getPermutationCore(string s, int i, int &count, int k,string &result);
string getPermutation(int n, int k)
{
	string s(n, '0');
	string result;
	for (int i = 0; i < n; ++i)
		s[i] += i + 1;
	//cout << s << endl;
	int count = 1;
	getPermutationCore(s, 0, count, k, result);
	return result;
}
void getPermutationCore(string s, int i, int &count, int k, string &result)
{
	if (i == s.size() - 1)
	{
		if (count == k)
		{
			result = s;
			count++;
		}
		else
		{
			count++;
			return;
		}
	}
	for (int j = i; j < s.size(); ++j)
	{
		swap(s[i], s[j]);
		getPermutationCore(s, i + 1, count, k, result);
	}
}
int main(void)
{
	string s=getPermutation(3, 3);
	cout << s << endl;
	system("pause");
	return 0;
}