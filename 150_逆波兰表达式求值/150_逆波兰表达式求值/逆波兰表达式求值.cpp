#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
/*
根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
*/
int evalRPN(vector<string>& tokens)
{
	stack<int> s;
	for (int i = 0; i < tokens.size(); ++i)
	{
		if(isOperator(tokens[i]))
		{
			int y = s.top(); s.pop();
			int x = s.top(); s.pop();
			if (tokens[i] == "+")  x += y;
			else if (tokens[i] == "-") x -= y;
			else if (tokens[i] == "*") x *= y;
			else x /= y;//底下的除以上面的
			s.push(x);
		}
		else
		{
			s.push(stoi(tokens[i]));
		}
	}
	return s.top();
}

//判断是否是操作数
bool isOperator(string s)
{
	if (s == "+" || s == "-" || s == "*" || s == "/")
		return true;
	else
		return false;
}
int main(void)
{
	system("pause");
	return 0;
}