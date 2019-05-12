#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
using namespace std;
string addBinary(string a, string b)
{
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;
	string result;
	auto iter1 = a.rbegin();
	auto iter2 = b.rbegin();
	int value = 0;
	int jin = 0;
	int m = 0, n = 0;
	while (iter1 != a.rend() || iter2 != b.rend())
	{
		m = (iter1 != a.rend()) ? (*iter1-'0') : 0;
		n = (iter2 != b.rend()) ? (*iter2-'0') : 0;
		value = (jin + m + n) % 2;
		jin = (jin + m + n) / 2;
		result.push_back(value + '0');
		++iter1;
		++iter2;
	}
	if (jin == 1)
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}
int main(void)
{
	string s1 = "1";
	string s2 = "11";
	string result = addBinary(s1, s2);
	cout << result << endl;
	system("pause");
	return 0;
}




