#include<iostream>
using namespace std;
/*
ʵ�� int sqrt(int x) ������
���㲢���� x ��ƽ���������� x �ǷǸ�������
���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��
*/
//���ö��ֲ��ҽ������
int mySqrt(int x)
{
	if (x <= 1)
		return x;
	int start = 1;
	int end = x / 2;
	while (start <= end)
	{
		//long long�����б�Ҫ�ģ���Ϊ���ǴӶ���֮һ����ʼƽ�������ܳ������ֵ
		long long mid = (start + end) / 2;
		long long sq = mid*mid;
		if (sq == x)
			return mid;
		else if (sq > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return end;
}
int main(void)
{
	int result = mySqrt(4);
	cout << result << endl;
	system("pause");
	return 0;
}