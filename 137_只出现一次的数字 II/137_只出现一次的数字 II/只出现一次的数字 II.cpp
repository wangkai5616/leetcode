#include<iostream>
#include<vector>
using namespace std;
/*
给定一个非空整数数组，除了某个元素只出现一次以外，
其余每个元素均出现了三次。找出那个只出现了一次的元素。
*/
/*
思路：把数组中所有数字的二进制表示的每一位都加起来，如果某一位的和能被3整除，
那么那个只出现一次的数字二进制表示中对应的那一位是0；否则就是1。
*/
int singleNumber(vector<int>& nums)
{
	int bitSum[32] = { 0 };
	for (int i = 0; i < nums.size(); ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = bitMask & nums[i];
			if (bit != 0)
				bitSum[j] += 1;
			bitMask = bitMask << 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}