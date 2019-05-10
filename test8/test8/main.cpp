#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int jump(vector<int>& nums)
{
	int length = nums.size();
	if (length == 1)
		return 0;
	int step = 0;
	int start = 0, end = 0;
	while (start <= end)
	{
		++step;
		int oldEnd = end;
		for (int i = start; i <= oldEnd; ++i)
		{
			int newRight = i + nums[i];
			if (newRight >= length - 1)
				return step;
			if (newRight > end)
				end = newRight;
		}
		start = oldEnd + 1;
	}
}
int main(void)
{
	char c = 'a' + 2;
	cout << c << endl;
	system("pause");
	return 0;
}

