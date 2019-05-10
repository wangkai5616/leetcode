#include<iostream>
#include<vector>
using namespace std;
/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3
示例 2:
输入: [3,4,-1,1]
输出: 2
示例 3:
输入: [7,8,9,11,12]
输出: 1
说明:
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/
/*
思路：本质上是桶排序 (bucket sort)，每当 A[i]!= i+1 的时候，将 A[i] 与 A[A[i]-1] 交换，直到无法
交换为止，终止条件是 A[i]== A[A[i]-1]。
*/
void bucket_sort(vector<int>& nums, int n);
//时间复杂度O(n)，空间复杂度O(1)
int firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();
	bucket_sort(nums, n);
	for (int i = 0; i < n; ++i)
		if (nums[i] != i + 1)
			return i + 1;
	return n + 1;
}
void bucket_sort(vector<int>& nums, int n)
{
	for (int i = 0; i < n; ++i)
	{
		while (nums[i] != i + 1)
		{
			if (nums[i] <= 0 || nums[i]>n || nums[i] == nums[nums[i] - 1])
				break;
			swap(nums[i], nums[nums[i] - 1]);
		}
	}
}
int main(void)
{
	system("pause");
	return 0;
}