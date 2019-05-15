#include<iostream>
#include<vector>
using namespace std;
/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2
*/
//没什么用，只是辅助理解grayCode函数
void print(const vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}
/*
先求只有1个bit时的情况，此时是0,1，
对于上面的0,1，当求2bit时其实就是00，01,
在这个基础上，将10和上一次的逆序结果进行或，然后加入result
然后重复上面的步骤
*/
vector<int> grayCode(int n)
{
	vector<int> result;
	result.push_back(0);//第一个元素必为0
	for (int i = 0; i < n; ++i)
	{
		const int highest_bit = 1 << i;
		for (int j = result.size() - 1; j >= 0; --j)//要反着遍历才能对称
			result.push_back(highest_bit | result[j]);
		print(result);
	}
	return result;
}

int main(void)
{
	vector<int> result = grayCode(3);
	system("pause");
	return 0;
}