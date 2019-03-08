#include<iostream>
using namespace std;
/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*/
double myPowCore(double x, int n);
double myPow(double x, int n)
{
	if (n < 0)
		return 1.0 / myPowCore(x, -n);
	else
		return myPowCore(x, n);
}
double myPowCore(double x, int n)
{
	if (n == 0)
		return 1;
	double d = myPowCore(x, n / 2);
	//n为偶数
	if (n % 2 == 0)
		return d*d;
	//n为奇数，还得多乘一个x
	else
		return d*d*x;
}
int main(void)
{

	system("pause");
	return 0;
}