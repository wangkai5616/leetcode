#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/
string longestCommonPrefix(vector<string>& strs)
{
	string result = "";
	if (strs.empty())
		return result;
	string s1 = strs[0];
	for (int i = 0; i < s1.size();++i)
	{
		for (int j = 1; j < strs.size(); ++j)
		{
			if (s1[i] != strs[j][i])
				return result;			
		}
		result += s1[i];
	}
	return result;
}
int main(void)
{
	string s1 = "abcdd";
	string s2 = "ab";
	string s3 = "abbn";
	vector<string> v = { s1,s2,s3 };
	string s = longestCommonPrefix(v);
	cout << s << endl;

	//编译器做了处理，在最后加上了'0\'
	string test = "abc";
	if (test[3] == '\0')
		cout << "以空结尾" << endl;
	system("pause");
	return 0;
}