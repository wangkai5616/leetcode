#include<iostream>
using namespace std;
/*
����һ���ַ��� (s) ��һ���ַ�ģʽ (p)��ʵ��֧�� '.' �� '*' ��������ʽƥ�䡣

'.' ƥ�����ⵥ���ַ���
'*' ƥ���������ǰ���Ԫ�ء�
ƥ��Ӧ�ø��������ַ��� (s) �������ǲ����ַ�����
*/
bool matchCore(char *str, char *pattern);
bool match(char *string, char *pattern)
{
	if (string == nullptr || pattern == nullptr)
		return false;
	return matchCore(string, pattern);
}
bool matchCore(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		{
			return matchCore(str + 1, pattern + 2)//��Ӧ�����*ǰ����ַ�ֻ������һ��
				|| matchCore(str + 1, pattern)//��Ӧ�����*ǰ����ַ������˶�λ��� *ǰ�������.
											  /*
											  �������Ҳ����if�з���
											  char str1[] = "abc";
											  char str2[] = "a*abc";
											  */
				|| matchCore(str, pattern + 2);
		}
		else
		{
			return matchCore(str, pattern + 2);
		}
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);
	return false;
}
int main(void)
{
	char str1[] = "abc";
	char str2[] = "a*abc";
	bool result = match(str1, str2);
	if (result)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	system("pause");
	return 0;
}
