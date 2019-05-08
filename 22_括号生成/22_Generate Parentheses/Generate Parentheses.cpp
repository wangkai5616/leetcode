#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
���� n �����������ŵĶ���������д��һ��������ʹ���ܹ��������п��ܵĲ���
��Ч��������ϡ�
*/
/*
�������ų��ִ��� < n ʱ���Ϳ��Է����µ������š��������ų��ִ���С
�������ų��ִ���ʱ���Ϳ��Է����µ������š�
*/
void dfs(int n, string s, int l, int r, vector<string> &result);
vector<string> generateParenthesis(int n)
{
	vector<string> result;
	if (n < 1)
		return result;
	int l = 0;
	int r = 0;
	dfs(n, "", l, r, result);
	return result;
}
void dfs(int n, string s, int l, int r, vector<string> &result)
{
	//˵��'('��������
	if (l == n)
	{
		result.push_back(s.append(n - r, ')'));
		return;
	}
	dfs(n, s + '(', l + 1, r, result);
	if (l > r)
		dfs(n, s + ')', l, r + 1, result);
}
int main(void)
{
	system("pause");
	return 0;
}