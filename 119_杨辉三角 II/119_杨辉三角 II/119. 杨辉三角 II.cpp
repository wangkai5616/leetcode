#include<iostream>
#include<vector>
using namespace std;
/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
输入: 3
输出: [1,3,3,1]
*/
vector<int> getRow(int rowIndex)
{
	vector<int> result;
	for (int i = 0; i <= rowIndex; ++i)
	{
		//result存放的是当前行的元素，计算下一行的时候可以进行利用
		for (int j = i - 1; j > 0; --j)//从后往前计算，数据不会被扰乱
			result[j] = result[j - 1] + result[j];
		result.push_back(1);//每次总要在末尾添加1
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}