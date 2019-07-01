#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��̬�滮
/*
�������ֱ�ӵķ���������DP����������Ҫ������dp���飬����v1[i]
��ʾ������[0, i]��Χ�ڲ���һ������nums[i]���ֵ����������˻���
v2[i]��ʾ������[0, i]��Χ�ڲ���һ������nums[i]���ֵ���С������
�˻�����ʼ��ʱv1[0]��v2[0]����ʼ��Ϊnums[0]�����඼��ʼ��Ϊ0��
��ô������ĵڶ������ֿ�ʼ��������ô��ʱ�����ֵ����Сֵֻ����
����������֮���������v1[i-1]*nums[i]��v2[i-1]*nums[i]����nums[i]��
���������������е����ֵ������v1[i]������Сֵ������v2[i]��Ȼ����
v1[i]�����½��res���ɡ�
*/
int maxProduct(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int result = nums[0];
	int n = nums.size();
	vector<int> v1(n, 0);
	vector<int> v2(n, 0);
	v1[0] = nums[0];
	v2[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		v1[i] = max(max(v1[i - 1] * nums[i], v2[i - 1] * nums[i]), nums[i]);
		v2[i] = min(min(v1[i - 1] * nums[i], v2[i - 1] * nums[i]), nums[i]);
		result = max(result, v1[i]);
	}
	return result;
}