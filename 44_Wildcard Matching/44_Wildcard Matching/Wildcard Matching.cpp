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