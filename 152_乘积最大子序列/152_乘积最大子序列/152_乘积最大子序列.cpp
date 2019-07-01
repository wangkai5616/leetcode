#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//动态规划
/*
这道题最直接的方法就是用DP来做，而且要用两个dp数组，其中v1[i]
表示子数组[0, i]范围内并且一定包含nums[i]数字的最大子数组乘积，
v2[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最小子数组
乘积，初始化时v1[0]和v2[0]都初始化为nums[0]，其余都初始化为0。
那么从数组的第二个数字开始遍历，那么此时的最大值和最小值只会在
这三个数字之间产生，即v1[i-1]*nums[i]，v2[i-1]*nums[i]，和nums[i]。
所以我们用三者中的最大值来更新v1[i]，用最小值来更新v2[i]，然后用
v1[i]来更新结果res即可。
*/
int maxProduct(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int result = nums[0];
	int n = nums.size();
	vector<int> v1(n, 0);
	vector<int> v2(n, 0);
	v1[0] = nums[0];
	v2[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		v1[i] = max(max(v1[i - 1] * nums[i], v2[i - 1] * nums[i]), nums[i]);
		v2[i] = min(min(v1[i - 1] * nums[i], v2[i - 1] * nums[i]), nums[i]);
		result = max(result, v1[i]);
	}
	return result;
}