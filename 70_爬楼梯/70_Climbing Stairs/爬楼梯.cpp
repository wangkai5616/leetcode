#include<iostream>
using namespace std;
/*
������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
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