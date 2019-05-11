#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。
示例:
输入: [1,1,2]
输出:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/
//思路：交换
void permuteUnique(vector<vector<int>> &result,
	vector<int> nums, int i);
vector<vector<int>> permuteUnique(vector<int> nums)
{
	vector<vector<int>> result;
	permuteUnique(result, nums, 0);
	return result;
}
void permuteUnique(vector<vector<int>> &result, 
	vector<int> nums, int i)
{
	vector<int> v;//统计出现的元素的值
	if (i == nums.size() - 1)
	{
		result.push_back(nums);
		return;
	}
	for (int j = i; j < nums.size(); ++j)
	{
		//判断之前是否出现过该值
		if (j != i && find(v.begin(),v.end(),nums[j])!=v.end())
			continue;
		else
		{
			v.push_back(nums[j]);
			swap(nums[i], nums[j]);
			permuteUnique(result, nums, i + 1);
		}
	}
}
void print(const vector<vector<int>> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<int> v{ 3,3,0,3 };
	vector<vector<int>> result;
	result = permuteUnique(v);
	print(result);
	system("pause");
	return 0;
}