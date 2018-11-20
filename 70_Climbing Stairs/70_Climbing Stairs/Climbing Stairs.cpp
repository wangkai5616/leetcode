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
	int prev = 0;
	int cur = 1;
	for (int i = 1; i <= n; ++i)
	{
		int temp = cur;
		cur += prev;
		prev = temp;
	}
	return cur;
}
int main(void)
{
	int result = climbStairs(5);
	cout << result << endl;
	system("pause");
	return 0;
}