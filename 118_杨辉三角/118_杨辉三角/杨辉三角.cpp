#include<iostream>
#include<vector>
using namespace std;
//杨辉三角
vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> result;
	if (numRows == 0)
		return result;
	//第一行元素,(1,1)代表的是vector的大小是1，每个元素都是1
	result.push_back(vector<int>(1, 1));
	for (int i = 2; i <= numRows; ++i)
	{
		//第i行有i个元素
		vector<int> current(i, 1);
		//本来应该是减1，但是下标是从0开始的
		const vector<int> &prev = result[i - 2];
		for (int j = 1; j < i - 1; ++j)
			current[j] = prev[j - 1] + prev[j];
		result.push_back(current);
	}
	return result;
}

int main(void)
{
	system("pause");
	return 0;
}