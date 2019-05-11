#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int>> permuteUnique(vector<int> nums)
{
	vector<vector<int>> result;

}
void dfs(vector<vector<int>> &result, vector<int> nums, int k)
{
	if (k == nums.size() - 1)
	{
		result.push_back(nums);
		return;
	}
	vector<int> v;
	for (int i = k; i < nums.size(); ++i)
	{
		if (i != k && find(v.begin(), v.end(), nums[i]) != v.end())
			continue;
		else
		{
			v.push_back(nums[i]);
		}
	}
}
int main(void)
{

	system("pause");
	return 0;
}

