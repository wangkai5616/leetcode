#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> restoreIpAddresses(string s)
{
	vector<string> result;
	string ip;//����м���
	dfs(s, 0, 0, ip, result);
	return result;
}
/*
s��ԭʼ���ݣ�start��ָ��s�����￪ʼ��step��ָip��ַ����4����
���
*/
void dfs(string s, int start, int step, string ip, vector<string> &result)
{
	if (start == s.size() && step == 4)
	{
		ip.resize(ip.size() - 1);
		result.push_back(ip);
		return;
	}
	//ʣ�µ�̫����
	if (s.size() - start > (4 - step) * 3)
		return;
	//ʣ�µ�̫����
	if (s.size() - start < (4 - step))
		return;
	int num = 0;
	for (int i = start; i < start + 3; ++i)
	{
		num = num * 10 + (s[i] - '0');
		if (num <= 255)
		{
			ip += s[i];
			dfs(s, i + 1, step + 1, ip + '.', result);
		}
		//���磺010010,������0.10.0.10����������01.0.0.10
		if (num == 0)
			break;
	}
}
int main(void)
{
	system("pause");
	return 0;
}