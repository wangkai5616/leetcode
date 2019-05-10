#include<iostream>
#include<string>
using namespace std;
int divide(int dividend, int divisor)
{
	long long a = dividend > 0 ? dividend : -(long long)dividend;
	long long b = divisor > 0 ? dividend : -(long long)dividend;
	long long result = 0;
	while (a > b)
	{
		long long c = b;
		for (int i = 0; a >= c; ++i, c << 1)
		{
			a -= c;
			result += 1 << i;
		}
	}
}

int main(void)
{

	system("pause");
	return 0;
}

