#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
*/
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
//将这个newInterval插入intervals，然后就和56题一样了
//但是这样的时间复杂度较高，因为intervals本来就是有序，还得重新再排一遍
vector<Interval> insert1(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval> result;
	intervals.push_back(newInterval);
	//将intervals中的元素按照start从小到大的顺序进行排序
	sort(intervals.begin(), intervals.end(),
		[](const Interval& i1, const Interval& i2) {return i1.start < i2.start; });
	result.push_back(intervals[0]);
	int cur = 0;
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i].start > result[cur].end)
		{
			result.push_back(intervals[i]);
			cur++;//cur始终保持result容器中最后一个元素的下标
		}
		else
			result[cur].end = max(intervals[i].end, result[cur].end);
	}
	return result;
}

//时间复杂度O(n)
vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval)
{
	auto it = intervals.begin();
	while (it != intervals.end())
	{
		//新来的newInterval的肯定大于it指向的值
		if (newInterval.start > it->end)
			it++;
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