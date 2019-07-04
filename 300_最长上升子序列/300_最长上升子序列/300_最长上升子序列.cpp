#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//动态规划版本
int lengthOfLIS(vector<int>& nums)
{
	int size = nums.size();
	if (size < 1)
		return 0;
	vector<int> record(size, 1);
	for (int j = 1; j < size; ++j)
	{
		for (int i = 0; i < j; ++i)
			if (nums[j]>nums[i] && record[j] < record[i] + 1)
				record[j] = record[i] + 1;
	}
	int result = 0;
	for (int i = 0; i < size; ++i)
	{
		if (record[i] > result)
			result = record[i];
	}
	return result;
}
/*
方法二：O(nlgn)
用到了二分查找法，所以才能加快运行时间哇。思路是，我们先建立一个数组ends，
把首元素放进去，然后比较之后的元素，如果遍历到的新元素比ends数组中的首元素
小的话，替换首元素为此新元素，如果遍历到的新元素比ends数组中的末尾元素还大
的话，将此新元素添加到ends数组末尾(注意不覆盖原末尾元素)。如果遍历到的新元素
比ends数组首元素大，比尾元素小时，此时用二分查找法找到第一个不小于此新元素的
位置，覆盖掉位置的原来的数字，以此类推直至遍历完整个nums数组，此时ends数组的
长度就是我们要求的LIS的长度，特别注意的是ends数组的值可能不是一个真实的LIS，比
如若输入数组nums为{4, 2， 4， 5， 3， 7}，那么算完后的ends数组为{2， 3， 5， 7}，
可以发现它不是一个原数组的LIS，只是长度相等而已。
*/
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	vector<int> ends;
	ends.push_back(nums[0]);
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] < ends[0])
			ends[0] = nums[i];
		else if (nums[i]>ends.back())
			ends.push_back(nums[i]);
		else
		{
			int left = 0, right = ends.size() - 1;
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (ends[mid] < nums[i])
					left = mid + 1;
				else
					right = mid;
			}
			ends[right] = nums[i];
		}
	}
	return ends.size();
}
int main(void)
{
	system("pause");
	return;
}