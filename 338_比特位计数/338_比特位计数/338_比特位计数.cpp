#include<iostream>
#include<vector>
using namespace std;
int countBit(int value)
{
	int count = 0;
	while (value)
	{
		++count;
		value = value&(value - 1);
	}
	return count;
}
vector<int> countBits(int num)
{
	vector<int> result;
	int sum = 0;
	for (int i = 0; i <= num; ++i)
		result.push_back(countBit(i));
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}