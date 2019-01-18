#include<iostream>
using namespace std;
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/
int climbStairs(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int *nums = new int[n + 1];
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	int i = 0;
	for (i = 3; i <= n; ++i)
		nums[i] = nums[i - 1] + nums[i - 2];
	return nums[i - 1];
}
int main(void)
{
	int result = climbStairs(5);
	cout << result << endl;
	system("pause");
	return 0;
}