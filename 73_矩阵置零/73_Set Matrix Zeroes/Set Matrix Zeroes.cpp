#include<iostream>
#include<vector>
using namespace std;
/*
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0����
�������к��е�����Ԫ�ض���Ϊ 0����ʹ��ԭ���㷨��
*/
/*
ʱ�临�Ӷ�Ϊ0(m*n)���ռ临�Ӷ�Ϊ0(m+n)
*/
void setZeroes1(vector<vector<int>>& matrix)
{
	if (matrix.size() < 1)
		return;
	int m = matrix.size();
	int n = matrix[0].size();
	//���ÿһ���Ƿ����0
	vector<bool> row(m, false);
	//���ÿһ���Ƿ����0
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
ʱ�临�Ӷ�Ϊ0(m*n)���ռ临�Ӷ�Ϊ0(1)
*/
void setZeroes2(vector<vector<int>>& matrix)
{
	size_t m = matrix.size();
	size_t n = matrix[0].size();
	bool row_has_zero = false;//��һ���Ƿ����0
	bool col_has_zero = false;//��һ���Ƿ����0
	for (size_t i = 0; i < n; ++i)
		if (matrix[0][i] == 0)
		{
			row_has_zero = true;//ֻҪ������һ��0���˳�ѭ��
			break;
		}
	for (size_t i = 0; i < m;++i)
		if (matrix[i][0] == 0)
		{
			col_has_zero = true;//ֻҪ������һ��0���˳�ѭ��
			break;
		}
	for (size_t i = 1; i < m; ++i)
	{
		for (size_t j = 1; j < n; ++j)
			//���ĳ��Ԫ�ص�ֵΪ0����ô����һ���׺���һ����Ԫ����Ϊ0
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
	}
	//�������˵�һ�к͵�һ��֮���ÿһ��Ԫ�أ�������׻�������Ϊ0��
	//��ô���Ԫ�ص�ֵ��Ϊ0
	for (size_t i = 1; i < m; ++i)
		for (size_t j = 1; j < n; ++j)
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
	//���ŶԵ�һ���׺͵�һ��β��������
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