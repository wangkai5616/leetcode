#include<iostream>
#include<vector>
using namespace std;
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。
*/
int searchInsert(vector<int>& nums, int target)
{
	int begin = 0;
	int end = nums.size() - 1;
	int mid = 0;
	int flag = -1;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
		{
			begin = mid + 1;
			flag = 1;
		}
		else
		{
			end = mid - 1;
			flag = 2;
		}
	}
	if (flag == 1)
		return begin;
	else if (flag == 2)
		return end+1;
}
int main(void)
{
	vector<int> v = { 1,3,5,6 };
	int result = searchInsert(v, 0);
	cout << result << endl;
	system("pause");
	return  0;
}