#include<iostream>
#include<vector>
using namespace std;
/*
�����ö����������ˣ����������� [1, n] ����������������е� mid��Ȼ��
�����������飬ͳ������С�ڵ��� mid �����ĸ������������С�ڵ��� mid��
��˵���ظ�ֵ�� [mid+1, n] ֮�䣬��֮���ظ�ֵӦ�� [1, mid-1] ֮�䣬Ȼ��
�������ƣ�ֱ��������ɣ���ʱ�� right ��������Ҫ����ظ�ֵ
*/
int findDuplicate(vector<int>& nums)
{
	int left = 0, right = nums.size();
	int mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		int cnt = 0;
		for (int num : nums)
			if (num <= mid)
				++cnt;
		if (cnt <= mid)
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}