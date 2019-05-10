#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
*/
int longestValidParentheses(string s)
{
	//记录最长的子串
	int maxLength = 0;
	//未匹配的最后一个')'的位置
	int last = -1;
	//来一个'('就入栈
	stack<int> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			st.push(i);
		else
		{
			if (st.empty())
				last = i;//更新未匹配的最后一个')'的位置
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