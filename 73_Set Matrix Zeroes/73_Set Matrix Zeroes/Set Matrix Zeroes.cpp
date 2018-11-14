#include<iostream>
#include<vector>
using namespace std;
/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将
其所在行和列的所有元素都设为 0。请使用原地算法。
*/
/*
时间复杂度为0(m*n)，空间复杂度为0(m+n)
*/
void setZeroes1(vector<vector<int>>& matrix)
{
	if (matrix.size() < 1)
		return;
	int m = matrix.size();
	int n = matrix[0].size();
	//标记每一行是否存在0
	vector<bool> row(m, false);
	//标记每一列是否存在0
	vector<bool> col(n, false);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (matrix[i][j] == 0)
				row[i] = col[j] = true;
	for (int i = 0; i < m; ++i)
		if (row[i])
			fill(&matrix[i][0], &matrix[i][0] + n, 0);
	for (int j = 0; j < n;++j)
		if (col[j])
		{
			for (int i = 0; i < m; ++i)
				matrix[i][j] = 0;
		}
}
/*
时间复杂度为0(m*n)，空间复杂度为0(1)
*/
void setZeroes2(vector<vector<int>>& matrix)
{
	size_t m = matrix.size();
	size_t n = matrix[0].size();
	bool row_has_zero = false;//第一行是否存在0
	bool col_has_zero = false;//第一列是否存在0
	for (size_t i = 0; i < n; ++i)
		if (matrix[0][i] == 0)
		{
			row_has_zero = true;//只要发现有一个0就退出循环
			break;
		}
	for (size_t i = 0; i < m;++i)
		if (matrix[i][0] == 0)
		{
			col_has_zero = true;//只要发现有一个0就退出循环
			break;
		}
	for (size_t i = 1; i < m; ++i)
	{
		for (size_t j = 1; j < n; ++j)
			//如果某个元素的值为0，那么将这一行首和这一列首元素设为0
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
	}
	//遍历除了第一行和第一列之外的每一个元素，如果行首或者列首为0，
	//那么这个元素的值就为0
	for (size_t i = 1; i < m; ++i)
		for (size_t j = 1; j < n; ++j)
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
	//最后才对第一行首和第一行尾进行设置
	if (row_has_zero)
		for (size_t i = 0; i < n; ++i)
			matrix[0][i] = 0;
	if (col_has_zero)
		for (size_t i = 0; i < m; ++i)
			matrix[i][0] = 0;
}
int main(void)
{
	system("pause");
	return 0;
}