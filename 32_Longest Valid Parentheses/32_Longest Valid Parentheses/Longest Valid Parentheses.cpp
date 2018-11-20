#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
/*
����һ��ֻ���� '(' �� ')' ���ַ������ҳ���İ�����Ч���ŵ��Ӵ��ĳ��ȡ�
*/
int longestValidParentheses(string s)
{
	//��¼����Ӵ�
	int maxLength = 0;
	//δƥ������һ��')'��λ��
	int last = -1;
	//��һ��'('����ջ
	stack<int> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			st.push(i);
		else
		{
			if (st.empty())
				last = i;//����δƥ������һ��')'��λ��
			else
			{
				st.pop();
				if (st.empty())
					maxLength = max(maxLength, i - last);
				else
					maxLength = max(maxLength, i - st.top());
			}
		}
	}
	return maxLength;
}

int main(void)
{
	string s = "((())()(";
	int result = longestValidParentheses(s);
	cout << result << endl;
	system("pause");
	return 0;
}