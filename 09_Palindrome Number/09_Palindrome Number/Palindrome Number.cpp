#include<iostream>
using namespace std;
bool IsPalindrome1(int x)
{
	//�������ǽṹ���������һ������β�������0����ôҲ�϶����ǻ��Ľṹ
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;
	int xx = x;
	int temp;
	int result = 0;
	while (xx != 0)
	{
		temp = xx % 10;
		xx = xx / 10;
		result = result * 10 + temp;
	}
	if(result==x)
		return true;
	return false;
}
int main(void)
{
	bool result = IsPalindrome1(11321);
	if (result)
		cout << "is" << endl;
	else
		cout << "no" << endl;
	system("pause");
	return 0;
}