#include<iostream>
#include<string>
using namespace std;
int strStr(string haystack, string needle)
{
	if (needle.empty())
		return 0;
	if (haystack.empty())
		return -1;
	for (auto p1 = haystack.begin(); p1 != haystack.end(); ++p1)
	{
		auto p1_copy = p1;
		auto p2 = needle.begin();
		while (p1_copy != haystack.end() && p2 != needle.end() && *p1_copy == *p2)
		{
			p1_copy++;
			p2++;
		}
		if (p2 == needle.end())
			return p1 - haystack.begin();
	}
	return -1;
}

int main(void)
{
	string s1 = "hello";
	string s2 = "ll";
	int result = strStr(s1, s2);
	cout << result << endl;
	system("pause");
	return 0;
}