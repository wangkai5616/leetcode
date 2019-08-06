#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k)
{
	if (nums.empty() || k%nums.size() == 0)
		return;
	int n = nums.size();
	reverse(nums.begin(), nums.begin() + n - k);//reverse���������һ��Ԫ��
	reverse(nums.begin() + n - k, nums.end());
	reverse(nums.begin(), nums.end());
	return;
}