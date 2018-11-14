#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给出一个区间的集合，请合并所有重叠的区间。

思路：先按照元素的start排好序，然后再选择性的合并，
合并的条件当然就是后一项的start小于前一项的end
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
	//以intervals里面元素的start进行由小到大的排序
	sort(intervals.begin(), intervals.end(), [](Interval const& i1, Interval const& i2) {return i1.start < i2.start; });

	res.push_back(intervals[0]);
	int cur = 0;
	//永远是后面的元素的start和前一个元素的end进行比较
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