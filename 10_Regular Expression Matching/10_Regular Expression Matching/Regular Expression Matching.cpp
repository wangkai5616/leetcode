#include<iostream>
using namespace std;
/*
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
*/
bool matchCore(char *str, char *pattern);
bool match(char *string, char *pattern)
{
	if (string == nullptr || pattern == nullptr)
		return false;
	return matchCore(string, pattern);
}
bool matchCore(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		{
			return matchCore(str + 1, pattern + 2)//对应情况是*前面的字符只出现了一次
				|| matchCore(str + 1, pattern)//对应情况是*前面的字符出现了多次或者 *前面出现了.
											  /*
											  这种情况也会在if中发生
											  char str1[] = "abc";
											  char str2[] = "a*abc";
											  */
				|| matchCore(str, pattern + 2);
		}
		else
		{
			return matchCore(str, pattern + 2);
		}
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);
	return false;
}
int main(void)
{
	char str1[] = "abc";
	char str2[] = "a*abc";
	bool result = match(str1, str2);
	if (result)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	system("pause");
	return 0;
}
