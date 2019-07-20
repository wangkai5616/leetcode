#include<iostream>
using namespace std;
bool isPowerOfThree(int n)
{
	if (n == 1)
		return true;

	if (n == 0 || n == 2 || n % 3 != 0)
		return false;
	return isPowerOfThree(n / 3);
}