#include<iostream>
#include<string>
using namespace std;
void reverseString(string &s, int left, int right) {
	while (left < right) {
		swap(s[left++], s[right--]);
	}
	return;
}
string reverseWords(string s)
{
	int len = s.size();
	if (len < 2)
		return s;
	int start = 0;
	int end = 0;
	while (start < len)
	{
		if (s[start] == ' ')
			++start;
		end = start;
		while (end < len && s[end] != ' ')
			++end;
		reverseString(s, start, --end);
		start = ++end;
	}
	return s;
}