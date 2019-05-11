#include<iostream>
#include<vector>
using namespace std;
/*
����һ�������� n������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���

˼·���ο�ǰ����ǵ����Ƶ���
*/
void generateMatrixCore(vector<vector<int>> &matrix,
	int a, int b, int c, int d, int &i);
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>>result(n, vector<int>(n, 0));
	if (n < 1)
		return result;
	int a = 0;
	int b = 0;
	int c = n - 1;
	int d = n - 1;
	int i = 1;
	while (a <= c && b <= d)
		generateMatrixCore(result, a++, b++, c--, d--, i);
	return result;
}
void generateMatrixCore(vector<vector<int>> &matrix,
	int a, int b, int c, int d,int &i)
{
	if (a == c || b==d)
	{
		matrix[a][b] = i++;
		return;
	}
	int curX = a;
	int curY = b;
	while (curY != d)
	{
		matrix[a][curY] = i++;
		curY++;
	}
	while (curX != c)
	{
		matrix[curX][d] = i++;
		curX++;
	}
	while (curY != b)
	{
		matrix[c][curY] = i++;
		curY--;
	}
	while (curX != a)
	{
		matrix[curX][b] = i++;
		curX--;
	}
}
void print(vector<vector<int>> &result)
{
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<vector<int>> result = generateMatrix(5);
	print(result);
	system("pause");
	return 0;
}