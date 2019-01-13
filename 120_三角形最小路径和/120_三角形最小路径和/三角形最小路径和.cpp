#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
���磬���������Σ�
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
�Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����
*/

//��̬�滮���������Ϻ���
// ʱ�临�Ӷ� O(n^2)�ռ临�Ӷ� O(1)
//��״̬Ϊ f(i, j)����ʾ�Ӵ�λ�� (i, j) ������·������С�ͣ���״̬ת�Ʒ���Ϊ
//f(i, j) = min{ f(i, j + 1), f(i + 1, j + 1) } +(i, j)
int minimumTotal(vector<vector<int>>& triangle)
{
	for (int i = triangle.size() - 2; i >= 0; --i)
	{
		for (int j = 0; j < i + 1; ++j)
			//���º����µ���Сֵ�ӵ�ǰ��
			triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
	}
	return triangle[0][0];
}
int main(void)
{
	system("pause");
	return 0;
}