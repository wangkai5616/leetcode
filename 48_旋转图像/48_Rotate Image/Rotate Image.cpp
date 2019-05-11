#include<iostream>
#include<vector>
using namespace std;
/*
����һ�� n �� n �Ķ�ά�����ʾһ��ͼ��
��ͼ��˳ʱ����ת 90 �ȡ�
˵����
�������ԭ����תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫʹ����һ����������תͼ��
*/
void rotateEdge(vector<vector<int>>&matrix, int a, int b, int c, int d);
void rotate(vector<vector<int>>& matrix)
{
	//a,b,c��d�ֱ���һ�������ε����ϽǺ����½ǵ�����
	int a = 0;
	int b = 0;
	int c = matrix.size() - 1;
	int d = matrix.size() - 1;
	//һȦһȦ��ת�������ο��Կ���������������
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