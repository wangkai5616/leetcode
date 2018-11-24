#include<iostream>
using namespace std;
bool IsPalindrome1(int x)
{
	//负数不是结构，而且如果一个数的尾数如果是0，那么也肯定不是回文结构
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