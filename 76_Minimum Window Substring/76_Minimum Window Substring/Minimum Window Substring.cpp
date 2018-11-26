#include<iostream>
#include<string>
using namespace std;
//时间复杂度为O(n),空间复杂度为O(1)
string minWindow(string s, string t)
{
	if (s.empty() || t.empty() || s.size() < t.size())
		return "";
	//用于保存s中出现字符串t中的某个字符的数量
	int *appeared = new int[256]();
	//用于保存字符串t中出现的某个字符的数量
	int *expected = new int[256]();
	//对子串进行统计
	for (size_t i = 0; i < t.size(); ++i)
		expected[t[i]]++;
	int minWidth = INT_MAX;//保存窗口大小
	int minStart = 0;//窗口的起点位置
	int num = 0;//记录字符串s中出现字符串t中的字符的数量
	int winStart = 0;//头指针
	//尾指针不断往后扫
	for (size_t winEnd = 0; winEnd < s.size(); ++winEnd)
	{
		//子串t中有当前的这个字符
		if (expected[s[winEnd]]>0)
		{
			appeared[s[winEnd]]++;
			if (appeared[s[winEnd]] <= expected[s[winEnd]])
				num++;
		}
		//说明包含一个完整的子串t了
		if (num == t.size())
		{
			//收缩头指针
			while (appeared[s[winStart]]>expected[s[winStart]]
				|| expected[s[winStart]] == 0)
			{
				appeared[s[winStart]]--;
				winStart++;
			}
			if (minWidth > (winEnd - winStart + 1))
			{
				minWidth = winEnd - winStart + 1;
				minStart = winStart;
			}
		}
	}
	if (minWidth == INT_MAX)
		return "";
	else
		return s.substr(minStart, minWidth);
}
int main(void)
{
	string S = "ABC";
	string T = "ABC";
	string result = minWindow(S, T);
	cout << result << endl;
	system("pause");
	return 0;
}