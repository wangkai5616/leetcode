#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�
ʾ��:
����: [1,1,2]
���:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*/
//˼·������
void permuteUnique(vector<vector<int>> &result,
	vector<int> nums, int i);
vector<vector<int>> permuteUnique(vector<int> nums)
{
	vector<vector<int>> result;
	permuteUnique(result, nums, 0);
	return result;
}
void permuteUnique(vector<vector<int>> &result, 
	vector<int> nums, int i)
{
	vector<int> v;//ͳ�Ƴ��ֵ�Ԫ�ص�ֵ
	if (i == nums.size() - 1)
	{
		result.push_back(nums);
		return;
	}
	for (int j = i; j < nums.size(); ++j)
	{
		//�ж�֮ǰ�Ƿ���ֹ���ֵ
		if (j != i && find(v.begin(),v.end(),nums[j])!=v.end())
			continue;
		else
		{
			v.push_back(nums[j]);
			swap(nums[i], nums[j]);
			permuteUnique(result, nums, i + 1);
		}
	}
}
void print(const vector<vector<int>> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<int> v{ 3,3,0,3 };
	vector<vector<int>> result;
	result = permuteUnique(v);
	print(result);
	system("pause");
	return 0;
}