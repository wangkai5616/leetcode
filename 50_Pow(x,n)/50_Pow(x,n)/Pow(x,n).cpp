#include<iostream>
using namespace std;
/*
ʵ�� pow(x, n) �������� x �� n ���ݺ�����
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
	//nΪż��
	if (n % 2 == 0)
		return d*d;
	//nΪ���������ö��һ��x
	else
		return d*d*x;
}
int main(void)
{

	system("pause");
	return 0;
}