#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
/*
罗马数字转整数
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
*/
int romanToInt(string s)
{
	int result = 0;
	unordered_map<char, int> map = { {'I',1},{'V',5},{'X',10}
		,{'L',50},{'C',100},{'D',500},{'M',1000} };
	for (int i = 0; i < s.size(); ++i)
	{
		if (1 + i < s.size() && map[s[i]] < map[s[i + 1]])
		{
			result += map[s[i + 1]] - map[s[i]];
			i++;
		}
		else
			result += map[s[i]];
	}
	return result;
}
int main(void)
{
	string s = "IV";
	cout << romanToInt(s) << endl;
	system("pause");
	return 0;
}