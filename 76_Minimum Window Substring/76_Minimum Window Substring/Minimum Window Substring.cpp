#include<iostream>
#include<string>
using namespace std;
//ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
string minWindow(string s, string t)
{
	if (s.empty() || t.empty() || s.size() < t.size())
		return "";
	//���ڱ���s�г����ַ���t�е�ĳ���ַ�������
	int *appeared = new int[256]();
	//���ڱ����ַ���t�г��ֵ�ĳ���ַ�������
	int *expected = new int[256]();
	//���Ӵ�����ͳ��
	for (size_t i = 0; i < t.size(); ++i)
		expected[t[i]]++;
	int minWidth = INT_MAX;//���洰�ڴ�С
	int minStart = 0;//���ڵ����λ��
	int num = 0;//��¼�ַ���s�г����ַ���t�е��ַ�������
	int winStart = 0;//ͷָ��
	//βָ�벻������ɨ
	for (size_t winEnd = 0; winEnd < s.size(); ++winEnd)
	{
		//�Ӵ�t���е�ǰ������ַ�
		if (expected[s[winEnd]]>0)
		{
			appeared[s[winEnd]]++;
			if (appeared[s[winEnd]] <= expected[s[winEnd]])
				num++;
		}
		//˵������һ���������Ӵ�t��
		if (num == t.size())
		{
			//����ͷָ��
			while (appeared[s[winStart]]>expected[s[winStart]]
				|| expected[s[winStart]] == 0)
			{
				appeared[s[winStart]]--;
				winStart++;
			}
			if (minWidth > (winEnd - winStart + 1))
			{
				minWidth = winEnd - winStart + 1;
				minStart = winStart;
			}
		}
	}
	if (minWidth == INT_MAX)
		return "";
	else
		return s.substr(minStart, minWidth);
}
int main(void)
{
	string S = "ABC";
	string T = "ABC";
	string result = minWindow(S, T);
	cout << result << endl;
	system("pause");
	return 0;
}