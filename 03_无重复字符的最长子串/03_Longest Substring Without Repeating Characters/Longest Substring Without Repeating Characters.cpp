#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
字符不只包括a、b...，还有#$%^各种各样的
*/
int lengthOfLongestSubstring(string s)
{
	int curLength = 0;
	int maxLength = 0;
	map<char, int> m;//字符及其对应的下标构成map
	for (int i = 0; i < s.length(); ++i)
	{
		/*
		先前没有出现过字符s[i]或者先前已经出现过的那个字符
		不在当前的curLength范围中，那么CurLength继续++
		*/
		if (m.find(s[i]) == m.end() || i-m.find(s[i])->second>curLength)
		{
			++curLength;
		}
		else
		{
			if (curLength > maxLength)
				maxLength = curLength;
			//更新curLength
			curLength = i - m.find(s[i])->second;
		}
		//在map中进行记录
		m[s[i]] = i;
	}
	if (curLength > maxLength)
		maxLength = curLength;
	return maxLength;
}
int main(void)
{
	string s = "abc&*abrh";
	int result = lengthOfLongestSubstring(s);
	cout << result << endl;
	system("pause");
	return 0;
}