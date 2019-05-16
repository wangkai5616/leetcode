#include<iostream>
#include<vector>
using namespace std;
/*
����һ������ n������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֣�
*/
/*
˼·��
������Ϊ 1, 2, 3, ..., n ʱ����������ԭ��Ĺ����� BST ������Ψһ�ԣ��� i Ϊ���ڵ����������
������ [1, i-1] ���ɣ����������� [i+1, n] ���ɡ�

*/
int numTrees(int n)
{
	vector<int> v(n + 1, 0);
	v[0] = 1;
	v[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int k = 1; k <= i; ++k)
			v[i] += v[k - 1] * v[i - k];
	}
	return v[n];
}
int main(void)
{
	system("pause");
	return 0;
}