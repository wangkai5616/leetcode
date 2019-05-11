#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�
*/
/*
��������⣬��Ϊ�漰��ǰ��󣬻�Ҫ�Ӻ���ǰ�����Բ��ܸ����±�
�Ƿ񵽴�num.size()���ж�
*/
vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.empty())
		return result;
	sort(nums.begin(), nums.end());
	vector<int> v;
	dfs(nums,v,result);
	return result;
}
void dfs(const vector<int>& nums, vector<int> &v, vector<vector<int>> &result)
{
	//��������
	if (v.size() == nums.size())
	{
		result.push_back(v);
		return;
	}
	for (auto i : nums)
	{
		//����i�Ƿ���v�г��ֹ�
		auto pos = find(v.begin(), v.end(), i);
		if (pos == v.end())
		{
			v.push_back(i);
			dfs(nums, v, result);
			v.pop_back();
		}
	}
}
int main(void)
{
	system("pause");
	return 0;
}