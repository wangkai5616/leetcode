#include<iostream>
#include<vector>
using namespace std;
/*
��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������

˼·�������Ͻ������½��ң�ʱ�临�Ӷ�Ϊ0(m+n)
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