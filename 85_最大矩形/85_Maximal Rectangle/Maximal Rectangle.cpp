#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
示例:
输入:
[
["1","0","1","0","0"],
["1","0","1","1","1"],
["1","1","1","1","1"],
["1","0","0","1","0"]
]
输出: 6
*/
//该设计是单调栈中的小端栈，也就是从栈底到栈顶是从小到大
int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.empty() || matrix[0].empty())
		return 0;
	int result = 0;
	int m = matrix.size(), n = matrix[0].size();
	/*
	巧妙的地方，故意多加一位0，保证栈中的元素都会被计算，
	这样就不用再去判断栈中是否还有没出来的元素了
	*/
	vector<int> height(n + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		stack<int> s;
		for (int j = 0; j < n + 1; ++j)
		{
			//height中保存的是高度
			if (j < n)
				height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
			while (!s.empty() && height[s.top()] >= height[j])
			{
				int cur = s.top();
				s.pop();
				result = max(result, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
			}
			s.push(j);
		}
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}