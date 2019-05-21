#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
/*
�����沨����ʾ��������ʽ��ֵ��
��Ч����������� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��
˵����
��������ֻ�����������֡�
�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
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
			else x /= y;//���µĳ��������
			s.push(x);
		}
		else
		{
			s.push(stoi(tokens[i]));
		}
	}
	return s.top();
}

//�ж��Ƿ��ǲ�����
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