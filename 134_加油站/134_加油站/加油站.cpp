#include<iostream>
#include<vector>
using namespace std;
/*
在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 
cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
说明:
如果题目有解，该答案即为唯一答案。
输入数组均为非空数组，且长度相同。
输入数组中的元素均为非负数。
*/
/*
设置两个变量，sum 判断当前的指针的有效性；total 则判断整个数组是否有
解，有就返回通过 sum 得到的下标，没有则返回 -1。
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int total = 0;
	int j = -1;
	for (int i = 0, sum = 0; i < gas.size(); ++i)
	{
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (sum < 0)
		{
			j = i;
			sum = 0;
		}
	}
	return total >= 0 ? j + 1 : -1;
}
int main(void)
{
	vector<int> gas = { 2,3,4 };
	vector<int> cost = { 3,4,3 };
	int result = canCompleteCircuit(gas, cost);
	cout << result << endl;
	system("pause");
	return 0;
}