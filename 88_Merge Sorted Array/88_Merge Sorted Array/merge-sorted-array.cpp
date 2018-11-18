#include<iostream>
#include<vector>
using namespace std;
/*
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:
��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:
*/
/*
˼·���ⲻ���������������룬���Բ��ôӺ���ǰ�����ⲻ��ʡȥ���ƶ�����
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	if (n < 1)
		return;
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
		nums1[k--] = nums1[i]>nums2[j] ? nums1[i--] : nums2[j--];
	while (j >= 0)
		nums1[k--] = nums2[j--];
}
int main(void)
{
	system("pause");
	return 0;
}