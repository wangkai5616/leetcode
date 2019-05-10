#include<iostream>
#include<vector>
using namespace std;
/*
����һ��δ������������飬�ҳ�����û�г��ֵ���С����������
ʾ�� 1:
����: [1,2,0]
���: 3
ʾ�� 2:
����: [3,4,-1,1]
���: 2
ʾ�� 3:
����: [7,8,9,11,12]
���: 1
˵��:
����㷨��ʱ�临�Ӷ�ӦΪO(n)������ֻ��ʹ�ó�������Ŀռ䡣
*/
/*
˼·����������Ͱ���� (bucket sort)��ÿ�� A[i]!= i+1 ��ʱ�򣬽� A[i] �� A[A[i]-1] ������ֱ���޷�
����Ϊֹ����ֹ������ A[i]== A[A[i]-1]��
*/
void bucket_sort(vector<int>& nums, int n);
//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
int firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();
	bucket_sort(nums, n);
	for (int i = 0; i < n; ++i)
		if (nums[i] != i + 1)
			return i + 1;
	return n + 1;
}
void bucket_sort(vector<int>& nums, int n)
{
	for (int i = 0; i < n; ++i)
	{
		while (nums[i] != i + 1)
		{
			if (nums[i] <= 0 || nums[i]>n || nums[i] == nums[nums[i] - 1])
				break;
			swap(nums[i], nums[nums[i] - 1]);
		}
	}
}
int main(void)
{
	system("pause");
	return 0;
}