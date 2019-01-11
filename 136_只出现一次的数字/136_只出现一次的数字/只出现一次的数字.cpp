#include<iostream>
#include<vector>
using namespace std;
/*
给定一个非空整数数组，除了某个元素只出现一次以外，
其余每个元素均出现两次。找出那个只出现了一次的元素。
*/
//思路：两个相同数字异或结果为0
int singleNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
		result ^= nums[i];
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}