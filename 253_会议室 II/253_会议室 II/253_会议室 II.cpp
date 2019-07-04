#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
};
/*
用两个一维数组来做，分别保存起始时间和结束时间，然后各自排个序，我们定义
结果变量res和结束时间指针 endpos，然后我们开始遍历，如果当前起始时间小于
结束时间指针的时间，则结果自增1，反之结束时间指针自增1，这样我们可以找出
重叠的时间段，从而安排新的会议室。
*/
int minMeetingRooms(vector<Interval>& intervals)
{
	vector<int> starts;
	vector<int> ends;
	int result = 0, endpos = 0;
	for (int i = 0; i < intervals.size(); ++i)
	{
		starts.push_back(intervals[i].start);
		ends.push_back(intervals[i].end);
	}
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());
	//判断第i个开始的时候，如果小于end[endpos]，说明需要增加房间了
	//否则的话不需要增加房间，也就是等你结束我再开始
	for (int i = 0; i < intervals.size(); ++i)
	{
		if (starts[i] < ends[endpos])
			++result;
		else
			++endpos;
	}
	return result;
}

int main(void)
{
	system("pause");
	return 0;
}