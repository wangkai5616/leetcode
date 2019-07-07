#include<iostream>
using namespace std;
int getSum(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	int jin = 0;
	int c = 0;
	do {
		c = a^b;
		jin = (a&b) << 1;
		a = c;
		b = jin;
	} while (b != 0);
	return a;
}