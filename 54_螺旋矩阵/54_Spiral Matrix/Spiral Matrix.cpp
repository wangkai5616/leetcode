#include<iostream>
#include<vector>
using namespace std;
/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），
请按照顺时针螺旋顺序，返回矩阵中的所有元素。
*/
void spiralOrderCore(vector<vector<int>>& matrix, vector<int> &v,
	int a, int b, int c, int d);
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> result;
	while (matrix.size() < 1)
		return result;
	int a = 0;
	int b = 0;
	int c = matrix.size() - 1;
	int d = matrix[0].size()-1;
	while (a <= c && b <= d)
	{
		spiralOrderCore(matrix, result, a++, b++, c--, d--);
	}
	return result;
}
void spiralOrderCore(vector<vector<int>>& matrix, vector<int> &v,
	int a, int b, int c, int d)
{
	if (a == c)
	{
		while (b <= d)
		{
			v.push_back(matrix[a][b]);
			++b;
		}
		return;
	}
	if (b == d)
	{
		while (a <= c)
		{
			v.push_back(matrix[a][b]);
			++a;
		}
		return;
	}
	int curX = a;
	int curY = b;
	while (curY != d)
	{
		v.push_back(matrix[a][curY]);
		curY++;
	}
	while (curX != c)
	{
		v.push_back(matrix[curX][d]);
		curX++;
	}
	while (curY != b)
	{
		v.push_back(matrix[c][curY]);
		curY--;
	}
	while (curX != a)
	{
		v.push_back(matrix[curX][b]);
		curX--;
	}
}
int main(void)
{
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<int> result = spiralOrder(matrix);
	for (auto i : result)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}