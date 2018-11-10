#include<iostream>
#include<vector>
using namespace std;
#define INTMAX 2147483647
#define INTMIN (-2147483647 - 1)//直接写成-2147483648会报错
int reverse(int x) {
	int result = 0;
	while (x != 0)
	{
		int temp = x % 10;
		x /= 10;
		if (result > INTMAX / 10 || (result == INTMAX / 10 && temp > 7))
			return 0;
 		if (result < INTMIN / 10 || (result == INTMIN / 10 && temp < -8))
			return 0;
		result = result * 10 + temp;
	}
	return result;
}
int main(void)
{
	int result = reverse(234);
	cout << result << endl;
	system("pause");
	return 0;
}