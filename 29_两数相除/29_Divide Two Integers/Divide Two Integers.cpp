#include<iostream>
using namespace std;
/*
�������������������� dividend �ͳ��� divisor�������������Ҫ��ʹ�ó˷��������� mod �������
���ر����� dividend ���Գ��� divisor �õ����̡�
*/
/*
˼·�����ϼ�ȥ������������������ϣ�������һ���Ż���ÿ�ΰѱ�������������
�����١�������󣬾����·��شӳ�ʼ�ı��������¿�ʼ��
ʱ�临�Ӷ� O(logn)���ռ临�Ӷ� O(1)
*/
int divide(int dividend, int divisor)
{
	// �� dividend = INT_MIN ʱ��-dividend ������������� long long
	//Ҳ����˵-INT_MIN/-1,תΪ����֮��ͻ����
	long long a = dividend >= 0 ? dividend : -(long long)dividend;
	long long b = divisor >= 0 ? divisor : -(long long)divisor;
	// �� dividend = INT_MIN ʱ��divisor = -1 ʱ������������������ long long
	long long result = 0;
	while (a >= b) 
	{
		long long c = b;
		for (int i = 0; a >= c; ++i, c <<= 1) {
			a -= c;
			result += 1 << i;
		}
	}
	result = ((dividend^divisor) >> 31) ? (-result) : (result);
	//���-2147483648,-1��������������д���
	return result > INT_MAX ? INT_MAX : (int)result;
}
int main(void)
{
	int result = divide(16, 3);
	cout << result << endl;
	system("pause");
	return 0;
}