#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
˵�����⼯���ܰ����ظ����Ӽ�
*/
void dfs(const vector<int> &nums, int k, vector<int> &v, vector<vector<int>> &result);
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	vector<int> v;
	dfs(nums, 0, v, result);
	return result;
}
void dfs(const vector<int> &nums, int k, vector<int> &v, vector<vector<int>> &result)
{
	result.push_back(v);
	for (int i = k; i < nums.size(); ++i)
	{
		if (i != k && nums[i] == nums[i - 1])
			continue;
		v.push_back(nums[i]);
		dfs(nums, i + 1, v, result);
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
	vector<int> nums = { 1,2,2 };
	vector<vector<int>> result = subsetsWithDup(nums);
	print(result);
	system("pause");
	return 0;
}