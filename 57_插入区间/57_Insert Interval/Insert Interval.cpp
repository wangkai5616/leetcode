#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ�����ص��� ������������ʼ�˵�����������б�
���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��

ʾ�� 1:

����: intervals = [[1,3],[6,9]], newInterval = [2,5]
���: [[1,5],[6,9]]
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
//�����newInterval����intervals��Ȼ��ͺ�56��һ����
//����������ʱ�临�ӶȽϸߣ���Ϊintervals�����������򣬻�����������һ��
vector<Interval> insert1(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval> result;
	intervals.push_back(newInterval);
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

//ʱ�临�Ӷ�O(n)
vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval)
{
	auto it = intervals.begin();
	while (it != intervals.end())
	{
		//������newInterval�Ŀ϶�����itָ���ֵ
		if (newInterval.start > it->end)
			it++;
		//������newInterval�Ŀ϶�����itָ���ֵ
		//���ԣ��ҵ���λ�ã����в���
		else if (newInterval.end < it->start)
		{
			intervals.insert(it, newInterval);
			return intervals;
		}
		//������newInterval�ĺ�itָ���ֵ���кϲ���Ȼ��ɾ��
		//ԭ��itָ���ֵ�����¹���������newInterval
		else
		{
			newInterval.start = min(newInterval.start, it->start);
			newInterval.end = max(newInterval.end, it->end);
			it = intervals.erase(it);
		}
	}
	intervals.insert(intervals.end(), newInterval);
	return intervals;
}
int main(void)
{
	system("pause");
	return 0;
}