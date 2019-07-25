#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<hash_map>
#include<unordered_map>
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
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				v.push_back(i);
				v.push_back(j);
				return v;
			}
		}
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
			v.push_back(map[nums[i]]);
			v.push_back(map[temp]);
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
	unordered_map<int, int> m;
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i)
		m[nums[i]] = i;
	for (int i = 0; i < nums.size(); ++i)
	{
		int t = target - nums[i];
		if (m.count(t) && m[t] != i)
		{
			res.push_back(i);
			res.push_back(m[t]);
			break;
		}
	}
	return res;
}
int main(void)
{
	vector<int> v{ 3,3 };
	vector<int> result = twoSum3(v, 6);
	for (auto i : result)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}