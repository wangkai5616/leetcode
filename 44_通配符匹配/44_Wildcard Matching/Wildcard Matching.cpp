#include<iostream>
#include<string>
using namespace std;
/*
递归方法会超时
*/
bool isMatchCore(string s, int i, string p, int j);
bool isMatch2(string s, string p)
{
	int i = 0, j = 0;
	return isMatchCore(s, i, p, j);
}
bool isMatchCore(string s, int i, string p, int j)
{
	if (i == s.size() && j == p.size())
		return true;
	if (i < s.size() && j == p.size())
		return false;
	if (p[j] == '*' && i<=s.size())
		return isMatchCore(s, i + 1, p, j) || //*匹配多个字符
		isMatchCore(s, i, p, j + 1) || //对应情况是*匹配空
		isMatchCore(s, i + 1, p, j + 1); //*匹配一个字符
	if (i<s.size() &&(s[i] == p[j] || (p[j] == '?')))
		return isMatchCore(s, i + 1, p, j + 1);
	return false;
}


bool isMatch(string s, string p) {
	if (s == p)
		return true;
	//jstar用来记p中'*'的位置, istar记录s中'*'所能匹配的字符的最终位置
	int i = 0, j = 0, iStar = -1, jStar = -1;
	while (i < s.size())
	{
		if (s[i] == p[j] || p[j] == '?')
		{//达到了消除一个字符的条件
			++i; ++j;
		}
		else if (p[j] == '*')
		{//当前字符串为'*'，记录下来当前位置
			iStar = i;
			jStar = j++;
		}
		else if (jStar >= 0)
		{//当两个字符无法匹配时，如果出现了'*'，那么用'*'号抵消，并且p中'*'位置不变
			i = ++iStar;
			j = jStar + 1;
		}
		//不满足匹配条件，并且没有出现'*'
		else
			return false;
	}
	//查找完字符串中所有的'*'
	while (j < p.size() && p[j] == '*')
		++j;
	//所有的字符都得到了匹配
	return j == p.size();
}

int main(void)
{
	string s = "adceb";
	string p = "*a*b";
	bool b = isMatch2(s, p);
	if (b)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	system("pause");
	return 0;
}