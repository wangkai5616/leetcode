#include<iostream>
#include<vector>
using namespace std;
/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/
void swap(vector<int>& nums, int a, int b);
int removeElement1(vector<int>& nums, int val)
{
	if (nums.size() < 1)
		return 0;
	int index = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != val)
			nums[index++] = nums[i];
	}
	return index;
}

int removeElement2(vector<int>& nums, int val)
{
	if (nums.size() < 1)
		return 0;
	int length = nums.size();
	for (int i = 0; i < length; ++i)
	{
		if (nums[i] == val)
		{
			swap(nums,i,length-1);
			length--;
			i--;
		}
		
	}
	return length;
}
void swap(vector<int>& nums,int a, int b)
{
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

int main(void)
{
	vector<int> v = { 0,1,2,2,3,0,4,2,8,9};
	int result = removeElement1(v, 2);
	cout << result << endl;
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}

