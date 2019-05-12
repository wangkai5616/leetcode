#include<iostream>
#include<string>
using namespace std;
/*
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��
*/
string addBinary(string a, string b)
{
	string result;
	int length= a.size() > b.size() ? a.size() : b.size();
	auto iter1 = a.rbegin();
	auto iter2 = b.rbegin();
	int carry = 0;//��λ
	for (int i = 0; i < length; ++i)
	{
		int m = iter1 != a.rend() ? *iter1++ - '0' : 0;
		int n = iter2 != b.rend() ? *iter2++ - '0' : 0;
		int val = (m + n + carry) % 2;
		carry = (m + n + carry) / 2;
		result.insert(result.begin(), val + '0');
	}
	if (carry == 1)
		result.insert(result.begin(), '1');
	return result;
}
int main(void)
{
	string s1 = "10101";
	string s2 = "111";
	cout << addBinary(s1, s2) << endl;
	system("pause");
	return 0;
}
