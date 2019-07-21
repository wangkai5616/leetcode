#include<iostream>
#include<vector>
using namespace std;
int countPrimes(int n)
{
	int result = 0;
	vector<bool> prime(n, true);
	for (int i = 2; i < n; ++i)
	{
		if (prime[i])
		{
			++result;
			for (int j = 2; i*j < n; ++j)
				prime[i*j] = false;
		}
	}
	return result;
}
