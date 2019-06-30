#include<iostream>
#include<string>
using namespace std;
string decode(string s, int& i);
string decodeString(string s) {
	int i = 0;
	return decode(s, i);
}
string decode(string s, int& i) 
{
	string res = "";
	int n = s.size();
	while (i < n && s[i] != ']') 
	{
		if (s[i] < '0' || s[i] > '9') 
		{
			res += s[i++];
		}
		else 
		{
			int cnt = 0;
			while (s[i] >= '0' && s[i] <= '9') {
				cnt = cnt * 10 + s[i++] - '0';
			}
			++i;//跳过左侧的[
			string t = decode(s, i);//递归计算[]之间的string
			++i;//跳过右侧的]
			while (cnt-- > 0) {
				res += t;
			}
		}
	}
	return res;
}
int main(void)
{
	string s = "3[a2[c]]";
	string result = decodeString(s);
	cout << result << endl;
	system("pause");
	return 0;
}