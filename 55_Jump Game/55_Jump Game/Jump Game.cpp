#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
*/
/*
思路：从0出发，一层一层往上跳，看最后能不能超过最高层，
能超过，说明就能到达，否则不能到达。
时间复杂度O(n)，空间复杂度O(1)
*/
bool canJump(vector<int>& nums)
{
	int length = nums.size();
	//最右能跳到的下标
	int reach = 0;
	for (int i = 0; i <= reach && reach < length; ++i)
		reach = max(reach, i + nums[i]);
	return reach >= length-1;
}
/*
思路：动规，设状态为 f[i]，表示从第 0 层出发，走到 A[i] 时剩
余的最大步数，则状态转移方程为：
f[i] = max(f[i ? 1], A[i ? 1])-1,i>0
时间复杂度O(n)，空间复杂度O(n)
*/
bool canJump2(vector<int>& nums)
{
	int length = nums.size();
	//从0层出发，走到v[i]时剩余的最大步数，也就是最多还能
	//往前走几步
	vector<int> v(length, 0);
	v[0] = 0;
	for (int i = 1; i < length; ++i)
	{
		v[i] = max(v[i - 1], nums[i - 1]) - 1;
		if (v[i] < 0)
			return false;
	}
	return true;
}
int main(void)
{
	system("pause");
	return 0;
}