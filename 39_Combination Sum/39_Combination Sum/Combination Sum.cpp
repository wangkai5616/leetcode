#include<iostream>
#include<vector>
using namespace std;
void BackTrace(vector<vector<int>> &result, vector<int> &v, vector<int> candidates,
	 int target, int remain, int begin);
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> v;
	BackTrace(result, v, candidates, target, target, 0);
	return result;
}
/*
result存放的是最后的结果
v里面存放的是某次成立的元素
candidates是题目给定的数组
target是给定的值
remain距离给定的值还差的大小
begin从哪个坐标开始
*/
void BackTrace(vector<vector<int>> &result, vector<int> &v, vector<int> candidates,
	int target, int remain, int begin)
{
	if (remain < 0)
		return;
	else if (remain == 0)
		result.push_back(v);
	else
	{
		for (int i = begin; i < candidates.size(); ++i)
		{
			v.push_back(candidates[i]);
			BackTrace(result, v, candidates, target, remain - candidates[i], i);
			//无论结果正确与否，为了进行下一次找寻，需要移除一位
			v.pop_back();
		}
	}
}
void print(const vector<vector<int>> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<int> v = { 2,3,4 };
	vector<vector<int>> result = combinationSum(v, 8);
	print(result);
	system("pause");
	return 0;
}