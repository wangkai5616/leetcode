#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ������ļ��ϣ���ϲ������ص������䡣

ʾ�� 1:

����: [[1,3],[2,6],[8,10],[15,18]]
���: [[1,6],[8,10],[15,18]]
����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> result;
	if (intervals.empty())
		return result;
	//��intervals�е�Ԫ�ذ���start��С�����˳���������
	sort(intervals.begin(), intervals.end(),
		[](const Interval& i1, const Interval& i2) {return i1.start < i2.start; });
	result.push_back(intervals[0]);
	int cur = 0;
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i].start > result[cur].end)
		{
			result.push_back(intervals[i]);
			cur++;//curʼ�ձ���result���������һ��Ԫ�ص��±�
		}
		else
			result[cur].end = max(intervals[i].end, result[cur].end);
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}