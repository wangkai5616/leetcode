#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
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
// 时间复杂度 O(n1+n2+...)空间复杂度 O(1)
vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> result;
	for (int i = 0; i < intervals.size(); ++i)
		insert(result, intervals[i]);
	return result;
}
//时间复杂度O(n)
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	auto it = intervals.begin();
	while (it != intervals.end())
	{
		//新来的newInterval的肯定大于it指向的值
		if (newInterval.start > it->end)
			++it;
		//新来的newInterval的肯定大于it指向的值
		//所以，找到了位置，进行插入
		else if (newInterval.end < it->start)
		{
			intervals.insert(it, newInterval);
			return intervals;
		}
		//新来的newInterval的和it指向的值进行合并，然后删除
		//原来it指向的值，重新构造新来的newInterval
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