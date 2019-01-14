#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
��̬�滮��״̬ת�Ʒ���Ϊf(i) = min {f(j + 1) + 1, f(i)} , i �� j <n
�������(i,j)֮���ǻ��ģ�j��j+1֮����һ����Ȼ�����f(j+1)
f(i)�������i��n������ַ����������и����
*/
// ʱ�临�Ӷ� O(n^2)���ռ临�Ӷ� O(n^2)
int minCut(string s) 
{
	int n = s.size();
	vector<int> v(n + 1);
	//b[i][j]Ϊtrue������i��j��Ϊ����
	vector<vector<bool>> b(n, vector<bool>(n, false));
	//������������������ʼ��v��
	//v[i]������Ǵ�i��n����ַ�����Ҫ�и�Ĵ���
	for (int i = 0; i <= n; ++i)
		v[i] = n - 1 - i;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			//˵��i��j�ܹ���һ�����Ĵ�
			if (s[i] == s[j] && (j - i < 2 || b[i + 1][j - 1]))
			{
				b[i][j] = true;
				//j+1��n��Ҫ�и�Ĵ���+1(j��j+1��Ҫ��һ��)
				v[i] = min(v[i], v[j + 1] + 1);
			}
		}
	}
	return v[0];
}
int main(void)
{
	system("pause");
	return 0;
}