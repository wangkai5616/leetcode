#include<iostream>
#include<vector>
using namespace std;
/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
*/
vector<int> plusOne(vector<int>& digits)
{
	int c = 1;//每一次的进位
	for (auto it = digits.rbegin(); it != digits.rend(); ++it)
	{
		*it += c;
		c = *it / 10;
		*it %= 10;
	}
	if (c > 0)
		digits.insert(digits.begin(), 1);
	return digits;
}
int main(void)
{
	
	vector<int> v = { 9,9,9 };
	v = plusOne(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}