#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int longestValidParentheses(string s)
{
	int curLength = 0;
	int maxLength = 0;
	stack<int> si;
	int last = -1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			si.push(i);
		else
		{
			if (si.empty())
				last = i;
			else
			{
				si.pop();
				if(si.empty())
					maxLength=
			}
		}
	}
}
int main(void)
{

	system("pause");
	return 0;
}

