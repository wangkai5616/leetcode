#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/

//动态规划，从下往上好算
// 时间复杂度 O(n^2)空间复杂度 O(1)
//设状态为 f(i, j)，表示从从位置 (i, j) 出发，路径的最小和，则状态转移方程为
//f(i, j) = min{ f(i, j + 1), f(i + 1, j + 1) } +(i, j)
int minimumTotal(vector<vector<int>>& triangle)
{
	for (int i = triangle.size() - 2; i >= 0; --i)
	{
		for (int j = 0; j < i + 1; ++j)
			//左下和右下的最小值加当前数
			triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
	}
	return triangle[0][0];
}
int main(void)
{
	system("pause");
	return 0;
}