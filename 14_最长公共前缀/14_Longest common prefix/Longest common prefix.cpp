#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��
*/
string longestCommonPrefix(vector<string>& strs)
{
	string result = "";
	if (strs.empty())
		return result;
	string s1 = strs[0];
	for (int i = 0; i < s1.size();++i)
	{
		for (int j = 1; j < strs.size(); ++j)
		{
			if (s1[i] != strs[j][i])
				return result;			
		}
		result += s1[i];
	}
	return result;
}
int main(void)
{
	string s1 = "abcdd";
	string s2 = "ab";
	string s3 = "abbn";
	vector<string> v = { s1,s2,s3 };
	string s = longestCommonPrefix(v);
	cout << s << endl;

	//���������˴�������������'0\'
	string test = "abc";
	if (test[3] == '\0')
		cout << "�Կս�β" << endl;
	system("pause");
	return 0;
}