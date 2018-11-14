#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ������ļ��ϣ���ϲ������ص������䡣

˼·���Ȱ���Ԫ�ص�start�ź���Ȼ����ѡ���Եĺϲ���
�ϲ���������Ȼ���Ǻ�һ���startС��ǰһ���end
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};
vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> res;
	if (intervals.empty())
		return res;
	//��intervals����Ԫ�ص�start������С���������
	sort(intervals.begin(), intervals.end(), [](Interval const& i1, Interval const& i2) {return i1.start < i2.start; });

	res.push_back(intervals[0]);
	int cur = 0;
	//��Զ�Ǻ����Ԫ�ص�start��ǰһ��Ԫ�ص�end���бȽ�
	for (int i = 1; i < intervals.size(); ++i) {
		if (intervals[i].start > res[cur].end) {
			res.push_back(intervals[i]);
			cur++;
		}
		else {
			res[cur].end = max(res[cur].end, intervals[i].end);
		}
	}
	return res;
}



int main(void)
{
	Interval i1(1, 3);
	Interval i2(2, 6);
	Interval i3(8, 10);
	Interval i4(15, 18);
	vector<Interval> v;
	v.push_back(i1);
	v.push_back(i2);
	v.push_back(i3);
	v.push_back(i4);
	vector<Interval> result = merge(v);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i].start << " " << result[i].end << endl;
	}
	system("pause");
	return 0;
}