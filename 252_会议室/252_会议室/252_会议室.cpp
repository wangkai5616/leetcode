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
˼·�����տ�ʼʱ���������Ȼ��ȽϺ�һ����
��ʼʱ���ǰһ���Ľ���ʱ���Ƿ��ͻ
*/
bool canAttendMeetings(vector<Interval>& intervals)
{
	if (intervals.size() <= 1)
		return true;
	//sort(intervals.begin(), intervals.end(), compareInterval);//�ȽϷ���һ
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