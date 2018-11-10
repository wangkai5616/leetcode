#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include<iostream>
#include<vector>
#include<hash_map>
using namespace std;
/*
����ʵ�֣�
ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(1)
*/
//Ҫע�ⷵ��vector�ķ�ʽ��������ô��סvector,���Թ��캯������ʽ��ɵ�
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
������ϣ��ʵ�֣�
ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷȣ�O(n)
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
һ����ϣ��ʵ�֣�
ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷȣ�O(n)
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