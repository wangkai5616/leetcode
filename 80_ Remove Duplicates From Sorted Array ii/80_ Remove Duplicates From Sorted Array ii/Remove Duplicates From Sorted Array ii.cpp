#include<iostream>
#include<vector>
using namespace std;
/*
����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
*/
int removeDuplicates1(vector<int>& nums)
{
	if (nums.size() < 3)
		return nums.size();
	//����������Ѿ���������ͬ����Ԫ�أ���ôhelp=1
	int help = 0;
	for (auto iter = nums.begin() + 1; iter != nums.end();)
	{
		if (*iter == *(iter - 1) && help == 1)
			//��ʱ������������ȱ�㣬ɾ��Ԫ����Ҫ�ƶ���Ԫ�ؽ϶࣬����ʱ�临�Ӷȸ�
			iter = nums.erase(iter);
		else if (*iter == *(iter - 1) && help == 0)
		{
			++iter;
			help = 1;
		}
		else
		{
			++iter;
			help = 0;
		}
	}
	return nums.size();
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