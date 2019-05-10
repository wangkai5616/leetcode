#include<iostream>
#include<vector>
using namespace std;
/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
*/
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() < 1)
		return 0;
	int index = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != nums[index])
			nums[++index] = nums[i];
	}
	return index + 1;
}
int main(void)
{
	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
	int result = removeDuplicates(v);
	cout << result << endl;
	for (int i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}