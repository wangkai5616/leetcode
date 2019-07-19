#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
�ⷨһ��������Ԫ�ط�����н��в���
*/
int kthSmallest(vector<vector<int>>& matrix, int k)
{
	priority_queue<int> q;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			q.emplace(matrix[i][j]);
			if (q.size() > k)
				q.pop();
		}
	}
	return q.top();
}
/*
˼·����������Ҳ�����ö��ֲ��ҷ��������������������������ô���Ͻǵ�����
һ������С�ģ������½ǵ�����һ�������ģ�������������������ķ�Χ��Ȼ������
����м�����mid�����ھ����в�ͬ��֮���Ԫ�ز������ϸ�����ģ���������Ҫ��ÿһ
�ж�����һ�� mid������ʹ�� upper_bound����������ǲ��ҵ�һ������Ŀ������Ԫ�أ�
���Ŀ�����ڱȸ��е�βԪ�ش��� upper_bound ���ظ���Ԫ�صĸ��������Ŀ������
������Ԫ��С���� upper_bound ����0, ���Ǳ��������е��п����ҳ��м����ǵڼ�С������Ȼ��k�Ƚϣ�
���ж��ֲ��ң�left �� right ���ջ���ȣ����һ��������е�kС�����֡�
*/
int kthSmallest(vector<vector<int>>& matrix, int k) {
	int left = matrix[0][0], right = matrix.back().back();
	while (left < right) {
		int mid = left + (right - left) / 2, cnt = 0;
		for (int i = 0; i < matrix.size(); ++i) 
		{
			cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
		}
		if (cnt < k) left = mid + 1;
		else right = mid;
	}
	return left;
}
int main(void)
{
	vector<vector<int>> v = { {1,5,9},{10,11,13},{12,13,15} };
	int k = kthSmallest(v, 18);
	cout << k << endl;
	system("pause");
	return 0;
}