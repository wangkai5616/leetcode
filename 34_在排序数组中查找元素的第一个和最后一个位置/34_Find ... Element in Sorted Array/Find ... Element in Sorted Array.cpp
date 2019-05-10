#include<iostream>
#include<vector>
using namespace std;
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
*/
vector<int> searchRange(vector<int>& nums, int target)
{
	int length = nums.size();
	int low = 0, high = length - 1;
	int mid = 0;
	//两个整数用于保存找到的开始位置和结束位置
	vector<int> result(2, -1);
	if (length == 0)
		return result;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (target == nums[mid])
		{
			int i = mid;//向左边继续寻找
			int j = mid;//向右边继续寻找
			while (i >= 0 && (nums[i] == target)) i--;
			if (i < 0)
				result[0] = 0;
			else
				result[0] = i + 1;
			while (j < length && (nums[j] == target)) j++;
			if (j > length)
				result[1] = nums[length - 1];
			else
				result[1] = j - 1;
			return result;
		}
		else if (target < nums[mid])	//小于
			high = mid - 1;
		else if (target > nums[mid])	//大于
			low = mid + 1;
	}
	return result;
}
int main(void)
{
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> v=searchRange(nums, 8);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}