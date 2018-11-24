#include<iostream>
#include<string>
#include<iterator>
using namespace std;
/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
*/
int lengthOfLastWord(string s)
{
	if (s.empty())
		return 0;
	int length = 0;
	auto iter = s.rbegin();
	while (*iter == ' ')
		iter++;
	for (; iter != s.rend(); ++iter)
	{
		if (*iter == ' ')
			return length;
		else
			length++;
	}
	return length;
}
//方法二,不使用容器
int lengthOfLastWord2(const char *s)
{
	int length = 0;
	while (*s)
	{
		if (*s++ != ' ')
			++length;
		else if (*s && *s != ' ')
			length = 0;
	}
	return length;
}
int main(void)
{
	string s = "hello world dsa ";
	int length = lengthOfLastWord(s);
	cout << length << endl;
	system("pause");
	return 0;
}