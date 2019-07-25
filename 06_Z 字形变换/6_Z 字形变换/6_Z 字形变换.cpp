#include<iostream>
#include<string>
using namespace std;
string convert(string s, int numRows) {
	if (numRows == 1) return s;
	string str;
	int n = s.length();
	int step = 2 * numRows - 2;

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j + i < n; j += step)
		{
			str += s[j + i];
			if (i != 0 && i != numRows - 1 && j + step - i < n)
				str += s[j + step - i];
		}
	}
	return str;
}
int main(void)
{
	string s = "LEETCODEISHIRING";
	int numRows = 3;
	system("pause");
	return 0;
}