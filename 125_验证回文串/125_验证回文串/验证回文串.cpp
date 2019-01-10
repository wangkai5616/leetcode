#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
给定一个字符串，验证它是否是回文串，只考虑
字母和数字字符，可以忽略字母的大小写。
*/
// 时间复杂度 O(n)，空间复杂度 O(1)
bool isPalindrome(string s) 
{
	//transform(b1,e1,b2,op)把一个区间[b1,e1)内的数据经过(op)转化,放入第二个容器内
	transform(s.begin(), s.end(), s.begin(), tolower);
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		//判断字符变量s[i]是否为字母或数字
		if (!isalnum(s[i]))
			++i;
		else if (!isalnum(s[j]))
			--j;
		else if (s[i++] != s[j--])
			return false;
	}
	return true;
}
int main(void)
{
	string s = "A man, a plan, a canal: Panama";
	bool b = isPalindrome(s);
	if (b) 
		cout << "aaa" << endl;
	else  
		cout << "bbb" << endl;
	system("pause");
	return 0;
}