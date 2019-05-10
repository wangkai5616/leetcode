#include<iostream>
#include<vector>
using namespace std;
/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,0,1,2,2,5,6] ���ܱ�Ϊ [2,5,6,0,0,1,2] )��
��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ��� true�����򷵻� false��

���� ������ת�������� ��������Ŀ�������е� nums  ���ܰ����ظ�Ԫ�ء�
*/
/*
�����������ظ�Ԫ�أ�����һ������� A[m]>=A[l], ��ô [l,m] Ϊ�������еļ���Ͳ��ܳ����ˣ���
�� [1,3,1,1,1]��
��� A[m]>=A[l] ����ȷ���������ǾͰ�����ֳ�����������
1.�� A[m]>A[l]�������� [l,m] һ������
2.�� A[m]==A[l] ȷ�����ˣ��Ǿ� l++�����¿�һ������
*/
//ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)
bool search(vector<int>& nums, int target)
{
	int first = 0;
	int last = nums.size();
	int mid = 0;
	while (first != last)
	{
		mid = (first + last) / 2;
		if (nums[mid] == target)
			return true;
		//˵����벿���ǵ����ģ�û���ܵ���ת��Ӱ��
		if (nums[first] < nums[mid])
		{
			if (nums[first] <= target && target < nums[mid])
				last = mid;
			else
				first = mid + 1;
		}
		//˵����벿�ֲ��ǵ������Ұ벿���ǵ���
		else if (nums[first] > nums[mid])
		{
			if (nums[mid] < target && target <= nums[last - 1])
				first = mid + 1;
			else
				last = mid;
		}
		else
			first++;
	}
	return false;
}
int main(void)
{
	vector<int> v = { 1,3,1,1 };
	bool b = search(v, 3);
	if (b)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}