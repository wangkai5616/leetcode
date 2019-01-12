#include<iostream>
#include<vector>
using namespace std;
/*
��һ����·���� N ������վ�����е� i ������վ������ gas[i] ����
����һ�������������޵ĵ��������ӵ� i ������վ������ i+1 ������վ��Ҫ�������� 
cost[i] ����������е�һ������վ��������ʼʱ����Ϊ�ա�
���������ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� -1��
˵��:
�����Ŀ�н⣬�ô𰸼�ΪΨһ�𰸡�
���������Ϊ�ǿ����飬�ҳ�����ͬ��
���������е�Ԫ�ؾ�Ϊ�Ǹ�����
*/
/*
��������������sum �жϵ�ǰ��ָ�����Ч�ԣ�total ���ж����������Ƿ���
�⣬�оͷ���ͨ�� sum �õ����±꣬û���򷵻� -1��
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	int total = 0;
	int j = -1;
	for (int i = 0, sum = 0; i < gas.size(); ++i)
	{
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (sum < 0)
		{
			j = i;
			sum = 0;
		}
	}
	return total >= 0 ? j + 1 : -1;
}
int main(void)
{
	vector<int> gas = { 2,3,4 };
	vector<int> cost = { 3,4,3 };
	int result = canCompleteCircuit(gas, cost);
	cout << result << endl;
	system("pause");
	return 0;
}