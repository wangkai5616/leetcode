#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
一条包含字母 A-Z 的消息通过以下方式进行了编码   
*/
/*
思路：本题假设给定的字符串为"s[1]s[2]……s[len]"，若我们用a[i-1]
表示前i-1个字符的解码方法数，那么求解a[i]分为两步。第一，若第i个
字符s[i]!='0'，那么第i个字符可以单独划分为一个字母，前i-1个字母的
划分对其没有影响，即a[i] = a[i-1]；第二，若第i-1个字符和第i个字符
可以组合成大于等于“10”，并且小于等于“26”的双字符，那么后两个字
母组合一下，方法数为前i-2个字符的方法数，即a[i] = a[i] + a[i-2]。
*/
int numDecodings(string s)
{
	int length = s.length();
	if (length == 0 || s[0] == '0')
		return 0;
	vector<int> v(length + 1, 0);
	v[0] = 1;
	for (int i = 1; i < length; ++i)
	{
		if (s[i] != '0')
			v[i] = v[i - 1];
		if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')
		{
			if (i == 1)
				v[i] += 1;
			else
				v[i] += v[i - 2];
		}
	}
	return v[length - 1];
}
int main(void)
{
	string s = "226";
	int result = numDecodings(s);
	cout << result << endl;
	system("pause");
	return 0;
}