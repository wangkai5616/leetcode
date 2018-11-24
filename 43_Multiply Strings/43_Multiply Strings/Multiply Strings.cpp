#include<iostream>
#include<vector>
#include<string>
#include<iterator>//包含了back_inserter的定义
#include<algorithm>
/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
它们的乘积也表示为字符串形式。

说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
using namespace std;
vector<int> make_bigint(const string & str);
string to_string(const vector<int> &v);
vector<int> chen(vector<int> v1, vector<int> v2);
string multiply(string num1, string num2)
{
	return to_string(chen(make_bigint(num1),make_bigint(num2)));
}
vector<int> make_bigint(const string & str)
{
	vector<int> v;
	/*
	transform()的第一个版本是以仿函数op作用域[first,last)中的每一个元素身上，并以其
	结果产生出一个新的序列
	*/
	transform(str.rbegin(), str.rend(), back_inserter(v),
		[](char c) {return c - '0'; });
	return v;
}
string to_string(const vector<int> &v)
{
	string str;
	//prev是指迭代器的前一个指向位置
	transform(find_if(v.rbegin(), prev(v.rend()), [](int c) {return c > 0; }),v.rend(),
		back_inserter(str), [](int c) {return c + '0'; });
	return str;
}
vector<int> chen(vector<int> v1, vector<int> v2)
{
	vector<int> v(v1.size() + v2.size());
	for (int i = 0; i < v1.size(); ++i)
		for (int j = 0; j < v2.size(); ++j)
		{
			v[i + j] += v1[i] * v2[j];
			v[i + j + 1] += v[i + j] / 10;
			v[i + j] %= 10;
		}
	return v;
}
int main()
{
	string s1 = "10";
	string s2 = "10";
	string result = multiply(s1, s2);
	cout << result << endl;
	system("pause");
	return 0;
}