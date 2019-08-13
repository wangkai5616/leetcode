#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	Solution(vector<int>& nums):v(nums) {}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res = v;
		int n = res.size();
		for (int i = 0; i < n; ++i)
		{
			int t = i + rand() % (n - i);
			swap(res[i], res[t]);
		}
		return res;
	}
private:
	vector<int> v;
};