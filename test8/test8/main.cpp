#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;
void dfs(vector<vector<int>> &result, const vector<int> &v
	, vector<int> temp, int k, int h);
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> result;
	vector<int> v;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	vector<int> temp;
	dfs(result, v, temp, 0, k);
	return result;
}
void dfs(vector<vector<int>> &result, const vector<int> &v
	, vector<int> temp, int k, int h)
{
	if (temp.size() == h)
	{
		result.push_back(temp);
		for (int i = 0; i < temp.size(); ++i)
			cout << temp[i] << "	";
		cout << endl;
		return;
	}
	for (int i = k; i < v.size(); ++i)
	{
		temp.push_back(v[i]);
		dfs(result, v, temp, k + 1, h);
		temp.pop_back();
	}
}
int main(void)
{
	vector<vector<int>> result;
	result = combine(2,2);
	system("pause");
	return 0;
}




