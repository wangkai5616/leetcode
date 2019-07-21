#include<iostream>
#include<unordered_set>
using namespace std;
bool isHappy(int n)
{
	unordered_set<int> us;
	while (n != 1)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10)*(n % 10);
			n /= 10;
		}
		n = sum;
		if (us.count(n))
			return false;
		us.insert(n);
	}
	return true;
}