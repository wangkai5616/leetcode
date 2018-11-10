#include<iostream>
#include<vector>
using namespace std;
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() < 1)
		return 0;
	int index = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != nums[index])
			nums[++index] = nums[i];
	}
	return index + 1;
}
int main(void)
{
	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
	int result = removeDuplicates(v);
	cout << result << endl;
	for (int i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}