#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
还是利用排好序之后，夹逼找
*/
int threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() < 3)
		return 0;
	int min_gap = INT_MAX;
	int result = 0;
	sort(nums.begin(), nums.end());
	vector<int>::iterator begin = nums.begin();
	vector<int>::iterator end = nums.end() - 2;
	for (; begin < end;++begin)
	{
		vector<int>::iterator start = begin + 1;
		vector<int>::iterator over = nums.end() - 1;
		while (start < over)
		{
			int sum = *begin + *start + *over;
			int gap = abs(sum - target);
			if (gap < min_gap)
			{
				result = sum;
				min_gap = gap;
			}
			if (sum < target)
				++start;
			else
				--over;
		}
	}
	return result;
}
int main(void)
{
	vector<int> nums{ -1,2,1,4 };
	int result = threeSumClosest(nums, 1);
	cout << result << endl;
	system("pause");
	return 0;
}