#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
��ʦ��������Ƿַ��ǹ����� N ������վ����һ��ֱ�ߣ���ʦ�����ÿ�����ӵı��֣�Ԥ�ȸ��������֡�

����Ҫ��������Ҫ�󣬰�����ʦ����Щ���ӷַ��ǹ���

ÿ���������ٷ��䵽 1 ���ǹ���
���ڵĺ����У����ָߵĺ��ӱ����ø�����ǹ���
��ô������������ʦ������Ҫ׼�����ٿ��ǹ��أ�

ʾ�� 1:
����: [1,0,2]
���: 5
����: ����Էֱ�����������ӷַ� 2��1��2 ���ǹ���
*/
// ʱ�临�Ӷ� O(n)�ռ临�Ӷ� O(n)
int candy(vector<int>& ratings)
{
	int n = ratings.size();
	vector<int> v(n);
	//��������ɨ�裬�����һ������ǰһ������һ����ǰһ����1
	for (int i = 1, increnmt = 1; i < n; ++i)
	{
		if (ratings[i] > ratings[i - 1])
			v[i] = max(increnmt++, v[i]);
		else
			increnmt = 1;
	}
	//��������ɨ�裬���ǰһ�����ں�һ����ǰһ���Ⱥ�һ����1�����֮ǰ��v[i]�ϴ�
	//�Ǿ�ѡ��ϴ�ģ���Ϊ��ǰ����ʹӺ���ǰ��Ҫ����
	for (int i = n - 2, increnmt = 1; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			v[i] = max(increnmt++, v[i]);
		else
			increnmt = 1;
	}
	//��ʼֵΪn,��Ϊÿ��С��������һ����
	int result = n;
	for (int i = 0; i < n; ++i)
		result += v[i];
	return result;
}
int main(void)
{
	vector<int> v = { 1,0,2 };
	int result = candy(v);
	cout << result << endl;
	system("pause");
	return 0;
}