#include<iostream>
#include<vector>
using namespace std;
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
*/
/*
二分查找，主要是边界的确定，一定存在某半部分还是递增的，
找到它，然后再进行target的判断
*/
int search(vector<int>& nums, int target)
{
	int first = 0;
	int last = nums.size();
	int mid = 0;
	while (first != last)
	{
		mid = (first + last) / 2;
		if (nums[mid] == target)
			return mid;
		//说明左半部分是递增的，没有受到旋转的影响
		if (nums[first] <= nums[mid])
		{
			if (nums[first] <= target && target < nums[mid])
				last = mid;
			else
				first = mid + 1;
		}
		//说明左半部分不是递增，右半部分是递增
		else
		{
			if (nums[mid] < target && target <= nums[last-1])
				first = mid + 1;
			else
				last = mid;
		}
	}
	return -1;
}
int main(void)
{
	vector<int> v = { 4,5,6,7,0,1,2 };
	int result = search(v, 3);
	cout << result << endl;
	system("pause");
	return 0;
}