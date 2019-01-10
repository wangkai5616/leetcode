#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ����
��ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
*/
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(1)
bool isPalindrome(string s) 
{
	//transform(b1,e1,b2,op)��һ������[b1,e1)�ڵ����ݾ���(op)ת��,����ڶ���������
	transform(s.begin(), s.end(), s.begin(), tolower);
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		//�ж��ַ�����s[i]�Ƿ�Ϊ��ĸ������
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