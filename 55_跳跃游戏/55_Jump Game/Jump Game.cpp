#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
�ж����Ƿ��ܹ��������һ��λ�á�
*/
/*
˼·����0������һ��һ����������������ܲ��ܳ�����߲㣬
�ܳ�����˵�����ܵ�������ܵ��
ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
*/
bool canJump(vector<int>& nums)
{
	int length = nums.size();
	//�������������±�
	int reach = 0;
	for (int i = 0; i <= reach && reach < length; ++i)
		reach = max(reach, i + nums[i]);
	return reach >= length-1;
}
/*
˼·�����棬��״̬Ϊ f[i]����ʾ�ӵ� 0 ��������ߵ� A[i] ʱʣ
������������״̬ת�Ʒ���Ϊ��
f[i] = max(f[i ? 1], A[i ? 1])-1,i>0
ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
*/
bool canJump2(vector<int>& nums)
{
	int length = nums.size();
	//��0��������ߵ�v[i]ʱʣ����������Ҳ������໹��
	//��ǰ�߼���
	vector<int> v(length, 0);
	v[0] = 0;
	for (int i = 1; i < length; ++i)
	{
		v[i] = max(v[i - 1], nums[i - 1]) - 1;
		if (v[i] < 0)
			return false;
	}
	return true;
}
int main(void)
{
	system("pause");
	return 0;
}