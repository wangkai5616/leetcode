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
vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> result;
	if (intervals.empty())
		return result;
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
int main(void)
{
	system("pause");
	return 0;
}