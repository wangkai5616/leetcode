#include<iostream>
#include<vector>
using namespace std;
/*
����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
*/
void swap(vector<int>& nums, int a, int b);
int removeElement1(vector<int>& nums, int val)
{
	if (nums.size() < 1)
		return 0;
	int index = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != val)
			nums[index++] = nums[i];
	}
	return index;
}

int removeElement2(vector<int>& nums, int val)
{
	if (nums.size() < 1)
		return 0;
	int length = nums.size();
	for (int i = 0; i < length; ++i)
	{
		if (nums[i] == val)
		{
			swap(nums,i,length-1);
			length--;
			i--;
		}
		
	}
	return length;
}
void swap(vector<int>& nums,int a, int b)
{
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

int main(void)
{
	vector<int> v = { 0,1,2,2,3,0,4,2,8,9};
	int result = removeElement1(v, 2);
	cout << result << endl;
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}

