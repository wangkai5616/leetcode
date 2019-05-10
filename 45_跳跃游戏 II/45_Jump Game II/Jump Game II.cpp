#include<iostream>
#include<vector>
using namespace std;
/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:
假设你总是可以到达数组的最后一个位置。
*/
//时间复杂度(n),空间复杂度O(1)
int jump(vector<int>& nums)
{
	const int length = nums.size();
	if (length == 1)
		return 0;
	int step = 0;//最小步数
	//[left,right]是当前能覆盖的区间
	int left = 0;
	int right = 0;
	while (left <= right)
	{
		++step;
		int oldRigth = right;
		for (int i = left; i <= oldRigth; ++i)
		{
			int newRight = i + nums[i];
			if (newRight >= length - 1)
				return step;
			if (newRight > right)
				right = newRight;
		}
		left = oldRigth + 1;
	}
	return 0;
}
int main(void)
{
	vector<int> nums = { 2,3,1,1,2,3,1,1,2 };
	int result = jump(nums);
	system("pause");
	return 0;
}