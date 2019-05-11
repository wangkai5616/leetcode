#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int lengthOfLastWord(string s)
{
	int length = 0;
	auto iter = s.begin();
	while (iter != s.end())
	{
		if (*iter != ' ')
			++length;
		else if (*iter == ' ' && (++iter != s.end()))
		{
			length = 0;
			--iter;
		}
		++iter;
	}
	return length;
}
int main(void)
{
	string s = "h w";
	cout << lengthOfLastWord(s) << endl;
	system("pause");
	return 0;
}

