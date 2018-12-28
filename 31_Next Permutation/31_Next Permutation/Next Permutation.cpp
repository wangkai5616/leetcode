#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums)
{
	int k = -1;
	for (int i = nums.size() - 2; i >= 0; --i)
	{
		//�ҵ������±�k��ʹ��nums[k]<nums[k+1]
		if (nums[i] < nums[i + 1])
		{
			k = i;
			break;
		}
	}
	//�������˵��vector�е�����ȫ����
	if (k == -1)
	{
		reverse(nums.begin(), nums.end());
		return;
	}
	int l = -1;
	//�Ӻ���ǰ�ң��ҵ�k֮������nums[k] < nums[l]�������±�i
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (nums[i] > nums[k])
		{
			l = i;
			break;
		}
	}
	swap(nums[k], nums[l]);
	/*
	�����ҵ���k��˵������,��k�����Ԫ���ǴӴ�С���У�����
	swap֮����Ȼ�ǴӴ�С������Ӧ��Ū�ɴ�С������Ϊ���ҵ�һ��
	���д��������������
	*/
	reverse(nums.begin() + k + 1, nums.end());
}
int main(void)
{
	vector<int> v = { 1,2,3 };
	nextPermutation(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}