#include<iostream>
using namespace std;
/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。
*/
/*
思路：不断减去被除数。在这个基础上，可以做一点优化，每次把被除数翻倍，从
而加速。如果过大，就重新返回从初始的被除数重新开始。
时间复杂度 O(logn)，空间复杂度 O(1)
*/
int divide(int dividend, int divisor)
{
	// 当 dividend = INT_MIN 时，-dividend 会溢出，所以用 long long
	//也就是说-INT_MIN/-1,转为正数之后就会溢出
	long long a = dividend >= 0 ? dividend : -(long long)dividend;
	long long b = divisor >= 0 ? divisor : -(long long)divisor;
	// 当 dividend = INT_MIN 时，divisor = -1 时，结果会溢出，所以用 long long
	long long result = 0;
	while (a >= b) 
	{
		long long c = b;
		for (int i = 0; a >= c; ++i, c <<= 1) {
			a -= c;
			result += 1 << i;
		}
	}
	result = ((dividend^divisor) >> 31) ? (-result) : (result);
	//针对-2147483648,-1这种特殊情况进行处理
	return result > INT_MAX ? INT_MAX : (int)result;
}
int main(void)
{
	int result = divide(16, 3);
	cout << result << endl;
	system("pause");
	return 0;
}