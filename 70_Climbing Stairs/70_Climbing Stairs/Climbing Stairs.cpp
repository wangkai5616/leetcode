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