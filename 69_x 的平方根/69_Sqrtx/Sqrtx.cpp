#include<iostream>
using namespace std;
/*
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*/
//利用二分查找进行求解
int mySqrt(int x)
{
	if (x <= 1)
		return x;
	int start = 1;
	int end = x / 2;
	while (start <= end)
	{
		//long long还是有必要的，因为你是从二分之一出开始平方，可能超过最大值
		long long mid = (start + end) / 2;
		long long sq = mid*mid;
		if (sq == x)
			return mid;
		else if (sq > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return end;
}
int main(void)
{
	int result = mySqrt(4);
	cout << result << endl;
	system("pause");
	return 0;
}