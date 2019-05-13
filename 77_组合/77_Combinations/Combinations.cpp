#include<iostream>
#include<vector>
using namespace std;
/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
*/
//思路：dfs+for循环
void combineCore(vector<vector<int>> &result, vector<int> v, int i, int n, int k);
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> result;
	if (n<1 && k>n)
		return result;
	vector<int> v;
	combineCore(result, v, 1, n, k);
	return result;
}
void combineCore(vector<vector<int>> &result, vector<int> &v, int i, int n, int k)
{
	if (v.size() == k)
	{
		result.push_back(v);
		return;
	}
	for (int j = i; j <= n; ++j)
	{
		v.push_back(j);
		combineCore(result, v, j + 1, n, k);
		v.pop_back();
	}
}
void print(vector<vector<int>> &result)
{
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<vector<int>> result = combine(4, 2);
	print(result);
	system("pause");
	return 0;
}