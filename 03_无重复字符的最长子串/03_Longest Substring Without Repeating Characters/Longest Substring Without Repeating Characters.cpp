#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
�ַ���ֻ����a��b...������#$%^���ָ�����
*/
int lengthOfLongestSubstring(string s)
{
	int curLength = 0;
	int maxLength = 0;
	map<char, int> m;//�ַ������Ӧ���±깹��map
	for (int i = 0; i < s.length(); ++i)
	{
		/*
		��ǰû�г��ֹ��ַ�s[i]������ǰ�Ѿ����ֹ����Ǹ��ַ�
		���ڵ�ǰ��curLength��Χ�У���ôCurLength����++
		*/
		if (m.find(s[i]) == m.end() || i-m.find(s[i])->second>curLength)
		{
			++curLength;
		}
		else
		{
			if (curLength > maxLength)
				maxLength = curLength;
			//����curLength
			curLength = i - m.find(s[i])->second;
		}
		//��map�н��м�¼
		m[s[i]] = i;
	}
	if (curLength > maxLength)
		maxLength = curLength;
	return maxLength;
}
int main(void)
{
	string s = "abc&*abrh";
	int result = lengthOfLongestSubstring(s);
	cout << result << endl;
	system("pause");
	return 0;
}