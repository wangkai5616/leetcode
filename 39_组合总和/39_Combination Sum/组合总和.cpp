#include<iostream>
#include<vector>
using namespace std;
/*
����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ��
�ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
candidates �е����ֿ����������ظ���ѡȡ��
˵����
�������֣����� target��������������
�⼯���ܰ����ظ�����ϡ�
ʾ�� 1:
����: candidates = [2,3,6,7], target = 7,
����⼯Ϊ:
[[7],[2,2,3]]
*/
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
result��ŵ������Ľ��
v�����ŵ���ĳ�γ�����Ԫ��
candidates����Ŀ����������
target�Ǹ�����ֵ
remain���������ֵ����Ĵ�С
begin���ĸ����꿪ʼ
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
			//���۽����ȷ���Ϊ�˽�����һ����Ѱ����Ҫ�Ƴ�һλ
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