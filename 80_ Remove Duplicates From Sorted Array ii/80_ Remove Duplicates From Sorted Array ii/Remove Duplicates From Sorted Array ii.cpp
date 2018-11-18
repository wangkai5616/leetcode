#include<iostream>
#include<vector>
using namespace std;
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/
int removeDuplicates1(vector<int>& nums)
{
	if (nums.size() < 3)
		return nums.size();
	//如果数组中已经出现两次同样的元素，那么help=1
	int help = 0;
	for (auto iter = nums.begin() + 1; iter != nums.end();)
	{
		if (*iter == *(iter - 1) && help == 1)
			//这时这个方法的最大缺点，删除元素需要移动的元素较多，所以时间复杂度高
			iter = nums.erase(iter);
		else if (*iter == *(iter - 1) && help == 0)
		{
			++iter;
			help = 1;
		}
		else
		{
			++iter;
			help = 0;
		}
	}
	return nums.size();
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