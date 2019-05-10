#include<iostream>
#include<vector>
using namespace std;
/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�
ʾ��:

����: [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
˵��:
���������ǿ��Ե�����������һ��λ�á�
*/
//ʱ�临�Ӷ�(n),�ռ临�Ӷ�O(1)
int jump(vector<int>& nums)
{
	const int length = nums.size();
	if (length == 1)
		return 0;
	int step = 0;//��С����
	//[left,right]�ǵ�ǰ�ܸ��ǵ�����
	int left = 0;
	int right = 0;
	while (left <= right)
	{
		++step;
		int oldRigth = right;
		for (int i = left; i <= oldRigth; ++i)
		{
			int newRight = i + nums[i];
			if (newRight >= length - 1)
				return step;
			if (newRight > right)
				right = newRight;
		}
		left = oldRigth + 1;
	}
	return 0;
}
int main(void)
{
	vector<int> nums = { 2,3,1,1,2,3,1,1,2 };
	int result = jump(nums);
	system("pause");
	return 0;
}