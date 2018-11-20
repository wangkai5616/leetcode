#include<iostream>
#include<string>
using namespace std;
/*
一条包含字母 A-Z 的消息通过以下方式进行了编码
*/
int numDecodingsCore(const string& s, int i, const int length);
int numDecodings(string s)
{
	if (s.size() < 1)
		return 0;
	int length = s.size();
	return numDecodingsCore(s, 0, length);
}
int numDecodingsCore(const string& s, int i, const int length) 
{
	if (i == length - 1)
		return 1;
	int digit1 = s[i] - '0';
	int digit2 = s[i + 1] - '0';
	int num = digit1 * 10 + digit2;
	if (num >= 10 && num <= 25)
	{
		if (i == length - 2)
			return 2;
		else
			return numDecodingsCore(s, i + 1, length) +
			numDecodingsCore(s, i + 2, length);
	}
	return numDecodingsCore(s, i + 1, length);
}
int main(void)
{
	string s = "226";
	int result = numDecodings(s);
	cout << result << endl;
	system("pause");
	return 0;
}