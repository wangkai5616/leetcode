#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
double myPow(double x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n == -1)
		return 1 / x;
	int index = 0;
	if (n < 0)
	{
		index = 1;
		n = -n;
	}
	double k = myPow(x, n / 2);
	double result = 0;
	if (n % 2 == 1)
		result = k*k*x;
	else
		result = k*k;
	if (index>0)
		result = 1 / result;
	return result;
}
int main(void)
{
	cout << myPow(2, -1) << endl;
	system("pause");
	return 0;
}

