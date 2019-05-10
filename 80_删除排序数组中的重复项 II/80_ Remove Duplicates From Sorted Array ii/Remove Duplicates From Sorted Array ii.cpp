#include<iostream>
#include<vector>
using namespace std;
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int index = -1;
	int length = 0;
	int times = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i == 0 || nums[i] != nums[i - 1])
		{
			times = 1;
			nums[++index] = nums[i];
			++length;

		}
		else if (nums[i] == nums[i - 1])
		{
			if (times == 1)
			{
				++times;
				nums[++index] = nums[i];
				++length;
			}
		}
	}
	return length;
}

//时间复杂度为O(n)，空间复杂度为O(1)的方法
int removeDuplicates2(vector<int>& nums)
{
	if (nums.size() < 3)
		return nums.size();
	int index = 2;
	for (int i = 2; i < nums.size(); ++i)
	{
		if (nums[i] != nums[index - 2])
			nums[index++] = nums[i];
	}
	return index;
}
int main(void)
{
	vector<int> nums = { 1,1,1,2,2,2,3 };
	int result = removeDuplicates2(nums);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
	cout << result << endl;
	system("pause");
	return 0;
}