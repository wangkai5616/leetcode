#include<iostream>
#include<vector>
using namespace std;
/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��
����Լ��������в������ظ���Ԫ�ء�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
*/
/*
���ֲ��ң���Ҫ�Ǳ߽��ȷ����һ������ĳ�벿�ֻ��ǵ����ģ�
�ҵ�����Ȼ���ٽ���target���ж�
*/
int search(vector<int>& nums, int target)
{
	int first = 0;
	int last = nums.size();
	int mid = 0;
	while (first != last)
	{
		mid = (first + last) / 2;
		if (nums[mid] == target)
			return mid;
		//˵����벿���ǵ����ģ�û���ܵ���ת��Ӱ��
		if (nums[first] <= nums[mid])
		{
			if (nums[first] <= target && target < nums[mid])
				last = mid;
			else
				first = mid + 1;
		}
		//˵����벿�ֲ��ǵ������Ұ벿���ǵ���
		else
		{
			if (nums[mid] < target && target <= nums[last-1])
				first = mid + 1;
			else
				last = mid;
		}
	}
	return -1;
}
int main(void)
{
	vector<int> v = { 4,5,6,7,0,1,2 };
	int result = search(v, 3);
	cout << result << endl;
	system("pause");
	return 0;
}