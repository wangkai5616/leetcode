#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��̬�滮�汾
int lengthOfLIS(vector<int>& nums)
{
	int size = nums.size();
	if (size < 1)
		return 0;
	vector<int> record(size, 1);
	for (int j = 1; j < size; ++j)
	{
		for (int i = 0; i < j; ++i)
			if (nums[j]>nums[i] && record[j] < record[i] + 1)
				record[j] = record[i] + 1;
	}
	int result = 0;
	for (int i = 0; i < size; ++i)
	{
		if (record[i] > result)
			result = record[i];
	}
	return result;
}
/*
��������O(nlgn)
�õ��˶��ֲ��ҷ������Բ��ܼӿ�����ʱ���ۡ�˼·�ǣ������Ƚ���һ������ends��
����Ԫ�طŽ�ȥ��Ȼ��Ƚ�֮���Ԫ�أ��������������Ԫ�ر�ends�����е���Ԫ��
С�Ļ����滻��Ԫ��Ϊ����Ԫ�أ��������������Ԫ�ر�ends�����е�ĩβԪ�ػ���
�Ļ���������Ԫ����ӵ�ends����ĩβ(ע�ⲻ����ԭĩβԪ��)���������������Ԫ��
��ends������Ԫ�ش󣬱�βԪ��Сʱ����ʱ�ö��ֲ��ҷ��ҵ���һ����С�ڴ���Ԫ�ص�
λ�ã����ǵ�λ�õ�ԭ�������֣��Դ�����ֱ������������nums���飬��ʱends�����
���Ⱦ�������Ҫ���LIS�ĳ��ȣ��ر�ע�����ends�����ֵ���ܲ���һ����ʵ��LIS����
������������numsΪ{4, 2�� 4�� 5�� 3�� 7}����ô������ends����Ϊ{2�� 3�� 5�� 7}��
���Է���������һ��ԭ�����LIS��ֻ�ǳ�����ȶ��ѡ�
*/
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	vector<int> ends;
	ends.push_back(nums[0]);
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] < ends[0])
			ends[0] = nums[i];
		else if (nums[i]>ends.back())
			ends.push_back(nums[i]);
		else
		{
			int left = 0, right = ends.size() - 1;
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (ends[mid] < nums[i])
					left = mid + 1;
				else
					right = mid;
			}
			ends[right] = nums[i];
		}
	}
	return ends.size();
}
int main(void)
{
	system("pause");
	return;
}