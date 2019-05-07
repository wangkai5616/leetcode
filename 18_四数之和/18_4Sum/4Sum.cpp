#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	if (nums.size() < 4)
		return result;
	sort(nums.begin(), nums.end());
	auto a = nums.begin();
	for (; a < nums.end() - 3; ++a)
	{
		
		for (auto b = a+1; b < nums.end() - 2; ++b)
		{
			auto c = b+1;
			auto d = nums.end() - 1;
			while (c < d)
			{
				//cout << *a << " " << *b << " " << *c << " " << *d << endl;
				if (*a + *b + *c + *d < target)
					++c;
				else if (*a + *b + *c + *d > target)
					--d;
				else
				{
					result.push_back({ *a,*b,*c,*d });
					++c;
					--d;
				}
			}
		}
	}
	//必须先排序，因为unique只判断临近的
	sort(result.begin(), result.end());
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
	vector<int> nums = { 1,0,-1,0,-2,2 };
	vector<vector<int>> result = fourSum(nums, 0);
	print(result);
	system("pause");
	return 0;
}