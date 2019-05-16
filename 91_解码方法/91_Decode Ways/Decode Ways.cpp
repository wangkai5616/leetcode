#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
һ��������ĸ A-Z ����Ϣͨ�����·�ʽ�����˱���   
*/
/*
˼·���������������ַ���Ϊ"s[1]s[2]����s[len]"����������a[i-1]
��ʾǰi-1���ַ��Ľ��뷽��������ô���a[i]��Ϊ��������һ������i��
�ַ�s[i]!='0'����ô��i���ַ����Ե�������Ϊһ����ĸ��ǰi-1����ĸ��
���ֶ���û��Ӱ�죬��a[i] = a[i-1]���ڶ�������i-1���ַ��͵�i���ַ�
������ϳɴ��ڵ��ڡ�10��������С�ڵ��ڡ�26����˫�ַ�����ô��������
ĸ���һ�£�������Ϊǰi-2���ַ��ķ���������a[i] = a[i] + a[i-2]��
*/
int numDecodings(string s)
{
	int length = s.length();
	if (length == 0 || s[0] == '0')
		return 0;
	vector<int> v(length + 1, 0);
	v[0] = 1;
	for (int i = 1; i < length; ++i)
	{
		if (s[i] != '0')
			v[i] = v[i - 1];
		if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')
		{
			if (i == 1)
				v[i] += 1;
			else
				v[i] += v[i - 2];
		}
	}
	return v[length - 1];
}
int main(void)
{
	string s = "226";
	int result = numDecodings(s);
	cout << result << endl;
	system("pause");
	return 0;
}