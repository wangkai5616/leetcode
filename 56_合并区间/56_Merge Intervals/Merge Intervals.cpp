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
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	vector<vector<int>> result;
	vector<Interval> v;
	for (int i = 0; i < intervals.size(); ++i)
		v.push_back(Interval(intervals[i][0], intervals[i][1]));
	vector<Interval> vI = merge(v);
	for (int i = 0; i < vI.size(); ++i)
	{
		vector<int> v;
		v.push_back(vI[i].start);
		v.push_back(vI[i].end);
		result.push_back(v);
	}
	return result;
}
// ʱ�临�Ӷ� O(n1+n2+...)�ռ临�Ӷ� O(1)
vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> result;
	for (int i = 0; i < intervals.size(); ++i)
		insert(result, intervals[i]);
	return result;
}
//ʱ�临�Ӷ�O(n)
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	auto it = intervals.begin();
	while (it != intervals.end())
	{
		//������newInterval�Ŀ϶�����itָ���ֵ
		if (newInterval.start > it->end)
			++it;
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