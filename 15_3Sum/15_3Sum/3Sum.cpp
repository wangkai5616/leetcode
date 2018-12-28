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
	vector<vector<int>> result;
	if (nums.size() < 3)
		return result;
	int target = 0;
	sort(nums.begin(), nums.end());
	vector<int>::iterator begin = nums.begin();
	vector<int>::iterator end = nums.end() - 2;
	for (; begin < end; ++begin)
	{
		int need = target - *begin;
		vector<int>::iterator start = begin + 1;
		vector<int>::iterator over = nums.end() - 1;
		while (start < over)
		{
			if (*start + *over < need)
				++start;
			else if (*start + *over > need)
				--over;
			else
			{
				result.push_back({ *begin,*start,*over });
				++start;
				--over;
			}
		}
	}
	sort(result.begin(), result.end());
	/*
	unique并不会改变[first,last)的元素个数，有一些残留数据会留下来。可以用
	erase函数去除。
	unique会返回一个迭代器指向新区间的尾端，新区间之内不含相邻的重复元素
	*/
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
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