#include<iostream>
#include<vector>
using namespace std;
/*
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
说明：
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
*/
void rotateEdge(vector<vector<int>>&matrix, int a, int b, int c, int d);
void rotate(vector<vector<int>>& matrix)
{
	//a,b,c，d分别是一个正方形的左上角和右下角的坐标
	int a = 0;
	int b = 0;
	int c = matrix.size() - 1;
	int d = matrix.size() - 1;
	//一圈一圈旋转，正方形可以看成许多个套起来的
	while (a < c && b < d)
	{
		rotateEdge(matrix, a++, b++, c--, d--);
	}

}
void rotateEdge(vector<vector<int>>&matrix, int a, int b, int c, int d)
{
	int times = d - b;
	for (int i = 0; i != times; ++i)
	{
		int temp = matrix[a][b + i];
		matrix[a][b + i] = matrix[c-i][b];
		matrix[c - i][b] = matrix[c][d - i];
		matrix[c][d - i] = matrix[a+i][d];
		matrix[a + i][d] = temp;
	}
}
void print(vector<vector<int>>&matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
	rotate(matrix);
	print(matrix);
	system("pause");
	return 0;
}