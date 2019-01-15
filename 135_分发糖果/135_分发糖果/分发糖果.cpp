#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
*/
// 时间复杂度 O(n)空间复杂度 O(n)
int candy(vector<int>& ratings)
{
	int n = ratings.size();
	vector<int> v(n);
	//从左向右扫描，如果后一个大于前一个，后一个比前一个大1
	for (int i = 1, increnmt = 1; i < n; ++i)
	{
		if (ratings[i] > ratings[i - 1])
			v[i] = max(increnmt++, v[i]);
		else
			increnmt = 1;
	}
	//从右向左扫描，如果前一个大于后一个，前一个比后一个大1，如果之前的v[i]较大
	//那就选择较大的，因为从前往后和从后往前都要满足
	for (int i = n - 2, increnmt = 1; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			v[i] = max(increnmt++, v[i]);
		else
			increnmt = 1;
	}
	//初始值为n,因为每个小朋友至少一颗糖
	int result = n;
	for (int i = 0; i < n; ++i)
		result += v[i];
	return result;
}
int main(void)
{
	vector<int> v = { 1,0,2 };
	int result = candy(v);
	cout << result << endl;
	system("pause");
	return 0;
}