#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;
string minWindow(string s, string t)
{
	if (s.size() == 0 || t.size() == 0 || s.size() < t.size())
		return "";
	//用于保存s中出现字符串t中的某个字符的数量
	int *appeared = new int[256]();
	//用于保存字符串t中出现的某个字符的数量
	int *expected = new int[256]();
	for (int i = 0; i < t.size(); ++i)
		expected[t[i]]++;
	int minWidth = INT_MAX;
	int minStart = 0;
	int num = 0;
	int winStrat = 0;
	for (int winEnd = 0; winEnd < s.size(); ++winEnd)
	{
		if (expected[s[winEnd]]>0)
		{
			appeared[s[winEnd]]++;
			if (appeared[s[winEnd]] <= expected[s[winEnd]])
				++num;
		}
		if (num == t.size())
		{
			while (appeared[s[winStrat]]>expected[s[winStrat]])
			{
				appeared[s[winStrat]--];
				++winStrat;
			}
		}
	}
}
int main(void)
{
	
	system("pause");
	return 0;
}




