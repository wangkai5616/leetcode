#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����
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