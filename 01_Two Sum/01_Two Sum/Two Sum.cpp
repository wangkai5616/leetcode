#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include<iostream>
#include<vector>
#include<hash_map>
using namespace std;
/*
暴力实现：
时间复杂度：O(n^2)
空间复杂度：O(1)
*/
//要注意返回vector的方式，包括怎么接住vector,是以构造函数的形式完成的
vector<int> twoSum1(vector<int>& nums, int target)
{
	vector<int> v;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		if (nums[i] + nums[i + 1] == target)
		{
			v.push_back(nums[i]);
			v.push_back(nums[i + 1]);
			return v;
		}
		else
			i++;
	}
	return v;
}
/*
两个哈希表实现：
时间复杂度：O(n)
空间复杂度：O(n)
*/
vector<int> twoSum2(vector<int>& nums, int target)
{
	vector<int> v;
	hash_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
		map[nums[i]] = i;
	for (int i = 0; i < nums.size(); ++i)
	{
		int temp = target - nums[i];
		if (map.find(temp) != map.end() && map[temp] != i)
		{
			v.push_back(nums[i]);
			v.push_back(temp);
			return v;
		}
	}
	return v;
}
/*
一个哈希表实现：
时间复杂度：O(n)
空间复杂度：O(n)
*/
vector<int> twoSum3(vector<int>& nums, int target)
{
	vector<int> v;
	hash_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i)
	{
		map[nums[i]] = i;
		int temp = target - nums[i];
		if (map.find(temp) != map.end() && map[temp] != i)
		{
			v.push_back(nums[i]);
			v.push_back(temp);
			return v;
		}
	}
	return v;
}
int main(void)
{
	vector<int> v{ 2,47,32,4,9 };
	vector<int> result = twoSum3(v, 11);
	for (auto i : result)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}