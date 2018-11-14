#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ������ candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�
˵����
�������֣�����Ŀ������������������
�⼯���ܰ����ظ�����ϡ�
*/
//˼·������39
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
			//ͨ��i+1��ֹ��ͬһԪ���ظ���ȡ����candidates����Ȼ���жϵ�ǰԪ�غ���һԪ�ط�ֹ�ظ����㡣
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