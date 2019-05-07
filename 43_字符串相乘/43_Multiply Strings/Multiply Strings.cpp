#include<iostream>
#include<vector>
#include<string>
#include<iterator>//������back_inserter�Ķ���
#include<algorithm>
/*
�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻���
���ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��

˵����
num1 �� num2 �ĳ���С��110��
num1 �� num2 ֻ�������� 0-9��
num1 �� num2 �������㿪ͷ������������ 0 ����
����ʹ���κα�׼��Ĵ������ͣ����� BigInteger����ֱ�ӽ�����ת��Ϊ����������
*/
using namespace std;
vector<int> make_bigint(const string & str);
string to_string(const vector<int> &v);
vector<int> chen(vector<int> v1, vector<int> v2);
string multiply(string num1, string num2)
{
	return to_string(chen(make_bigint(num1),make_bigint(num2)));
}
vector<int> make_bigint(const string & str)
{
	vector<int> v;
	/*
	transform()�ĵ�һ���汾���Էº���op������[first,last)�е�ÿһ��Ԫ�����ϣ�������
	���������һ���µ�����
	*/
	transform(str.rbegin(), str.rend(), back_inserter(v),
		[](char c) {return c - '0'; });
	return v;
}
string to_string(const vector<int> &v)
{
	string str;
	//prev��ָ��������ǰһ��ָ��λ��
	transform(find_if(v.rbegin(), prev(v.rend()), [](int c) {return c > 0; }),v.rend(),
		back_inserter(str), [](int c) {return c + '0'; });
	return str;
}
vector<int> chen(vector<int> v1, vector<int> v2)
{
	vector<int> v(v1.size() + v2.size());
	for (int i = 0; i < v1.size(); ++i)
		for (int j = 0; j < v2.size(); ++j)
		{
			v[i + j] += v1[i] * v2[j];
			v[i + j + 1] += v[i + j] / 10;
			v[i + j] %= 10;
		}
	return v;
}
int main()
{
	string s1 = "10";
	string s2 = "10";
	string result = multiply(s1, s2);
	cout << result << endl;
	system("pause");
	return 0;
}