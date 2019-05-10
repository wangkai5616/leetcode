#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums)
{
	int k = -1;
	for (int i = nums.size() - 2; i >= 0; --i)
	{
		//找到最大的下标k，使得nums[k]<nums[k+1]
		if (nums[i] < nums[i + 1])
		{
			k = i;
			break;
		}
	}
	//这种情况说明vector中的数完全逆序
	if (k == -1)
	{
		reverse(nums.begin(), nums.end());
		return;
	}
	int l = -1;
	//从后往前找，找到k之后满足nums[k] < nums[l]的最大的下标i
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (nums[i] > nums[k])
		{
			l = i;
			break;
		}
	}
	swap(nums[k], nums[l]);
	/*
	当初找到的k，说明的是,从k往后的元素是从大到小排列，经过
	swap之后依然是从大到小，我们应该弄成从小到大，因为是找第一个
	排列大于题给定的序列
	*/
	reverse(nums.begin() + k + 1, nums.end());
}
int main(void)
{
	vector<int> v = { 1,2,3 };
	nextPermutation(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}