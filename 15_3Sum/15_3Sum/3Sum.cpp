#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(const vector<vector<int>> &v);
/*
���ź��򣬴�ͷ��β���ȹ̶�һ��Ԫ�أ�Ȼ�����ʣ�µ�����
Ԫ����ͨ�����ҼӱƵõ��ģ����Ӷ�ΪO(n^2)
*/
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.size() < 3)
		return result;
	int target = 0;
	sort(nums.begin(), nums.end());
	vector<int>::iterator begin = nums.begin();
	vector<int>::iterator end = nums.end() - 2;
	for (; begin < end; ++begin)
	{
		int need = target - *begin;
		vector<int>::iterator start = begin + 1;
		vector<int>::iterator over = nums.end() - 1;
		while (start < over)
		{
			if (*start + *over < need)
				++start;
			else if (*start + *over > need)
				--over;
			else
			{
				result.push_back({ *begin,*start,*over });
				++start;
				--over;
			}
		}
	}
	sort(result.begin(), result.end());
	/*
	unique������ı�[first,last)��Ԫ�ظ�������һЩ�������ݻ���������������
	erase����ȥ����
	unique�᷵��һ��������ָ���������β�ˣ�������֮�ڲ������ڵ��ظ�Ԫ��
	*/
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}
void print(const vector<vector<int>> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (auto j : v[i])
			cout << j << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> result=threeSum(nums);
	print(result);
	system("pause");
	return 0;
}