#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> result;
	if (nums.size() == 0 || k < 1)
		return result;
	deque<int> d;
	for (int i = 0; i < nums.size(); ++i)
	{
		while (!d.empty() && nums[d.back()] <= nums[i])
			d.pop_back();
		d.push_back(i);
		if (d.front() == i - k)
			d.pop_front();
		if (i >= k - 1)
			result.push_back(nums[d.front()]);
	}
	return result;
}
int main()
{
	vector<int> v = { 1,3,-1,-3,5,3,6,7 };
	vector<int> result = maxSlidingWindow(v, 3);
	system("pasue");
	return 0;
}