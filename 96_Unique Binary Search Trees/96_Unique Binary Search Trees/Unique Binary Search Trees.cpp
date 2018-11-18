#include<iostream>
#include<vector>
using namespace std;
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