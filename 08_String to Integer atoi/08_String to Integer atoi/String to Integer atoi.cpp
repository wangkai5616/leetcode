#include<iostream>
#include<string>
using namespace std;
/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。
*/
int myAtoi(string str)
{
	int num = 0;
	int sign = 1;
	int length = str.size();
	int i = 0;
	for (; i < length; ++i)
		if (str[i] != ' ')
			break;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	for (; i < length; ++i)
	{
		if (str[i]<'0' || str[i]>'9')
			return num*sign;
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0')>INT_MAX % 10))
			return sign == -1 ? INT_MIN : INT_MAX;
		num = num * 10 + str[i] - '0';
	}
	return sign == -1 ? -num : num;
}
int main(void)
{
	string s = " -23456";
	int result = myAtoi(s);
	cout << result << endl;
	system("pause");
	return 0;
}