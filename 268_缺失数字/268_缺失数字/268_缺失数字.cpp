#include<iostream>
#include<vector>
using namespace std;
/*
思路是既然0到n之间少了一个数，我们将这个少了一个数的数组合0到n之间完整的数组异或一下，
那么相同的数字都变为0了，剩下的就是少了的那个数字了
*/
int missingNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
		result ^= (i + 1) ^ nums[i];
	return result;
}
/*
用等差数列的求和公式求出0到n之间所有的数字之和，然后再遍历数组算出给定数字的累积和，然后
做减法，差值就是丢失的那个数字
*/
int missingNumber(vector<int>& nums) 
{
	int sum = 0, n = nums.size();
	for (auto &a : nums) {
		sum += a;
	}
	return 0.5 * n * (n + 1) - sum;
}