#include<iostream>
#include<vector>
using namespace std;
/*
���ױ�����һ������������ϵͳ���ڸ�ϵͳ�У�������������ֵ����һ��λ���Ĳ��졣
����һ�����������λ���ķǸ����� n����ӡ����ױ������С����ױ������б����� 0 ��ͷ��
ʾ�� 1:

����: 2
���: [0,1,3,2]
����:
00 - 0
01 - 1
11 - 3
10 - 2
*/
//ûʲô�ã�ֻ�Ǹ������grayCode����
void print(const vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}
/*
����ֻ��1��bitʱ���������ʱ��0,1��
���������0,1������2bitʱ��ʵ����00��01,
����������ϣ���10����һ�ε����������л�Ȼ�����result
Ȼ���ظ�����Ĳ���
*/
vector<int> grayCode(int n)
{
	vector<int> result;
	result.push_back(0);//��һ��Ԫ�ر�Ϊ0
	for (int i = 0; i < n; ++i)
	{
		const int highest_bit = 1 << i;
		for (int j = result.size() - 1; j >= 0; --j)//Ҫ���ű������ܶԳ�
			result.push_back(highest_bit | result[j]);
		print(result);
	}
	return result;
}

int main(void)
{
	vector<int> result = grayCode(3);
	system("pause");
	return 0;
}