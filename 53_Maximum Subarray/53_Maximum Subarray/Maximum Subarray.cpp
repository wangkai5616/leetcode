#include<iostream>
#include<vector>
using namespace std;
//����һ���������� nums ���ҵ�һ���������͵���
//�������飨���������ٰ���һ��Ԫ�أ������������͡�
int maxSubArray(vector<int>& nums)
{
	if (nums.size() < 1)
		return -1;
	int max = INT_MIN;
	int current = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (current < 0)
			current = nums[i];
		else
			current += nums[i];
		if (current > max)
			max = current;
	}
	return max;
}
int main(void)
{
	vector<int> v = { -3,4,-4,6,3,-1,8 };
	int result = maxSubArray(v);
	cout << result << endl;
	system("pause");
	return 0;
}