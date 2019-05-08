#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/
bool isValid(string s)
{
	stack<char> sch;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			sch.push(s[i]);
		else if (s[i] == ')')
		{
			if (sch.empty() || sch.top() != '(')
				return false;
			else
				sch.pop();
		}
		else if (s[i] == ']')
		{
			if (sch.empty() || sch.top() != '[')
				return false;
			else
				sch.pop();
		}
		else if (s[i] == '}')
		{
			if (sch.empty() || sch.top() != '{')
				return false;
			else
				sch.pop();
		}
		else
			return false;
	}
	if (sch.empty())
		return true;
	else
		return false;
}
int main(void)
{
	string s = "()";
	bool b = isValid(s);
	system("pause");
	return 0;
}