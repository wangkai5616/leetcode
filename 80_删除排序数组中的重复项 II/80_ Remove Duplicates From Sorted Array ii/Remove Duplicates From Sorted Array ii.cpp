#include<iostream>
#include<vector>
using namespace std;
/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
*/
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int index = -1;
	int length = 0;
	int times = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i == 0 || nums[i] != nums[i - 1])
		{
			times = 1;
			nums[++index] = nums[i];
			++length;

		}
		else if (nums[i] == nums[i - 1])
		{
			if (times == 1)
			{
				++times;
				nums[++index] = nums[i];
				++length;
			}
		}
	}
	return length;
}

//ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)�ķ���
int removeDuplicates2(vector<int>& nums)
{
	if (nums.size() < 3)
		return nums.size();
	int index = 2;
	for (int i = 2; i < nums.size(); ++i)
	{
		if (nums[i] != nums[index - 2])
			nums[index++] = nums[i];
	}
	return index;
}
int main(void)
{
	vector<int> nums = { 1,1,1,2,2,2,3 };
	int result = removeDuplicates2(nums);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
	cout << result << endl;
	system("pause");
	return 0;
}