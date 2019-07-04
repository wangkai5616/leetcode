#include<iostream>
#include<vector>
using namespace std;
/*
对于每个数字nums[i]，如果其对应的nums[nums[i] - 1]是正数，我们就赋
值为其相反数，如果已经是负数了，就不变了，那么最后我们只要把留下的整
数对应的位置加入结果res中即可。
*/
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		int idx = abs(nums[i]) - 1;
		nums[idx] = (nums[idx] > 0) ? -nums[idx] : nums[idx];
	}
	cout << endl;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > 0) {
			res.push_back(i + 1);
		}
	}
	return res;
}
int main(void)
{
	vector<int> v = { 4,3,2,7,8,2,3,1 };
	vector<int> result=findDisappearedNumbers(v);
	for (auto a : result)
		cout << a << "	";
	cout << endl;
	system("pause");
	return 0;
}