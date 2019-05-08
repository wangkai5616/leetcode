#include<iostream>
#include<string>
using namespace std;
/*
�ݹ鷽���ᳬʱ
*/
bool isMatchCore(string s, int i, string p, int j);
bool isMatch2(string s, string p)
{
	int i = 0, j = 0;
	return isMatchCore(s, i, p, j);
}
bool isMatchCore(string s, int i, string p, int j)
{
	if (i == s.size() && j == p.size())
		return true;
	if (i < s.size() && j == p.size())
		return false;
	if (p[j] == '*' && i<=s.size())
		return isMatchCore(s, i + 1, p, j) || //*ƥ�����ַ�
		isMatchCore(s, i, p, j + 1) || //��Ӧ�����*ƥ���
		isMatchCore(s, i + 1, p, j + 1); //*ƥ��һ���ַ�
	if (i<s.size() &&(s[i] == p[j] || (p[j] == '?')))
		return isMatchCore(s, i + 1, p, j + 1);
	return false;
}


bool isMatch(string s, string p) {
	if (s == p)
		return true;
	//jstar������p��'*'��λ��, istar��¼s��'*'����ƥ����ַ�������λ��
	int i = 0, j = 0, iStar = -1, jStar = -1;
	while (i < s.size())
	{
		if (s[i] == p[j] || p[j] == '?')
		{//�ﵽ������һ���ַ�������
			++i; ++j;
		}
		else if (p[j] == '*')
		{//��ǰ�ַ���Ϊ'*'����¼������ǰλ��
			iStar = i;
			jStar = j++;
		}
		else if (jStar >= 0)
		{//�������ַ��޷�ƥ��ʱ�����������'*'����ô��'*'�ŵ���������p��'*'λ�ò���
			i = ++iStar;
			j = jStar + 1;
		}
		//������ƥ������������û�г���'*'
		else
			return false;
	}
	//�������ַ��������е�'*'
	while (j < p.size() && p[j] == '*')
		++j;
	//���е��ַ����õ���ƥ��
	return j == p.size();
}

int main(void)
{
	string s = "adceb";
	string p = "*a*b";
	bool b = isMatch2(s, p);
	if (b)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	system("pause");
	return 0;
}