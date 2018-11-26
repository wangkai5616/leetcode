#include<iostream>
#include<vector>
using namespace std;
/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
��������в�����Ŀ��ֵ������ [-1, -1]��
*/
vector<int> searchRange(vector<int>& nums, int target)
{
	int length = nums.size();
	int low = 0, high = length - 1;
	int mid = 0;
	//�����������ڱ����ҵ��Ŀ�ʼλ�úͽ���λ��
	vector<int> result(2, -1);
	if (length == 0)
		return result;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (target == nums[mid])
		{
			int i = mid;//����߼���Ѱ��
			int j = mid;//���ұ߼���Ѱ��
			while (i >= 0 && (nums[i] == target)) i--;
			if (i < 0)
				result[0] = 0;
			else
				result[0] = i + 1;
			while (j < length && (nums[j] == target)) j++;
			if (j > length)
				result[1] = nums[length - 1];
			else
				result[1] = j - 1;
			return result;
		}
		else if (target < nums[mid])	//С��
			high = mid - 1;
		else if (target > nums[mid])	//����
			low = mid + 1;
	}
	return result;
}
int main(void)
{
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> v=searchRange(nums, 8);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}