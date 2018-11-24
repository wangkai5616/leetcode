#include<iostream>
#include<string>
#include<iterator>
using namespace std;
/*
����һ����������Сд��ĸ�Ϳո� ' ' ���ַ��������������һ�����ʵĳ��ȡ�
������������һ�����ʣ��뷵�� 0 ��
*/
int lengthOfLastWord(string s)
{
	if (s.empty())
		return 0;
	int length = 0;
	auto iter = s.rbegin();
	while (*iter == ' ')
		iter++;
	for (; iter != s.rend(); ++iter)
	{
		if (*iter == ' ')
			return length;
		else
			length++;
	}
	return length;
}
//������,��ʹ������
int lengthOfLastWord2(const char *s)
{
	int length = 0;
	while (*s)
	{
		if (*s++ != ' ')
			++length;
		else if (*s && *s != ' ')
			length = 0;
	}
	return length;
}
int main(void)
{
	string s = "hello world dsa ";
	int length = lengthOfLastWord(s);
	cout << length << endl;
	system("pause");
	return 0;
}