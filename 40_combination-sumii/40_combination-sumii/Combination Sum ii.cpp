#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。
*/
//思路：对照39
void BackTrace(vector<vector<int>> &result, vector<int> &v, vector<int> candidates,
	int target, int remain, int begin);
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	vector<int> v;
	sort(candidates.begin(), candidates.end());
	BackTrace(result, v, candidates, target, target, 0);
	
	return result;
}
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
			if (i > begin && candidates[i] == candidates[i - 1])
				continue;
			v.push_back(candidates[i]);
			//通过i+1防止对同一元素重复提取，对candidates排序然后判断当前元素和上一元素防止重复计算。
			BackTrace(result, v, candidates, target, remain - candidates[i], i + 1);
			v.pop_back();
		}
	}
}
/*
sort(result.begin(), result.end());
result.erase(unique(result.begin(), result.end()), result.end());
return result;
*/
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
	vector<int> v = { 1,1,1,1 };
	vector<vector<int>> result = combinationSum2(v, 3);
	print(result);
	system("pause");
	return 0;
}