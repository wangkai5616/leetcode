#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
*/
//时间复杂度为0(n)
void sortColors(vector<int>& nums)
{
	if (nums.size() < 1)
		return;
	int i = 0;
	//小于1的最后一个元素的下标
	int left = -1;
	//大于1的第一个元素的下标
	int right = nums.size();
	while (i<right)
	{
		if (nums[i] < 1)
			swap(nums[++left], nums[i++]);
		else if (nums[i] > 1)
			swap(nums[--right], nums[i]);
		else
			i++;
	}
}
int main(void)
{
	vector<int> v = { 2,0,2,1,1,0 };
	sortColors(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}