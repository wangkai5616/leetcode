#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
/*
����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ��������������
ʾ��:
����:
[
["1","0","1","0","0"],
["1","0","1","1","1"],
["1","1","1","1","1"],
["1","0","0","1","0"]
]
���: 6
*/
//������ǵ���ջ�е�С��ջ��Ҳ���Ǵ�ջ�׵�ջ���Ǵ�С����
int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.empty() || matrix[0].empty())
		return 0;
	int result = 0;
	int m = matrix.size(), n = matrix[0].size();
	/*
	����ĵط���������һλ0����֤ջ�е�Ԫ�ض��ᱻ���㣬
	�����Ͳ�����ȥ�ж�ջ���Ƿ���û������Ԫ����
	*/
	vector<int> height(n + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		stack<int> s;
		for (int j = 0; j < n + 1; ++j)
		{
			//height�б�����Ǹ߶�
			if (j < n)
				height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
			while (!s.empty() && height[s.top()] >= height[j])
			{
				int cur = s.top();
				s.pop();
				result = max(result, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
			}
			s.push(j);
		}
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}