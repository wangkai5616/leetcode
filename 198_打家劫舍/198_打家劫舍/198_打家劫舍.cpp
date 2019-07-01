#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int rob(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i % 2 == 1)
			sum1 = max(sum1 + nums[i], sum2);
		else
			sum2 = max(sum2 + nums[i], sum1);
	}
	return sum1 > sum2 ? sum1 : sum2;
}
int main(void)
{
	system("pause");
	return 0;
}