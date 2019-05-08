#include<iostream>
#include<string>
using namespace std;
/*
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
string intToRoman(int num)
{
	string result = "";
	const int value[] = { 1000, 900, 500, 400, 100, 90,
		50, 40, 10, 9, 5, 4, 1 };
	const string str[]= { "M", "CM", "D", "CD", "C", "XC",
		"L", "XL", "X", "IX", "V", "IV", "I" };

	for (int i = 0; num > 0; ++i)
	{
		int count = num / value[i];
		num %= value[i];
		for (; count > 0; --count)
			result += str[i];
	}
	return result;
}
int main(void)
{
	int num = 12345;
	cout << intToRoman(num) << endl;
	system("pause");
	return 0;
}