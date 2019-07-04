#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
};
/*
������һά�����������ֱ𱣴���ʼʱ��ͽ���ʱ�䣬Ȼ������Ÿ������Ƕ���
�������res�ͽ���ʱ��ָ�� endpos��Ȼ�����ǿ�ʼ�����������ǰ��ʼʱ��С��
����ʱ��ָ���ʱ�䣬��������1����֮����ʱ��ָ������1���������ǿ����ҳ�
�ص���ʱ��Σ��Ӷ������µĻ����ҡ�
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
	//�жϵ�i����ʼ��ʱ�����С��end[endpos]��˵����Ҫ���ӷ�����
	//����Ļ�����Ҫ���ӷ��䣬Ҳ���ǵ���������ٿ�ʼ
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