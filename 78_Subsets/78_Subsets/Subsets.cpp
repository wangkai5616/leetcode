#include<iostream>
#include<vector>
using namespace std;
/*
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
˵�����⼯���ܰ����ظ����Ӽ���

˼·���������취������ÿ��Ԫ�أ���������ѡ��ѡ���߲�ѡ
*/
void subsetsCore(vector<vector<int>> &result, vector<int> &v, vector<int>& nums, int i);
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.size() < 1)
		return result;
	vector<int> v;
	int i = 0;
	subsetsCore(result, v, nums, i);
	return result;
}
void subsetsCore(vector<vector<int>> &result,vector<int> &v, vector<int>& nums,int i)
{
	if (i == nums.size())
	{
		result.push_back(v);
		return;
	}
	subsetsCore(result, v, nums, i + 1);
	v.push_back(nums[i]);
	subsetsCore(result, v, nums, i + 1);
	v.pop_back();
}
void print(vector<vector<int>> &result)
{
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> result = subsets(nums);
	print(result);
	system("pause");
	return 0;
}