#include<iostream>
#include<vector>
using namespace std;
/*
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��
*/
vector<int> plusOne(vector<int>& digits)
{
	int c = 1;//ÿһ�εĽ�λ
	for (auto it = digits.rbegin(); it != digits.rend(); ++it)
	{
		*it += c;
		c = *it / 10;
		*it %= 10;
	}
	if (c > 0)
		digits.insert(digits.begin(), 1);
	return digits;
}
int main(void)
{
	
	vector<int> v = { 9,9,9 };
	v = plusOne(v);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}