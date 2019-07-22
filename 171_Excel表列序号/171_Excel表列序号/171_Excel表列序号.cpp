#include<iostream>
#include<string>
using namespace std;
int titleToNumber(string s)
{
	int n = s.size();
	long num = 0;
	long tmp = 1;
	for (int i = n-1; i >= 0; --i)
	{
		num += (s[i] - 'A' + 1)*tmp;
		if (num >= INT_MAX)
			return INT_MAX;
		tmp *= 26;
	}
	return num;
}
int main(void)
{
	cout << titleToNumber("ABCD") << endl;
	system("pause");
	return 0;
}