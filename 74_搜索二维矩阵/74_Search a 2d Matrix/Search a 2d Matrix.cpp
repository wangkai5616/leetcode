#include<iostream>
#include<vector>
using namespace std;
/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

思路：从右上角往左下角找，时间复杂度为0(m+n)
*/
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.size() < 1)
		return false;
	int m = matrix.size();
	int n = matrix[0].size();
	int i = 0;
	int j = n - 1;
	while (i < m && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			--j;
		else
			++i;
	}
	return false;
}
int main(void)
{
	system("pause");
	return 0;
}