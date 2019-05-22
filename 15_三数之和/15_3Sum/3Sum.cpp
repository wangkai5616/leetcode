#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(const vector<vector<int>> &v);
/*
先排好序，从头至尾，先固定一个元素，然后求解剩下的两个
元素是通过左右加逼得到的，复杂度为O(n^2)
*/
vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	if (nums.empty() || nums.back() < 0 || nums.front() > 0) return{};
	for (int k = 0; k < nums.size(); ++k) {
		if (nums[k] > 0) break;
		if (k > 0 && nums[k] == nums[k - 1]) continue;
		int target = 0 - nums[k];
		int i = k + 1, j = nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] == target) {
				res.push_back({ nums[k], nums[i], nums[j] });
				while (i < j && nums[i] == nums[i + 1]) ++i;
				while (i < j && nums[j] == nums[j - 1]) --j;
				++i; --j;
			}
			else if (nums[i] + nums[j] < target) ++i;
			else --j;
		}
	}
	return res;
}
void print(const vector<vector<int>> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (auto j : v[i])
			cout << j << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result=threeSum(nums);
	print(result);
	system("pause");
	return 0;
}