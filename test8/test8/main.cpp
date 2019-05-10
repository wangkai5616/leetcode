#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int search(vector<int>& nums, int target)
{
	int begin = 0;
	int end = nums.size() - 1;
	int k = 0;
	while (begin <= end)
	{
		k = (begin + end) / 2;
		if (nums[k] == target)
			return k;
		else if (nums[begin] < nums[k])
		{
			if (target < nums[k])
				end = k - 1;
			else
				begin = k + 1;
		}
		else
		{
			if (target > nums[k])
				begin = k + 1;
			else
				end = k - 1;
		}			
	}
	return -1;
}
int main(void)
{
	vector<int> v = { 4,5,6,7,0,1,2 };
	cout << search(v, 0) << endl;
	system("pause");
	return 0;
}

