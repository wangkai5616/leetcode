#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ��������ɫ����ɫ����ɫ��һ�� n ��Ԫ�ص����飬ԭ�ض����ǽ�������
ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�

�����У�����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
*/
//ʱ�临�Ӷ�Ϊ0(n)
void sortColors(vector<int>& nums)
{
	if (nums.size() < 1)
		return;
	int i = 0;
	//С��1�����һ��Ԫ�ص��±�
	int left = -1;
	//����1�ĵ�һ��Ԫ�ص��±�
	int right = nums.size();
	while (i<right)
	{
		if (nums[i] < 1)
			swap(nums[++left], nums[i++]);
		else if (nums[i] > 1)
			swap(nums[--right], nums[i]);
		else
			i++;
	}
}
int main(void)
{
	vector<int> v = { 2,0,2,1,1,0 };
	sortColors(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}