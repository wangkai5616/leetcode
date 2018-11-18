#include<iostream>
#include<vector>
using namespace std;
/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
*/
/*
思路：
当数组为 1, 2, 3, ..., n 时，基于以下原则的构建的 BST 树具有唯一性：以 i 为根节点的树，其左
子树由 [1, i-1] 构成，其右子树由 [i+1, n] 构成。

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