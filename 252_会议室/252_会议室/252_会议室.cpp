#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
};
bool compareInterval(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}
/*
思路：按照开始时间进行排序，然后比较后一个的
开始时间和前一个的结束时间是否冲突
*/
bool canAttendMeetings(vector<Interval>& intervals)
{
	if (intervals.size() <= 1)
		return true;
	//sort(intervals.begin(), intervals.end(), compareInterval);//比较方法一
	sort(intervals.begin(), intervals.end(), 
		[](const Interval &a, const Interval &b) {return a.start < b.start; });
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i].start < intervals[i - 1].end)
			return false;
	}
	return true;
}

int main(void)
{
	system("pause");
	return 0;
}