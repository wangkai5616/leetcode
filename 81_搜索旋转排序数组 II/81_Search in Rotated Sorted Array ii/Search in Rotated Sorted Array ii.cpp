#include<iostream>
#include<vector>
using namespace std;
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
*/
/*
分析：允许重复元素，则上一题中如果 A[m]>=A[l], 那么 [l,m] 为递增序列的假设就不能成立了，比
如 [1,3,1,1,1]。
如果 A[m]>=A[l] 不能确定递增，那就把它拆分成两个条件：
1.若 A[m]>A[l]，则区间 [l,m] 一定递增
2.若 A[m]==A[l] 确定不了，那就 l++，往下看一步即可
*/
//时间复杂度 O(n)，空间复杂度 O(1)
bool search(vector<int>& nums, int target)
{
	int first = 0;
	int last = nums.size();
	int mid = 0;
	while (first != last)
	{
		mid = (first + last) / 2;
		if (nums[mid] == target)
			return true;
		//说明左半部分是递增的，没有受到旋转的影响
		if (nums[first] < nums[mid])
		{
			if (nums[first] <= target && target < nums[mid])
				last = mid;
			else
				first = mid + 1;
		}
		//说明左半部分不是递增，右半部分是递增
		else if (nums[first] > nums[mid])
		{
			if (nums[mid] < target && target <= nums[last - 1])
				first = mid + 1;
			else
				last = mid;
		}
		else
			first++;
	}
	return false;
}
int main(void)
{
	vector<int> v = { 1,3,1,1 };
	bool b = search(v, 3);
	if (b)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}